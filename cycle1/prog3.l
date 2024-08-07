%{
	#include <stdio.h>
	int lc = 0, wc = 0, cc = 0;
%}

%%
[\n]	{lc++; cc += yyleng;}
[ \t]	{ cc += yyleng;}
[^\t\n ]+ {wc++; cc += yyleng;}
%%

int main()
{
	FILE *fp;
	fp = fopen("ip_prog3.txt","r");
	yyin = fp;
	yylex();
	
	printf("The number of lines = %d \n",lc);
	printf("The number of words = %d \n",wc);
	printf("The number of chars = %d \n",cc);
}
int yywrap()
{
	return 1;
}