CC = gcc
CFLAGS = -I src
FLEX = flex
BISON = bison

all: parser

parser: src/lex.yy.c src/parser.tab.c src/ast.c src/ir.c src/semantic.c src/codegen.c
	$(CC) $(CFLAGS) src/lex.yy.c src/parser.tab.c src/ast.c src/ir.c src/semantic.c src/codegen.c -o parser

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

clean:
	rm -f src/lex.yy.c src/parser.tab.c src/parser.tab.h src/parser.output parser out.c edges.ppm edges.png
