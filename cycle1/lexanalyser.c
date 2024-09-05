#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

bool isDelimiter(char ch)
{
	if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == ',' || 
		ch == ';' || ch == '=' || ch == '<' || ch == '>' || ch == '(' || ch == ')' || 
		ch == '[' || ch == ']' || ch == '{' || ch == '}' )
	{
		return true;
	}
	return false;
}

bool isOperator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/'||
		ch == '<' || ch == '>' || ch == '=')
	{
		return true;
	}
	return false;
}

bool validIdentifier(char *str)
{
	if (str[0] == '0' || str[0] == '1' || str[0] == '2' || str[0] == '3' || str[0] == '4' || 
		str[0] == '5' || str[0] == '6' || str[0] == '7' || str[0] == '8' || str[0] == '9')
	{
		return false;
	}
	return true;
}

bool isKeyword ( char *str)
{
	if (!strcmp(str, "if" ) || !strcmp (str, "else" ) 
	 	|| !strcmp (str, "while" ) || !strcmp (str, "do" )
	 	|| !strcmp (str, "break" ) || !strcmp (str, "continue" ) || !strcmp(str,"int")
		|| !strcmp (str, "double" ) || !strcmp (str, "float" )
		|| !strcmp (str, "return" ) || !strcmp (str, "char" )
		|| !strcmp (str, "case" ) || !strcmp (str, "char" )
		|| !strcmp (str, "sizeof" ) || !strcmp (str, "long" )
		|| !strcmp (str, "short" ) || !strcmp (str, "typedef" )
		|| !strcmp (str, "switch" ) || !strcmp (str, "unsigned" )
		|| !strcmp (str, "void" ) || !strcmp (str, "static" )
		|| !strcmp (str, "struct" ) || !strcmp (str, "goto" ) )
		return ( true ) ;
	return ( false ) ;
}

bool isInteger(char *str)
{
	int len = strlen(str);
	if (len == 0)
		return false;
	for (int i = 0; i < len; ++i)
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && 
			str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && 
			str[i] != '8' && str[i] != '9')
		return false;
	}
	return true;
}

bool isRealNumber(char *str)
{
	int len = strlen(str);
	bool hasDecimal = false;

	if (len == 0)
	{
		return false;
	}
	for (int i = 0; i < len; ++i)
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && 
			str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && 
			str[i] != '8' && str[i] != '9' && str[i] != '.' || ( str[i] == '-' && i > 0))
		{
			return false;
		}
		if (str[i] == '.')
		{
			if (hasDecimal == true)
				return false;
			hasDecimal = true;
		}
	}
	return hasDecimal;
}

char *subString(char *str, int left, int right)
{
	char * subStr = (char*)malloc(sizeof(char)*(right-left+2));
	for (int i = left; i <= right; ++i)
		subStr[i-left] = str[i];
	subStr[right-left+1] = '\0';
	return subStr;
}

void parse(char *str)
{
	int left = 0, right = 0;
	int len = strlen(str);
	while(right <= len && left <= right)
	{
		if (isDelimiter(str[right]) == false)
		{
			right++;
		}
		if ((isDelimiter(str[right]) == true) && (left == right))
		{
			if(isOperator(str[right]) == true)
					printf("%c is an operator \n",str[right]);
			right++;
			left = right;
		}
		if (((isDelimiter(str[right]) == true) && (left != right)) || ((right == len) && (left != right)))
		{
			char *subStr = subString(str,left,right-1);
			if (isKeyword(subStr) == true)
			{
				printf("%s is a keyword \n",subStr);
			}
			else if(isInteger(subStr) == true)
			{
				printf("%s is an integer\n", subStr);
			}
			else if(isRealNumber(subStr) == true)
			{
				printf("%s is a real number\n", subStr);
			}
			else if((validIdentifier(subStr) == true)&& isDelimiter(str[right-1]) == false)
			{
				printf("%s is a valid identifier\n", subStr);
			}
			else if((validIdentifier(subStr) == false)&& isDelimiter(str[right-1]) == false)
			{
				printf("%s is not valid identifier\n", subStr);
			}
			left = right;
		}
	}
}

int main()
{
	char input[100];
	printf("Enter expression :\n");
	scanf("%[^\n]",input);
	printf("\nAfter parsing : \n\n");
	parse(input);
	return 0;
}