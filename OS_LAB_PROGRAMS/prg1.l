%{
#include<stdio.h>
int line=0,word=0,letter=0;
%}
%%
[A-Za-z] {letter++;}
[" "] {word++;}
\n {line++;word++;}
%%
void main()
{
	//printf("Enter the input \n");
	yyin=fopen("inputexp1.txt","r");	
	yylex();
	/*printf("The number of letters present are =%d \n The number of words are =%d \n The number of lines are =%d \n",letter,word,line);*/
}
