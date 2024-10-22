%{
#include <stdio.h>
#include <stdlib.h>
%}

%token NUMBER ID
%left '+' '-'
%left '*' '/'

%%
valid: E '\n' {printf("Expression is valid\n");return 0;}
E: E '+' E
 | E '-' E
 | E '*' E
 | E '/' E
 | NUMBER
 | ID
 | '(' E ')'
%%

int main() {
    printf("Enter Expression:");
    yyparse();
    return 0;
}

int yyerror() {
    printf("Invalid Expression\n");
    exit(1);
}