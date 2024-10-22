%{
    #include<stdio.h>
%}

%%
"abc"         { printf("ABC"); }
\n            { printf("\n"); return 0; }
.             { printf("%s", yytext); }
%%

int main() {
    printf("Enter String: ");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
