%{
/* Definition section */
extern int yylval ;
# include "y.tab.h"
%}

/* Rule Section */
%%
[0-9]+ {yylval = atoi(yytext); return NUMBER;}
[\t] ;
[\n] return 0;
. return yytext [0];
%%

int yywrap ()
{
return 1;
}
