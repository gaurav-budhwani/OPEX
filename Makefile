CC = gcc
CFLAGS = -I src
FLEX = flex
BISON = bison

all: parser

parser: src/lex.yy.c src/parser.tab.c
	$(CC) $(CFLAGS) src/lex.yy.c src/parser.tab.c -o parser

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

clean:
	rm -f src/lex.yy.c src/parser.tab.c src/parser.tab.h parser
