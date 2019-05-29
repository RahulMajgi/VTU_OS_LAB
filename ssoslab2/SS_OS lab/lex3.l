%{ 
	#include<stdio.h>
	int chars=0, words=0,spaces=0,lines=0;
%}
%%
[a-zA-Z0-9] {chars++;}
[" "] {words++, spaces++;}
[\n] {words++, lines++;}
%%

void main()
{
	printf("enter expression:");
	yylex();
	printf("characters=%d\n words=%d\n spaces=%d\n lines=%d\n",chars,words,spaces,lines);
}

