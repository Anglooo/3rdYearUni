lex: lex.o lex.yy.o
	gcc -o lex lex.o lex.yy.o
	
lex.o: tokens.h
	gcc -c lex.c
	
lex.yy.o: tokens.h lex.yy.c
	gcc -c lex.yy.c

lex.yy.c: tokens.h simp.lex
	flex simp.lex
	
clean:
	rm -rf *.o simp.c lex.yy.c lex
