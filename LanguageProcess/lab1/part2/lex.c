#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"

int symb;

extern int yylex(void);
extern FILE *   yyin;
extern char * yytext;

char * showSymb(int symb)
{  switch(symb)
   {  case  TBEGIN: return "BEGIN";
      case  DO: return "DO";
      case  ELSE: return "ELSE";
      case  END: return "END";
      case  ID: return "ID";
      case  IF: return "IF";
      case  INT: return "INT";
      case  INPUT: return "INPUT";
      case  PRINT: return "PRINT";
      case  THEN: return "THEN";
      case  VAR: return "VAR";
      case  WHILE: return "WHILE";
      case  PLUS: return "+";
      case  MINUS: return "-";
      case  STAR: return "*";
      case  SLASH: return "/";
      case  LBRA: return "(";
      case  RBRA: return ")";
      case  LT: return "<";
      case  LTE: return "<=";
      case  EQ: return "=";
      case  NEQ: return "!=";
      case  GTE: return ">=";
      case  GT: return ">";
      case  ASSIGN: return ":=";
      case SEMI: return ";";
      case EOF: return "EOF";
      default: printf("bad symbol: %d",symb);
   }
}

printSymb()
{  char * s;
   printf("%s ",showSymb(symb));
   if(symb==ID || symb==INT){
    if(yytext == NULL)
    	printf("Error: yytext is null");
    else
    	printf("%s\n",yytext);
   } else
    printf("\n");
}
   
main(int argc,char ** argv)
{  
   if((yyin=fopen(argv[1],"r"))==NULL)
   {  printf("can't open %s\n",argv[1]);
      exit(0);
   }

   symb = yylex();
   printSymb();
   // printf("num: %d\n",ch);
   
   // Q: why is not EOF returned?
   while(symb != EOF)
   {  
   	   symb = yylex();
   	   printSymb();
   }

   fclose(yyin);
}
