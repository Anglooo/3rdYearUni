%{
#include <stdio.h>

void yyerror(const char *s) {
	printf("yyerror: %s",s);
	exit(-1);
}

extern FILE *   yyin;
%}

%token TBEGIN END


%start program

%%

program: 


%%

main(int argc,char ** argv)
{  
   if((yyin=fopen(argv[1],"r"))==NULL)
   {  printf("can't open %s\n",argv[1]);
      exit(0);
   }

   yyparse();
   fclose(yyin);

}

