%{
	#include<stdio.h>
	int count=0;
%}
%x F E
%%
"//" {BEGIN F; }
"/*" {BEGIN F; }
<F>. {BEGIN F;}
<F>/n {BEGIN 0; count++; }
<E>./n* {BEGIN E; }
<E>*/ {BEGIN 0; count++; }
%%
void main(int arg c,char *argv[])
{
	yyin=fopen(argv[1],"r");
	yyout=fopen(argv[2],"w");
	yylex();
	printf("the no. of comments are %d",count);
	

