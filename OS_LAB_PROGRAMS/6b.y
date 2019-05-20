%{
#include<stdio.h>
extern int yylex();
%}
%token let dig
%%
input:let input {;}
|let {;}
|dig {;};
%%

void main()
{
	printf("Enter the variable \n");
	yyparse();
	//printf("Number of keywords,operator and identifiers are %d and %d and %d \n",key,op,id);
	printf("VALID VARIABLE!!!\n");
}

void yyerror()
{
printf("INVALID VARIABLE!!!\n");
}
