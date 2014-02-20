%{
#include "tokens.h"
%}

DIGIT    [0-9]
CHAR     [a-zA-Z]
         
%%

";" 		{ return SEMI;}
"+" 		{ return PLUS;}
"-" 		{ return MINUS;}
"*" 		{ return STAR;}
"/" 		{ return SLASH;}
"(" 		{ return LBRA;}
")" 		{ return RBRA;}
"=" 		{ return EQ;}
"!=" 	{ return NEQ;}
":=" 	{ return ASSIGN;}
"<" 		{ return LT;}
">" 		{ return GT;}
"<=" 	{ return LTE;}
">=" 	{ return GTE;}

"BEGIN" 		{ return TBEGIN;}
"DO" 		{ return DO;}
"ELSE" 		{ return ELSE;}
"END" 		{ return END;}
"ID" 		{ return ID;}
"INT" 		{ return INT;}
"INPUT" 		{ return INPUT;}
"PRINT" 		{ return PRINT;}
"THEN" 		{ return THEN;}
"VAR" 		{ return VAR;}
"WHILE" 		{ return WHILE;}

"REPEAT" 		{ return REPEAT;}
"UNTIL" 		{ return UNTIL;}

"USING" 		{ return USING;}
"IN" 		{ return IN;}

{DIGIT}+ {return INT;}
{CHAR}+  {return ID;}

<<EOF>>	 		  {return EOF;} /* end of file */
[ \t\n]+          /* eat up whitespace */

%%

int yywrap() { return EOF; }

