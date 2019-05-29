%{
#include "y.tab.h"
extern int yylval;
%}
%%
a { return A; }
b { return B; }
. { return yytext[0]; }
\n { return yytext[0]; }
%%
