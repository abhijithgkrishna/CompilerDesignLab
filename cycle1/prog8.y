%{
/* Definition section */
#include <stdio.h>
int flag = 0;
%}

%token NUMBER

%left '+'
%left '-'
%left '*'
%left '/'
%left '%'
%left '(' ')'

/* Rule Section */
%%
ArithmeticExpression : E {
    printf("\nResult: %d\n", $$);
    return 0;
};

E : E '+' E { $$ = $1 + $3; }
  | E '-' E { $$ = $1 - $3; }
  | E '*' E { $$ = $1 * $3; }
  | E '/' E { $$ = $1 / $3; }
  | E '%' E { $$ = $1 % $3; }
  | '(' E ')' { $$ = $2; }
  | NUMBER { $$ = $1; }
  ;

%%

// driver code
void main() {
    printf("\nEnter expression: ");
    yyparse();
    if (flag == 0)
        printf("\nExpression is valid\n\n");
}

void yyerror() {
    printf("\nInvalid expression\n\n");
    flag = 1;
}
