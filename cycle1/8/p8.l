%{
    #include <stdio.h>
    int COMMENT = 0;
    int cnt = 0;
%}

identifier [a-zA-Z][a-zA-Z0-9]*

%%
#.*             { printf("\n %s is a preprocessor", yytext); }

int |
float |
char |
double |
while |
for |
do |
if |
break |
continue |
void |
switch |
case |
long |
struct |
const |
typedef |
return |
else |
goto {printf("\n %s is a keyword", yytext); }

"/*"            { COMMENT = 1; }
"*/"            { COMMENT = 0; cnt++; }

{identifier}\(  { if(!COMMENT) printf("\n Function %s", yytext); }

\{              { if(!COMMENT) printf("\n Block begins"); }
\}              { if(!COMMENT) printf("\n Block ends"); }

{identifier}(\[[0-9]*\])? { if(!COMMENT) printf("\n identifier %s", yytext); }

\".*\"          { if (!COMMENT) printf("\n \t %s is a String", yytext); }
[0-9]*          { if (!COMMENT) printf("\n \t %s is a Number", yytext); }

=               { if(!COMMENT) printf("\n assignment operator %s", yytext); }
\<= |
\>= |
\< |
\> |
==    { if(!COMMENT) printf("\n relational operator %s", yytext); }
%%

int main() {
    yyin = fopen("input.txt", "r");
    yylex();
    fclose(yyin);
    printf("\n \n Total No. of comments are %d \n", cnt);
    return 0;
}

int yywrap() {
    return 1;
}