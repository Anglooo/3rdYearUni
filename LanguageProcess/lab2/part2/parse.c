#include <stdio.h>

extern void yyparse(void);
extern FILE *   yyin;


main(int argc,char ** argv)
{  
   if((yyin=fopen(argv[1],"r"))==NULL)
   {  printf("can't open %s\n",argv[1]);
      exit(0);
   }

   yyparse();
   fclose(yyin);

}
