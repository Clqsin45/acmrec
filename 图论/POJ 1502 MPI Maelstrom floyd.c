#include <stdio.h>
#include <string.h>
#define INF 100002
int f[202][202];
void floyd(int n)
{
    int i, j ,k;
    for(k = 1; k <= n ; k++)
    {
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <=n ; j++)
            {
                if(f[i][j] > (f[i][k] + f[k][j])) f[i][j] = f[i][k] + f[k][j];
            }
        }
    }
}
int main(void)
{
    int n, i, j, min, max;
    char op[1000];
    scanf("%d", &n);
    memset(f, 0, sizeof(f));
    for(i = 1; i < n ; i++)
    {
        for(j = 1 ;j <= i; j++)
        {
            scanf("%s", op);
            if(strcmp(op, "x") == 0)
            {
                f[i + 1][j] = f[j][i + 1] = INF;
            }
            else
            {
                f[i + 1][j] = f[j][i + 1] = atoi(op);
            }
        }
    }
    floyd(n);
    max = 0;
    for(j = 2; j <= n; j++)
    {
        if(max < f[1][j]) max = f[1][j];
    }
    printf("%d\n",max);

    return 0;
}
