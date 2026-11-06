const vscode = require('vscode');
const path = require('path');
const fs = require('fs');
const { execFile } = require('child_process');

let diagnosticCollection;
let outputChannel;

/**
 * Resolve the path to the opex executable.
 * Looks in user settings, workspace folder, and parent folders.
 */
function getCompilerPath(workspaceRoot) {
    const config = vscode.workspace.getConfiguration('opex');
    const configuredPath = config.get('compilerPath');
    if (configuredPath && fs.existsSync(configuredPath)) {
        return configuredPath;
    }

    if (workspaceRoot) {
        const localBinary = path.join(workspaceRoot, 'opex');
        if (fs.existsSync(localBinary)) {
            return localBinary;
        }
    }

    return 'opex';
}

/**
 * Get the active OPEX text document, saving it if dirty.
 */
async function getActiveOpexDocument() {
    const editor = vscode.window.activeTextEditor;
    if (!editor) {
        vscode.window.showErrorMessage('OPEX: No active editor found.');
        return null;
    }

    const doc = editor.document;
    if (doc.languageId !== 'opex' && !doc.fileName.endsWith('.opx')) {
        vscode.window.showWarningMessage('OPEX: Active file is not an OPEX (.opx) source file.');
        return null;
    }

    if (doc.isDirty) {
        await doc.save();
    }

    return doc;
}

/**
 * Get workspace root for the given file or fallback.
 */
function getWorkspaceRoot(doc) {
    const folder = vscode.workspace.getWorkspaceFolder(doc.uri);
    return folder ? folder.uri.fsPath : path.dirname(doc.fileName);
}

/**
 * Parse compiler error output into VS Code diagnostics.
 */
function parseDiagnostics(output, doc) {
    const diagnostics = [];
    const lines = output.split('\n');

    const syntaxRegex = /Syntax Error at line (\d+), col (\d+):\s*(.+)/i;
    const semanticRegex = /Semantic Error:\s*(.+)/i;

    for (const line of lines) {
        const trimmed = line.trim();
        if (!trimmed) continue;

        const syntaxMatch = trimmed.match(syntaxRegex);
        if (syntaxMatch) {
            const lineNum = Math.max(0, parseInt(syntaxMatch[1], 10) - 1);
            const colNum = Math.max(0, parseInt(syntaxMatch[2], 10) - 1);
            const message = syntaxMatch[3];

            // Highlight from column to end of token/line
            const range = new vscode.Range(lineNum, colNum, lineNum, colNum + 10);
            diagnostics.push(new vscode.Diagnostic(range, message, vscode.DiagnosticSeverity.Error));
            continue;
        }

        const semanticMatch = trimmed.match(semanticRegex);
        if (semanticMatch) {
            const message = semanticMatch[1];
            // Position at start of document if line number not specified
            const range = new vscode.Range(0, 0, 0, 1);
            diagnostics.push(new vscode.Diagnostic(range, `Semantic Error: ${message}`, vscode.DiagnosticSeverity.Error));
        }
    }

    return diagnostics;
}

/**
 * Run semantic and syntax check on an OPEX document.
 */
function runCheck(doc, showNotification = true) {
    const workspaceRoot = getWorkspaceRoot(doc);
    const compiler = getCompilerPath(workspaceRoot);

    execFile(compiler, ['--check', doc.fileName], { cwd: workspaceRoot }, (error, stdout, stderr) => {
        const fullOutput = (stdout || '') + '\n' + (stderr || '');
        const diagnostics = parseDiagnostics(fullOutput, doc);

        diagnosticCollection.set(doc.uri, diagnostics);

        if (showNotification) {
            if (diagnostics.length === 0 && !error) {
                vscode.window.showInformationMessage('OPEX: Semantic check passed cleanly. Zero errors found.');
            } else {
                vscode.window.showErrorMessage(`OPEX: Semantic verification failed with ${diagnostics.length || 1} error(s). Check Problems panel.`);
            }
        }
    });
}

