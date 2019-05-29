%{   
	#include<stdio.h>
	extern int yylval;
%}
%%
[\t]	;
[+\-*=<>]	{printf("operator is %s \n",yytext); return op;}
"int"|"char"|"float"|"bool"|"if"|"else"|"do"|"while"|"printf" {printf("the keyword is %s \n",yytext); return key;}
[a-zA-Z][A-Za-z0-9]* {printf("identifiers are %s \n", yytext); return id;}
.	;
%%












   

