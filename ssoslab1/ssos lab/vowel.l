%{
	#include<stdio.h>
	int count=0;
%}
%%
[aeiouAEIOU] {count++; }
. ;
\n ;
%%
void main(int argc,char *argv[])
{
	printf("enter the exp:");
	yylex();
	printf("the no. of vowels are %d",count);
}
