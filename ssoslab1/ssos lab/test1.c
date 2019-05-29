%{
	#include<stdio.h>
	int count=0,opr=0,br=0;
%}
%x opn
%%
[0-9]+ {BEGIN opn; count++; }
"(" {br++; }
//[^0-9]+ { printf("invalid exp"); exit(0); }

//<opn>"(" {br++; }
<opn>")" {br--; }
//<opn>[+"-"*] {BEGIN 0; opr++; }
/*
<opn>[0-9]+ {printf("invalid"); exit(0); }
%%
*/
void main()
{
	printf("enter the exp:");
	yylex();
	if(count<=opr || br!=0 || count<1)
	{	
		printf("invalid\n");
	}
	//else 
	{
		printf("valid\n");
	}
	printf("\nthe no. of variables and operators are %d ,%d",count,opr);
}

