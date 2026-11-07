CC = gcc
CFLAGS = -I src
FLEX = flex
BISON = bison

.PHONY: all clean test test_derivations test_all test_semantic test_ir test_run docs docs-serve deploy install extension install-extension

all: parser opex

parser: src/lex.yy.c src/parser.tab.c src/ast.c src/ir.c src/semantic.c src/codegen.c
	$(CC) $(CFLAGS) src/lex.yy.c src/parser.tab.c src/ast.c src/ir.c src/semantic.c src/codegen.c -o parser

opex: parser
	cp -f parser opex

install: opex
	install -d /usr/local/bin
	install -m 755 opex /usr/local/bin/opex

src/lex.yy.c: src/lexer.l src/parser.tab.h
	$(FLEX) -o src/lex.yy.c src/lexer.l

src/parser.tab.c src/parser.tab.h: src/parser.y
	$(BISON) -d -v -o src/parser.tab.c src/parser.y

test: parser
	./parser < tests/sample.opx

test_derivations: parser
	@for f in tests/*.opx; do \
		echo "=== Testing Derivations for $$f ==="; \
		./parser --derivations < "$$f" || true; \
	done

test_all: parser
	@for f in tests/*.opx; do \
		echo -n "Parsing $$f... "; \
		./parser --parse-only < "$$f" 2>&1 || true; \
	done

test_semantic: parser
	@for f in tests/*.opx; do \
		echo -n "Checking $$f... "; \
		./parser --check < "$$f" 2>&1 || true; \
	done

test_ir: parser
	@mkdir -p ir_outputs
	@for f in tests/*.opx; do \
		echo "Generating IR for $$f..."; \
		echo "=== SOURCE CODE ===" > "ir_outputs/$$(basename "$$f" .opx).ir"; \
		cat "$$f" >> "ir_outputs/$$(basename "$$f" .opx).ir"; \
		echo "\n=== INTERMEDIATE CODE ===" >> "ir_outputs/$$(basename "$$f" .opx).ir"; \
		./parser < "$$f" >> "ir_outputs/$$(basename "$$f" .opx).ir" 2>&1 || true; \
	done

test_run: parser
	@echo "--- Running Bubble Sort (Pure OPEX) ---"
	./parser --run tests/bubble_sort.opx
	@echo "\n--- Running Matrix Multiplication (Pure OPEX) ---"
	./parser --run tests/matrix_mult.opx
	@echo "\n--- Running Stack Demo (Pure OPEX) ---"
	./parser --run tests/stack.opx
	@echo "\n--- Running Queue Demo (Pure OPEX) ---"
	./parser --run tests/queue.opx
	@echo "\n--- Running Edge Detection Pipeline (Pure OPEX) ---"
	./parser --run tests/edge_detection.opx

docs:
	@if [ -d ".venv" ]; then \
		.venv/bin/mkdocs build --strict; \
	elif command -v mkdocs >/dev/null 2>&1; then \
		mkdocs build --strict; \
	else \
		echo "mkdocs not found. Run: python3 -m venv .venv && .venv/bin/pip install mkdocs-material"; exit 1; \
	fi

docs-serve:
	@if [ -d ".venv" ]; then \
		.venv/bin/mkdocs serve; \
	elif command -v mkdocs >/dev/null 2>&1; then \
		mkdocs serve; \
	else \
		echo "mkdocs not found. Run: python3 -m venv .venv && .venv/bin/pip install mkdocs-material"; exit 1; \
	fi

deploy:
	@if [ -d ".venv" ]; then \
		.venv/bin/mkdocs gh-deploy --force; \
	elif command -v mkdocs >/dev/null 2>&1; then \
		mkdocs gh-deploy --force; \
	else \
		echo "mkdocs not found. Run: python3 -m venv .venv && .venv/bin/pip install mkdocs-material"; exit 1; \
	fi

extension:
	cd extension && npx --yes @vscode/vsce package --no-dependencies

install-extension:
	mkdir -p $(HOME)/.vscode/extensions/gaurav-budhwani.opex-language-1.0.0
	cp -rf extension/* $(HOME)/.vscode/extensions/gaurav-budhwani.opex-language-1.0.0/
	@if [ -d "$(HOME)/.antigravity/extensions" ]; then \
		mkdir -p $(HOME)/.antigravity/extensions/gaurav-budhwani.opex-language-1.0.0; \
		cp -rf extension/* $(HOME)/.antigravity/extensions/gaurav-budhwani.opex-language-1.0.0/; \
	fi
	@echo "OPEX extension installed successfully to IDE extensions directory!"

clean:
	rm -f src/lex.yy.c src/parser.tab.c src/parser.tab.h src/parser.output parser opex out.c edges.ppm edges.png
	rm -rf site
