%{
#include "tokens.h"
%}

DIGIT    [0-9]

         
%%

";" 	{ return SEMI;}
{DIGIT}+ {return INT;}

<<EOF>>	 {return EOF;} /* end of file */
[ \t\n]+          /* eat up whitespace */


%%

int yywrap() { return EOF; }


