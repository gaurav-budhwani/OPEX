all: lexer

lexer: src/lex.yy.c
	gcc src/lex.yy.c -o lexer -I src

src/lex.yy.c: src/lexer.l
	flex -o src/lex.yy.c src/lexer.l

test: lexer
	./lexer < tests/sample.axi

clean:
	rm -f src/lex.yy.c lexer

test_all: lexer
	for f in tests/*.axi; do \
		echo "Testing $$f..."; \
		./lexer < "$$f" > /dev/null && echo "Pass" || echo "Fail"; \
	done
