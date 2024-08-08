%{
    #include<stdio.h>
    #include<stdlib.h>    
%}

%token NUMBER ID NL
%left '+' '-'
%left '*' '/'
%%
valid : E NL {printf("Expression is valid");}
E : E '+' E
    | E '-' E
    | E '*' E
    | E '/' E 
    | NUMBER
    | ID
    | '(' E ')';
%%

int main()
{
    printf("Enter the expression : \n");
    yyparse();
}

int yyerror()
{
    printf("Some error occured");
    exit(1);
}