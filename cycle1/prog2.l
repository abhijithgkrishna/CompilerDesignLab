%{
	#include<stdio.h>
	int vc = 0;
	int cc = 0;
%}
%%
[aeiouAEIOU] {vc ++;}
[A-Za-z] {cc++;}
[\n] {return 0;}
%%

int main()
{
	printf("Enter input string : ");
	yylex();
	printf("Number of vowels = %d \n",vc);
	printf("Number of consonants = %d \n",cc);
}
int yywrap()
{
	return 1;
}
