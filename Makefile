CC = gcc
CFLAGS = -I src
FLEX = flex
BISON = bison

all: parser

parser: src/lex.yy.c src/parser.tab.c src/ast.c src/ir.c
	$(CC) $(CFLAGS) src/lex.yy.c src/parser.tab.c src/ast.c src/ir.c -o parser

src/lex.yy.c: src/lexer.l src/parser.tab.h
	$(FLEX) -o src/lex.yy.c src/lexer.l

src/parser.tab.c src/parser.tab.h: src/parser.y
	$(BISON) -d -o src/parser.tab.c src/parser.y

test: parser
	./parser < tests/sample.opx

test_all: parser
	@for f in tests/*.opx; do \
		echo -n "Testing $$f... "; \
		./parser < "$$f"; \
	done

test_ir: parser
	@mkdir -p ir_outputs
	@for f in tests/*.opx; do \
		echo "Generating IR for $$f..."; \
		./parser < "$$f" > "ir_outputs/$$(basename "$$f" .opx).ir" 2>&1 || true; \
	done

clean:
	rm -f src/lex.yy.c src/parser.tab.c src/parser.tab.h parser
	rm -rf ir_outputs
