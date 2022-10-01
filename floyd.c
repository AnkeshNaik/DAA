#include <stdio.h>

int n;
void display(int a[n][n], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

void floyd(int a[n][n], int n)
{

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] > (a[i][k] + a[k][j]))
                    a[i][j] = a[i][k] + a[k][j];
            }
        }
         printf("\nA%d :",k);
         display(a,n);
    }
}

void main()
{
    printf("enter the no\n");
    scanf("%d", &n);
    int a[n][n];
    printf("enter the matrix");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    display(a, n);
    floyd(a, n);
    printf("adjjhaj\n");
    display(a, n);
}