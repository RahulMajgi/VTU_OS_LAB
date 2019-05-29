%{
#include<stdio.h>
#include<stdlib.h>
extern int yylex();
extern int yyparse();
extern FILE *yyin;
int id=0,key=0,op=0;
%}

%token ID KEY OP
%%
input:
ID input {id++; }
|KEY input {key++; }
|OP input {op++; }
|;
%%
int main()
{
	FILE *myfile=fopen("text6.c","r");
	if(!myfile)
	{
	printf("can't open file");
	return -1;
	}
	yyin=myfile;
	
	yyparse();
	
	printf("Keywords=%d,Identifiers=%d,Operators=%d",key,id,op);
}
void yyerror()
{
	printf("ERROR!");
	exit(-1);
}
