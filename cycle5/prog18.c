#include <stdio.h>
#include <string.h>

void gen_code_for_operator(char *inp, char operator, char * reg)
{
    int i = 0, j = 0;
    char temp[100];

    while (inp[i] != '\0')
    {
        if (inp[i] == operator)
        {
            printf("%c\t%c\t%c\t%c\n", operator, * reg, inp[i - 1], inp[i + 1]);
            temp[j - 1] = *reg;
            i += 2;
            (*reg)--;
            continue;
        }
        temp[j] = inp[i];
        i++;
        j++;
    }
    temp[++j] = '\0';
    strcpy(inp, temp);
}

void gen_code(char *inp)
{
    char reg = 'Z';

    gen_code_for_operator(inp, '/', &reg);
    gen_code_for_operator(inp, '*', &reg);
    gen_code_for_operator(inp, '+', &reg);
    gen_code_for_operator(inp, '-', &reg);
    gen_code_for_operator(inp, '=', &reg);
}

void main()
{
    char inp[100];
    printf("Enter expression: ");
    scanf("%s", inp);
    printf("Oprtr\tDestn\tOp1\tOp2\n");
    gen_code(inp);
}
