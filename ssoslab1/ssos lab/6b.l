%{
#include "y.tab.h"
extern int yylval;
%}
%x T
%%
["] {BEGIN T; }
<T>["] {BEGIN 0; }
[\t]	;
[+|-|*|/|=|<|>] { printf("\noperator is %s",yytext); return OP; }
int|char|bool|float|void|for|do|while|if|else|return|printf|scanf|main  { printf("\nkeyword is %s",yytext); return KEY; }
[A-Za-z][A-Za-z0-9]*  { printf("\nidentifier is %s",yytext); return ID; }
. ;
%%