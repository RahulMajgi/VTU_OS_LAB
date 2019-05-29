%{
	#include<stdio.h>
	int opnd=0,opr=0,br=0;
%}
%x OPN
%%
[0-9]+ {BEGIN OPN, opnd++;}
"(" {br++;}
[^0-9]+ {printf("invalid exp"); exit(0);}
<OPN>"("{br++;}
" "{;}
<OPN>")"{br--;}
<OPN>[+ - * /] {BEGIN 0;opr++}
<OPN>[0-9]+ {printf("invalid"); exit(0);}
