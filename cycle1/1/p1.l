%{
int vowel=0;
int cons=0;
%}

%%
[aeiouAEIOU]   { vowel++; }
[a-zA-Z]       { cons++; }
\n             { return 0; }
%%

int main() {
    printf("Enter String:");
    yylex();
    printf("No of Vowels: %d\n", vowel);
    printf("No of Consonants: %d\n", cons);
    return 0;
}

int yywrap() {
    return 1;
}