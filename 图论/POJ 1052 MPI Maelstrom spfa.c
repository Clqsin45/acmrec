#include <stdio.h>
#include <string.h>
#define INF 1000002
int map[102][102], v[102], d[102], q[INF];

void spfa(int n)
{
    int i, j, f, r, x, y;
    memset(v, 0, sizeof(v));
    for(i = 1; i <= n; i++) d[i] = INF;
    d[1] = 0;   v[1] = 1;
    for(q[f = r = 1] = 1; f <= r; f++)
    {
        x = q[f];
        v[x] = 0;
        for(y = 1; y <= n; y++)
        {
            if(x != y && d[y] > d[x] + map[x][y])
            {
                d[y] = map[x][y] + d[x];
                if(!v[y])
                {
                    v[y] = 1;   q[++r] = y;
                }
            }
        }
    }

}
int main(void)
{
    int n , i, j, max = -INF;
    char op[100];
    scanf("%d", &n);
    for(i = 1; i < n; i++)
    {
        for(j = 1; j <= i; j++)
        {
            scanf("%s",op);
            if(strcmp("x",op) == 0)
            {
                map[i + 1][j] = map[j][i + 1] = INF;
            }
            else
            {
                map[i + 1][j] = map[j][i + 1] = atoi(op);
            }

        }
    }
    for(i = 1; i <= n; i++)
    {
       for(j = 1; j <= n; j++)
        {
            printf("%-6d ", map[i][j]);
        }
        printf("\n");
    }

    spfa(n);
    for(i = 1; i <= n; i++)
    {
        printf("%d  %d\n",i, d[i]);
        if(max < d[i])  max = d[i];
    }
    printf("%d\n", max);
    return 0;
}
