#include <stdio.h>
#include <string.h>

int n;

void closure(int state, int matrix[][n])
{
    for (int i = 0; i < n; i++)
    {
        if (matrix[state][i] == 1)
        {
            printf(", q%d", i);
            closure(i, matrix);
        }
    }
    return;
}

int main()
{
    FILE *INPUT = fopen("input10.txt", "r");
    char state1[3], input[3], state2[3];
    int s1, s2;

    printf("Enter the no of states: ");
    scanf("%d", &n);
    int mat[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[i][j] = 0;
        }
    }

    while (fscanf(INPUT, "%s%s%s", state1, input, state2) != EOF)
    {
        if (strcmp(input, "e") == 0)
        {
            s1 = state1[1] - '0';
            s2 = state2[1] - '0';
            mat[s1][s2] = 1;
        }
    }

    printf("Epsilon closure of\n");
    for (int k = 0; k < n; k++)
    {
        printf("q%d : q%d", k, k);
        closure(k, mat);
        printf("\n");
    }

    return 0;
}
