# OPEX Language Support for Visual Studio Code & Antigravity IDE

Official language extension for the **OPEX** Domain-Specific Programming Language & Optimizing Native C99 Compiler.

<p align="center">
  <img src="icon.png" alt="OPEX Mascot" width="160" />
</p>

---

## Features

- **Full Syntax Highlighting**:
  - Highlights core keywords (`PROGRAM`, `BEGIN`, `END`, `AUTO`, `RETURN`), control flow (`FOR`, `WHILE`, `MATCH`, `CASE`), and native CV types (`IMAGE`, `MATRIX`, `KERNEL`, `PIXEL`).
  - Highlights custom operators: pipeline (`|>`), convolution (`**`), and assignment (`:=`).
  - Supports string interpolation (`"Value: {x}"`), single-line comments (`//`), and block comments (`/* ... */`).
- **One-Click Native Execution**:
  - Dedicated **▶ Run OPEX** button directly in the editor tab bar.
  - Shortcut keybinding: `Cmd+Alt+R` (macOS) / `Ctrl+Alt+R` (Linux / Windows).
  - Automatically opens an integrated terminal and executes `./opex --run <active_file>`.
- **Integrated Compilation**:
  - Compile any `.opx` source directly into a standalone, optimized C99 native binary (`./opex -o <bin> <file>`).
  - Integrated notification prompt to immediately execute the resulting binary.
- **Diagnostics & Inline Error Squiggles**:
  - Automatically runs semantic and syntax checks on file save (`./opex --check`).
  - Syntax errors pinpoint exact line and column locations with editor squiggles and listings in the **Problems** tab.
- **3-Address Code (3AC) Inspector**:
  - View compiler quadruples (`op`, `arg1`, `arg2`, `result`) in a dedicated output channel with a single command.
- **Extensive Code Snippets**:
  - `prog`: Program skeleton with initialization and main block.
  - `pipeline`: Full image loading, grayscale, blur, threshold, and save pipeline.
  - `kernel`: 3x3 convolution matrix initialization.
  - `conv`: Kernel convolution expression (`IMAGE edges := img ** kernel;`).
  - `func`: Typed function definition with return statement.
  - `struct`: Custom record structure definition.
  - `for`, `forstep`, `foreach`, `while`, `match`, `ifelse`: Control structures.

---

## Keyboard Shortcuts

| Command | macOS | Windows / Linux |
| :--- | :--- | :--- |
| **OPEX: Run Active File** | `Cmd + Option + R` | `Ctrl + Alt + R` |

---

## Available Commands

Access these from the Command Palette (`Cmd+Shift+P` / `Ctrl+Shift+P`):

- `OPEX: Run Active File` — Execute the current OPEX file immediately.
- `OPEX: Compile to Standalone Native Binary` — Compile to a standalone binary.
- `OPEX: Run Semantic Type-Check` — Validate types and scope declarations.
- `OPEX: Show 3-Address Code (3AC)` — View intermediate representation quadruples.

---

## Configuration Settings

You can customize the extension via your VS Code `settings.json`:

```json
{
  "opex.compilerPath": "/usr/local/bin/opex"
}
```

*By default, the extension automatically discovers the `./opex` compiler binary in your workspace root.*

---

## License

MIT © Gaurav Budhwani

