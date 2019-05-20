%{
#include<stdio.h>
extern int yylex();
int count = 0;
%}
%token A B
%%
str: S'\n' {if(count>9)
		{
			printf("STRING ACCEPTED \n");
	        }
	        ;return 0;} 
S:A T B {count++;}
T:A T {count++;}
|;
%%

void main()
{
	printf(" Enter the expression \n");
	yyparse();
}

void yyerror()
{
	printf("STRING REJECTED\n");
}
