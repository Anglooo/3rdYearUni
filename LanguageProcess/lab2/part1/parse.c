#include <stdio.h>
#include <stdlib.h>

#include "tokens.h"

extern int ch;
extern int symb;
extern int value;
extern char * id;

extern lex(FILE *);
extern printSymb();
extern char * showSymb(int);

rule(char * name,int depth)
{  int i;
   for(i=0;i<depth;i++)
    printf(" ");
   printf("%s\n",name);
}

error(char * rule,char * message)
{  printf("%s: found %s\n",rule,showSymb(symb));
   printf("%s: %s\n",rule,message);
   exit(0);
}

Lex(FILE * fin)
{  printSymb();
   lex(fin);
}

program(FILE * fin,int depth)
{  rule("program",depth);
   if(symb==VAR)
    declarations(fin,depth+1);
   commands(fin,depth+1);
}

declarations(FILE * fin,int depth)
{  rule("declarations",depth);
   declaration(fin,depth+1);
   if(symb==SEMI)
   {  Lex(fin);
      if(symb==VAR)
       declarations(fin,depth+1);
   }
   else
    error("declarations","; expected");
}

declaration(FILE * fin,int depth)
{  rule("declaration",depth);
   if(symb!=VAR)
    error("declaration","VAR expected\n");
   Lex(fin);
   if(symb!=ID)
    error("declaration","identifier expected\n");
   Lex(fin);
}

commands(FILE * fin,int depth)
{  rule("commands",depth);
   command(fin,depth+1);
   if(symb==SEMI)
   {  Lex(fin);
      commands(fin,depth+1);
   }
}

command(FILE * fin,int depth)
{  rule("command",depth);
   switch(symb)
   {  case ID: assign(fin,depth+1);
               break;
      case IF: Lex(fin);
               ifComm(fin,depth+1);
               break;
      case WHILE: Lex(fin);
                  whileComm(fin,depth+1);
                  break;
      case BEGIN: Lex(fin);
                  block(fin,depth+1);
                  break;     
      case INPUT: Lex(fin);
                  input(fin,depth+1);
                  break;
      case PRINT: Lex(fin);
                  print(fin,depth+1);
                  break;
      case REPEAT: Lex(fin);
                   repeat(fin, depth+1);
                   break;

      default: error("command","BEGIN/IF/INPUT/PRINT/WHILE/identifier expected\n");
   }
}

assign(FILE * fin,int depth)
{  rule("assign",depth);
   Lex(fin);
   if(symb!=ASSIGN)
    error("assign",":= expected\n");
   Lex(fin);
   expr(fin,depth+1);
}

ifComm(FILE * fin,int depth)
{  rule("if",depth);
   condexp(fin,depth+1);
   if(symb!=THEN)
    error("if","THEN expected\n");
   Lex(fin);
   command(fin,depth+1);
   if(symb==ELSE)
   {  Lex(fin);
      command(fin,depth+1);
   }
}

whileComm(FILE * fin,int depth)
{  rule("while",depth);
   condexp(fin,depth+1);
   if(symb!=DO)
    error("while","DO expected\n");
   Lex(fin);
   command(fin,depth+1);
}

block(FILE * fin,int depth)
{  rule("block",depth);
   program(fin,depth+1);
   if(symb!=END)
    error("block","END expected\n");
   Lex(fin);
}

input(FILE * fin,int depth)
{  rule("input",depth);
   if(symb!=ID)
    error("input","identifier expected\n");
   Lex(fin);
}

print(FILE * fin,int depth)
{  rule("print",depth);
   expr(fin,depth+1);
}

repeat(FILE * fin, int depth)
{
  rule("repeat",depth);
  
}

condexp(FILE * fin,int depth)
{  rule("condexp",depth);
   expr(fin,depth+1);
   switch(symb)
   {  case LT:
      case LTE:
      case EQ:
      case NEQ:
      case GTE:
      case GT: Lex(fin);
               expr(fin,depth+1);
               return;
      default: error("condexp","comparison operator expected\n");
   }
}

expr(FILE * fin,int depth)
{  rule("exp",depth);
   term(fin,depth+1);
   if(symb==PLUS || symb==MINUS)
   {  Lex(fin);
      expr(fin,depth+1);
   }
}

term(FILE * fin,int depth)
{  rule("term",depth);
   factor(fin,depth+1);
   if(symb==STAR || symb==SLASH)
   {  Lex(fin);
      term(fin,depth+1);
   }
}

factor(FILE * fin,int depth)
{  rule("factor",depth);
   if(symb==MINUS)
    Lex(fin);
   base(fin,depth+1);
}

base(FILE * fin,int depth)
{  rule("base",depth);
   switch(symb)
   {  case ID: break;
      case INT: break;
      case LBRA: Lex(fin);
                 expr(fin,depth+1);
                 if(symb!=RBRA)
                  error("base","( expected\n");
                 break;
      default: error("base","(, identifier or integer expected\n");
   }
   Lex(fin);
}

main(int c,char ** argv)
{  FILE * fin;
   
   printf("loading file\n");
   if((fin=fopen(argv[1],"r"))==NULL)
   {  printf("can't open %s\n",argv[1]);
      exit(0);
   }
   ch = getc(fin);
   lex(fin);
   program(fin,1);
}
