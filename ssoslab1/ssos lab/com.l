%{
	#include<stdio.h>
%}
%%
"and"|"but" {printf("compound"); exit(0); }
"because" {printf("compound"); exit(0); }

. ;
\n ;
%%
void main()
{
	printf("enter the exp:");
	yylex();
	printf("simple");
}