function activate(context) {
    diagnosticCollection = vscode.languages.createDiagnosticCollection('opex');
    outputChannel = vscode.window.createOutputChannel('OPEX Compiler');
    context.subscriptions.push(diagnosticCollection, outputChannel);

    // Command: Run Active File
    const runCmd = vscode.commands.registerCommand('opex.run', async () => {
        const doc = await getActiveOpexDocument();
        if (!doc) return;

        const workspaceRoot = getWorkspaceRoot(doc);
        const compiler = getCompilerPath(workspaceRoot);

        // Check if compiler binary exists or can be built
        if (compiler !== 'opex' && !fs.existsSync(compiler)) {
            const makefile = path.join(workspaceRoot, 'Makefile');
            if (fs.existsSync(makefile)) {
                vscode.window.showInformationMessage('OPEX: Building compiler binary with make...');
            }
        }

        let terminal = vscode.window.terminals.find(t => t.name === 'OPEX Runner');
        if (!terminal) {
            terminal = vscode.window.createTerminal({
                name: 'OPEX Runner',
                cwd: workspaceRoot
            });
        }

        terminal.show();

        const relPath = path.relative(workspaceRoot, doc.fileName);
        const runCmdStr = compiler === 'opex'
            ? `opex --run "${relPath}"`
            : `"${compiler}" --run "${relPath}"`;

        terminal.sendText(runCmdStr);
    });

    // Command: Compile to Standalone Native Binary
    const compileCmd = vscode.commands.registerCommand('opex.compile', async () => {
        const doc = await getActiveOpexDocument();
        if (!doc) return;

        const workspaceRoot = getWorkspaceRoot(doc);
        const compiler = getCompilerPath(workspaceRoot);
        const parsed = path.parse(doc.fileName);
        const defaultOutName = parsed.name;

        const outName = await vscode.window.showInputBox({
            prompt: 'Enter binary output name',
            value: defaultOutName
        });

        if (!outName) return;

        const outPath = path.isAbsolute(outName) ? outName : path.join(path.dirname(doc.fileName), outName);

        outputChannel.clear();
        outputChannel.appendLine(`[OPEX] Compiling ${path.basename(doc.fileName)} -> ${path.basename(outPath)}...`);
        outputChannel.show(true);

        execFile(compiler, ['-o', outPath, doc.fileName], { cwd: workspaceRoot }, (error, stdout, stderr) => {
            if (stdout) outputChannel.append(stdout);
            if (stderr) outputChannel.append(stderr);

            if (error) {
                vscode.window.showErrorMessage(`OPEX: Compilation failed. See Output channel.`);
            } else {
                vscode.window.showInformationMessage(
                    `OPEX: Successfully compiled to ${path.basename(outPath)}!`,
                    'Run Binary'
                ).then(selection => {
                    if (selection === 'Run Binary') {
                        let terminal = vscode.window.terminals.find(t => t.name === 'OPEX Runner');
                        if (!terminal) {
                            terminal = vscode.window.createTerminal({ name: 'OPEX Runner', cwd: workspaceRoot });
                        }
                        terminal.show();
                        terminal.sendText(`"${outPath}"`);
                    }
                });
            }
        });
    });

    // Command: Semantic Check
    const checkCmd = vscode.commands.registerCommand('opex.check', async () => {
        const doc = await getActiveOpexDocument();
        if (!doc) return;
        runCheck(doc, true);
    });

    // Command: Show 3AC Quadruples Intermediate Representation
    const showIRCmd = vscode.commands.registerCommand('opex.showIR', async () => {
        const doc = await getActiveOpexDocument();
        if (!doc) return;

        const workspaceRoot = getWorkspaceRoot(doc);
        const compiler = getCompilerPath(workspaceRoot);

        outputChannel.clear();
        outputChannel.appendLine(`============================================================`);
        outputChannel.appendLine(`      OPEX THREE-ADDRESS CODE (3AC): ${path.basename(doc.fileName)}`);
        outputChannel.appendLine(`============================================================\n`);
        outputChannel.show(true);

        execFile(compiler, [doc.fileName], { cwd: workspaceRoot }, (error, stdout, stderr) => {
            if (stdout) outputChannel.append(stdout);
            if (stderr) outputChannel.append(stderr);
            if (error && !stdout) {
                vscode.window.showErrorMessage(`OPEX: Failed to generate 3AC IR. See Output channel.`);
            }
        });
    });

    // Auto-check on document save
    const saveListener = vscode.workspace.onDidSaveTextDocument(doc => {
        if (doc.languageId === 'opex' || doc.fileName.endsWith('.opx')) {
            runCheck(doc, false);
        }
    });

    // Clean up diagnostics when document is closed
    const closeListener = vscode.workspace.onDidCloseTextDocument(doc => {
        diagnosticCollection.delete(doc.uri);
    });

    context.subscriptions.push(runCmd, compileCmd, checkCmd, showIRCmd, saveListener, closeListener);
}

function deactivate() {
    if (diagnosticCollection) {
        diagnosticCollection.clear();
        diagnosticCollection.dispose();
    }
}

module.exports = {
    activate,
    deactivate
};
