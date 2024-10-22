#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool isDelimiter(char ch) {
    char delimiter[]={' ','+','-','*','/',',',';','>','<','=','(',')','[',']','{','}'};
    for(int i=0;i<16;i++)
        if(ch == delimiter[i]) return true;
    return false;
}

bool isOperator(char ch) {
    char op[]={'+','-','*','/','>','<','='};
    for(int i=0;i<7;i++)
        if(ch == op[i]) return true;
    return false;
}

bool validIdentifier(char *str) {
    if (!((str[0] >= 'a' && str[0] <= 'z' )|| (str[0] >='A' && str[0] <= 'Z' )|| str[0]=='_'))
        return false;
    return true;
}

bool isKeyword(char *str) {
    char *keywords[] = {"if", "else", "while", "for", "break", "continue", "int", "char", "void", "main", "return"};
    for (int i = 0; i < 11 ; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return true;
    }
    return false;
}

bool isNumber(char *str) {
    bool hasDecimal = false;
    int i=0;
    if (str[0] == '\0') return false;
    if (str[0] == '-' || str[0] =='+') i++;
    for (i; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            if (hasDecimal)
                return false;
            hasDecimal = true;
        } else if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    return true;
}

char *subString(char *str, int left, int right) {
    char *subStr = (char *)malloc(right - left + 2);
    if (!subStr) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    for(int i=left;i<=right;i++){
    	subStr[i-left]=str[i];
    }
    subStr[right-left+1] = '\0';
    return subStr;
}

void parse(char *str)
{
	int left = 0, right = 0;
	int len = strlen(str);
	while(right < len && left <= right)
	{
		if(!isDelimiter(str[right]))
			right++;

        if(isDelimiter(str[right]) && left == right){
            if(isOperator(str[right]))
                printf("%c is an operator \n",str[right]);
            right++;
            left = right;
        }

        if(isDelimiter(str[right]) && (left != right || right == len)){
            char *subStr = subString(str,left,right-1);
            if (isKeyword(subStr))
				printf("%s is a Keyword\n",subStr);
			else if(isNumber(subStr))
				printf("%s is a Number\n", subStr);
			else if(validIdentifier(subStr))
				printf("%s is Identifier\n", subStr);
			else 
				printf("%s Error : Invalid Token\n", subStr);
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