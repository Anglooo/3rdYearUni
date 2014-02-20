all:
	bison -d simp.y
	flex simp.lex
	gcc -c lex.yy.c
	gcc simp.tab.c
	gcc -o parse lex.yy.o simp.tab.o parse.o
	
clean:
	rm -rf *.o simp.c lex.yy.c simp.tab.c simp.tab.h parse *~ 
