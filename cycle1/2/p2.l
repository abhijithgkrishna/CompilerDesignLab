%{
    #include<stdio.h>
    int wc=0, lc=0, cc=0;
%}

%%
[\n]       { lc++; cc += yyleng; }
[ \t]      { cc += yyleng; }
[^\t\n ]+  { wc++; cc += yyleng; }
%%

int main() {
    FILE *file;
    file = fopen("input.txt", "r");
    if (!file) {
        printf("File not opened");
        exit(0);
    }
    yyin = file;
    yylex();
    printf("No of lines: %d\n", lc);
    printf("No of words: %d\n", wc);
    printf("No of characters: %d\n", cc);
}

int yywrap() {
    return 1;
}