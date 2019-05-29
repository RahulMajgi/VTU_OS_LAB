%{
	#include<stdio.h>
	#include<stdlib.h>
	extern int yylex();
%}
%token A B
%%
expr:S'\n' {printf("accepted"); return 0;}
S: A T B|B
T: A T
|;
%%
void main()
{
	printf("enter the string \n");
	yyparse();
}
int yyerror()
{
	printf("invalid\n");
}
