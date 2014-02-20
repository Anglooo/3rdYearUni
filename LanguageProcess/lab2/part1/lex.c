   #include <stdio.h>
#include <stdlib.h>
#include "tokens.h"

#define MAXIDENT 256

int ch;
int symb;
int value;
int lineNum=0;
char id[MAXIDENT];

char * showSymb(int symb)
{  switch(symb)
   {  case BEGIN: return "BEGIN";
      case DO: return "DO";
      case ELSE: return "ELSE";
      case END: return "END";
      case ID: return "ID";
      case IF: return "IF";
      case INT: return "INT";
      case INPUT: return "INPUT";
      case PRINT: return "PRINT";
      case THEN: return "THEN";
      case VAR: return "VAR";
      case WHILE: return "WHILE";
      case PLUS: return "+";
      case MINUS: return "-";
      case STAR: return "*";
      case SLASH: return "/";
      case LBRA: return "(";
      case RBRA: return ")";
      case LT: return "<";
      case LTE: return "<=";
      case EQ: return "=";
      case NEQ: return "!=";
      case GTE: return ">=";
      case GT: return ">";
      case ASSIGN: return ":=";
      case SEMI: return ";";
      case EOF: return "EOF";
      case REPEAT: return "REPEAT";
      case UNTIL: return "UNTIL";
      case USING: return "USING";
      case IN: return "IN";
      default: printf("bad symbol: %d",symb);
   }
}

printSymb()
{  char * s;
   printf("%s ",showSymb(symb));
   if(symb==ID)
    printf("%s\n",id);
   else
   if(symb==INT)
    printf("%d\n",value);
   else
   printf("\n");
}
   

getInteger(FILE * fin)
{  symb = INT;
   value=0;
   while(ch>='0' && ch<='9')
   {  value = 10*value+ch-'0';
      ch = getc(fin);
   }
}

getIdent(FILE * fin)
{ 
   int i;
   i = 0;
   while(((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || 
          (ch>='0' && ch<='9')) || (ch=='_') && i<MAXIDENT-1)
   {  id[i] = ch;
      ch = getc(fin);
      i++;
   }
   id[i] = '\0';
   if(i==MAXIDENT-1)
    while((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') ||
          (ch>='0' && ch<='9') || (ch=='_'))
     ch = getc(fin);
   if(strcmp(id,"BEGIN") == 0){
     symb = BEGIN;
     return;
   }   
   if(strcmp(id,"DO") == 0){
     symb = DO;
     return;
   } 
   if(strcmp(id,"ELSE") == 0){
     symb = ELSE;
     return;
   }    
   if(strcmp(id,"END") == 0){
     symb = END;
     return;
   }  
   if(strcmp(id,"IF") == 0){
     symb = END;
     return;
   }
   if(strcmp(id,"INPUT") == 0){
     symb = INPUT;
     return;
   }
   if(strcmp(id,"PRINT") == 0){
     symb = PRINT;
     return;
   }   
   if(strcmp(id,"THEN") == 0){
     symb = THEN;
     return;
   }   
   if(strcmp(id,"VAR") == 0){
     symb = VAR;
     return;
   }  
    if(strcmp(id,"WHILE") == 0){
     symb = WHILE;
     return;
   }
   if(strcmp(id, "REPEAT") == 0){
    symb = REPEAT;
    return;
   }
   if(strcmp(id, "UNTIL") == 0){
    symb = UNTIL;
    return;
   }  
   if(strcmp(id, "USING") == 0){
    symb = USING;
    return;
   }
   if (strcmp(id, "IN") == 0){
    symb = IN;
    return;
   }  
   symb = ID;
}
   

lex(FILE * fin)
{  while(ch==' ' || ch=='\n' || ch=='\t'){
   if(ch=='\n')
   {lineNum++;}
    ch = getc(fin);
  }
   switch(ch)
   {  case ';': symb = SEMI; break;
      case '+': symb = PLUS; break;
      case '-': symb = MINUS; break;
      case '*': symb = STAR; break;
      case '/': symb = SLASH; break;
      case '(': symb = LBRA; break;
      case ')': symb = RBRA; break;
      case '=': symb = EQ; break;
      case '!': ch = getc(fin);
                if(ch=='='){  symb = NEQ; break; }
                printf("lexical error on line:%d = expected after :\n", lineNum) ; exit(0);
      case ':': ch = getc(fin);
                if(ch=='='){  symb = ASSIGN; break;  }
                 printf("lexical error on line: %d = expected after :\n", lineNum); exit(0);
      case '<': ch = getc(fin);
                // if(ch=='-'){  symb = LARROW; break;  }
                if(ch=='='){  symb = LTE; break;  }
                symb = LT; return;
      case '>': ch = getc(fin);
                if(ch=='=')
                {  symb = GTE; break; }
                symb = GT; return;
      case EOF: symb = EOF; return;
      default: if(ch>='0' && ch<='9')
               {  getInteger(fin); return; }
               if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch=='_'))
               {  getIdent(fin); return;  }
                
               printf("lexical error: unknown character %c %x\n",ch,ch);
               exit(0);
   }
   ch = getc(fin);
}
   
