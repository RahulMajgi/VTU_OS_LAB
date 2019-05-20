%{
#include<stdio.h>
extern int yylex();
%}
%left '+''-'
%left '/''*'
%%
expr: E {printf("THE RESULT IS = %d",$1);}
E:E'+'E {$$=$1+$3;}
|E'-'E {$$=$1-$3;}
|E'*'E {$$=$1*$3;}
|E'/'E {$$=$1/$3;}
|'('E')' {$$=$2;}
|id {$$=$1;}
|;
%%

void main()
{
	printf(" Enter the expression \n");
	yyparse();
	printf(" VALID EXPRESSION!!!\n");
}

void yyerror()
{
printf("INVALID EXPRESSION!!!\n");
}
