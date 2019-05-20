%{
#include<stdio.h>
int cmt=0;
%}
%x F E
%%
"//" {BEGIN F;cmt++;}
<F>. {;}
<F>\n {BEGIN 0;}
"/*" {BEGIN E;cmt++;}
<E>. {;}
<E>\n {;}
<E>"*/" {BEGIN 0;}
%%
void main()
{
	//printf("Enter the input \n");
	yyin=fopen("prg1.l","r");	
	yyout=fopen("output","w");
	yylex();
	printf("The number of comments are =%d \n",cmt);
}
