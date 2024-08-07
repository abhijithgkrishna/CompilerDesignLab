%{
	#include <stdio.h>
%}
%%
"abc" {printf("ABC");}
\n {printf("\n"); return 0;}
. printf("%s",yytext);
%%
int main()
{
	printf("Enter the input string : \n");
	yylex();
}
int yywrap()
{
	return 1;
}