%{
	#include<stdio.h>
	int count=0;
%}

%x E F
%%
"//" {BEGIN F,count++;}
<F>. ;
<F>\n {BEGIN 0;}
"/*" {BEGIN E ,count++;}
<E>. ;
<E>\n ;
<E>"*/" {BEGIN 0;}

%%
void main()
{
	yyin= fopen("file1.txt","r");
	yyout= fopen("file2.txt","w");
	yylex();
	printf("count=%d",count);
}
