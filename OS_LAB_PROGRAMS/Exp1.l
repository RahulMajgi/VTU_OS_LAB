%{
#include<stdio.h>
int id=0,op=0,bracket=0,diff;
%}
%%
[+*] {op++;printf("%s is an operator\n",yytext);}
[(] {bracket++;}
[)] {bracket--;}
[a-zA-Z] {id++;printf("%s is an identifier\n",yytext);}
[0-9]+ {id++;printf("%s is an identifier\n",yytext);}
%%
int main()
{
yyin=fopen("inputexp1","r");
yylex();
diff=id-op;
printf("The number of operators are = %d\n The number of identifiers are = %d\n",op,id);
if(diff>=1||bracket!=0||id==1)
{
	printf("INVALID!!\n");
}
else
{
	printf("VALID!!\n");
}
}
