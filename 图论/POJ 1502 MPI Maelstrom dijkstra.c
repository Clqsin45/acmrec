#include <stdio.h>
#include <string.h>
#define INF 100002
int f[202][202], v[202], d[202];

void dijkstra(int n)
{
    int i, j, st, min;
    memset(v,0,sizeof(v));
    for(i = 1; i <= n; i++) d[i] = f[1][i];
    d[1] = 0; v[1] = 1;
    for(i = 1; i <= n; i++)
    {
        min = INF; st = 1;
        for(j = 1; j <= n; j++)
        {
            if(!v[j] && d[j] < min)
            {
                st = j;
                min = d[j];
            }
        }
        v[st] = 1;
        for(j = 1; j <= n ; j++)
        {
            if(!v[j] && d[j] > d[st] + f[st][j])
                d[j] = d[st] + f[st][j];
        }
    }
}
int main(void)
{
    int n, i, j, max;
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
    dijkstra(n);
    max = 0;
    for(i = 2; i <= n; i++) if(max < d[i]) max = d[i];
    printf("%d\n", max);
    return 0;
}
