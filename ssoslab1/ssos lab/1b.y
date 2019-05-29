%{
#include<stdio.h>
#include<stdlib.h>
extern int yylex();
%}
%token id
%left '+''-'
%left '*''/'
%%
expr: E {printf("results=%d, VALID",$1); return 0; }
E: E'+'E {$$=$1+$3; }
  | E'-'E {$$=$1-$3; }
  | E'*'E {$$=$1*$3; }
  | E'/'E {$$=$1/$3; }
  | '('E')' {$$=$2; }
  | id {$$=$1; }
  | ;
%%
void main()
{
	printf("Enter the expression");
	yyparse();
	
}
void yyerror()
{
	printf("INVALID");
}


