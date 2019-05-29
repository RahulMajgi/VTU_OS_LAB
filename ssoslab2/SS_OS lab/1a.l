%{ 
	#include<stdio.h>
	int count=0,op=0,bracket=0;
%}
%%
[+] {op++;}
[*] {op++;}
[0-9] {count++;}
[(] {bracket++;}
[)] {bracket--;}
%%

void main()
{
	printf("enter expression:");
	yylex();
	if(count<=op||bracket!=0||count==1)
	{
		printf("invalid\n");
		printf("operators=%d\n numbers=%d\n bracket=%d\n",op,count,bracket);
	}
	else
	{
		printf("valid\n");
		printf("operators=%d\n numbers=%d\n bracket=%d\n",op,count,bracket);
	}
}



