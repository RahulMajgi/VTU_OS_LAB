%{
	#include<stdio.h>
	int l=0,w=0,le=0;
%}
%%
[^a-zA-z] {le++; }
\n { l++; w++; }
" " { w++; }
%%
void main()
{
	printf("enter the exp:");
	yylex();
	printf("the no. of lines,words and letters are  %d,%d,%d",l,w,le);
}
