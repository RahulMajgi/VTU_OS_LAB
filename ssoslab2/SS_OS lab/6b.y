%{
	#include<stdio.h>
	#include<stdlib.h>
	extern int yylex();
	
	extern FILE *yyin;
	int id=0, key=0,op=0;
%}
%token ID KEY OP
%%
input: ID input {id++;}
       |KEY input {key++;}
       |OP input {op++;}
       |ID {id++;}
       |KEY {key++;} 
       |OP {op++;};

%%
int main()
{
 yyin=fopen("text6.c","r");
 if(!yyin)
 {
	printf("cant open file\n");
	return -1;
 }
 yyparse();

 printf(" keyword=%d \n identifiers=%d\n operators=%d\n",key,id,op);
 }

 void yyerror()
{
	printf("error!");
	exit (-1);
}








