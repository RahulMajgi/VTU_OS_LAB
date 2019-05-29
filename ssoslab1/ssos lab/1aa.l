%{
	#include<stdio.h>
	int count=0,opr=0,br=0;
%}
%%
[+*] {opr++;}
[0-9] {count++;}
[(] {br++;}
[)] {br--;}
%%
void main()
{
	printf("enter the exp:");
	yylex();
	if(count<=opr || br!=0 || count<1)
	{	
		printf("invalid\n");
	}
	else 
	{
		printf("valid\n");
	}
	printf("\nthe no. of variables and operators are %d ,%d \n",count,opr);
} 