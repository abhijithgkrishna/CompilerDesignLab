%{
	#include "y.tab.h"
%}

%%
[a-zA-Z] {return LETTER;}
[0-9] {return DIGIT;}
[\n] {return '\n';}
[_] {return UND;}
. {return yytext[0];}
%%