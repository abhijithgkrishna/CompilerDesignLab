%{
#include <stdio.h>
#include <stdlib.h>
%}

%token DIGIT LETTER UND

%%
stmt: variable '\n' {printf("Valid identifier\n"); return 0;};

variable : LETTER alphanumeric_opt;
alphanumeric_opt: alphanumeric|;
alphanumeric : LETTER alphanumeric
| DIGIT alphanumeric
| UND alphanumeric
| LETTER
| DIGIT
| UND ;
%%

int yyerror(){
	printf("Invalid Identifier\n");
	exit(0);
}

void main(){
	printf("Enter identifier:");
	yyparse();
}