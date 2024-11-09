#include <stdio.h>
#include <string.h>

int n;
int visited[10];

void clearVisited()
{
    for (int i = 0; i < n; i++)
        visited[i] = 0;
}
void closure(int state, int matrix[][n])
{
    for (int i = 0; i < n; i++)
    {
        if (matrix[state][i] == 1 && visited[i] == 0)
        {
            visited[i] = 1;
            printf(", q%d ", i);
            closure(i, matrix);
        }
    }
}

void main()
{
    FILE *INPUT = fopen("ip-eclo.txt", "r");
    char state1[3], state2[3], symbol[3];

    int s1, s2;

    fscanf(INPUT, "%d", &n);
    printf("N = %d \n", n);

    int matrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            matrix[i][j] = 0;
    }
    clearVisited();

    while (fscanf(INPUT, "%s%s%s", state1, symbol, state2) != EOF)
    {
        printf("line \n");
        if (strcmp(symbol, "e") == 0)
        {
            s1 = state1[1] - '0';
            s2 = state2[1] - '0';
            matrix[s1][s2] = 1;
        }
    }
    printf("Epsilon closure \n --------------------- \n");
    for (int i = 0; i < n; i++)
    {
        visited[i] = 1;
        printf("q%d : q%d ", i, i);
        closure(i, matrix);
        printf("\n");
        clearVisited();
    }
}