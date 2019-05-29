%{
#include<stdio.h>
#include<stdlib.h>
extern int yylex();
%}
%token A B
%%
str:S '\n' {printf("accepted"); return 0; }
S: A T B
T:A T
|;
%%
void main()
{
printf("Enter the expression");
yyparse();
}
void yyerror()
{
	printf("ERROR!");
	exit(-1);
}
