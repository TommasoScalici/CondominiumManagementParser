flexbison:
	flex lexer.fl
	bison -d -v --graph parser.y
	gcc -g -o result lex.yy.c parser.tab.c symbol.tab.c