%{
#include "y.tab.h"
extern int yylval;
%}
%%
[ \t]+ {;}
[a-zA-Z] {return let;}
[0-9] {return dig;}
\n {return 0;}
. {;}
%%
