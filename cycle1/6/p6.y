%{
	#include<stdio.h>
%}

%token NUMBER
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

%%
ArithmeticExpression: E{printf("Result: %d\n",$$); return 0;};
E:E'+'E{$$=$1+$3;}
|E '-' E{$$=$1-$3;}
|E '*' E{$$=$1*$3;}
|E '/' E{$$=$1/$3;}
|E '%' E{$$=$1%$3;}
| '('E')'{$$=$2;}
| NUMBER {$$ = $1;}
;
%%

void main()
{
	printf("Enter expression : ");
	yyparse();
}

void yyerror(){
	printf("Invalid Expression\n");
}