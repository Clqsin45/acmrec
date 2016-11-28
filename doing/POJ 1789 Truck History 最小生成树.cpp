#include <stdio.h>
#define INF 0x7f7f7f7f
#define MAX 2222
char c[MAX][10];
int dif[MAX][2002], v[MAX], d[MAX], n;

int caldif(int x, int y)
{
    int sum = 0, i;
    for(i = 1; i <= 7; i++)
        if(c[x][i] != c[y][i])  sum++;
    return sum;
}

int prim(void)
{
    int sum = 0, i, j, min, st;
    for(i = 0; i <= n; i++)
    {
        d[i] = dif[1][i]; v[i] = 0;
    }
    v[1] = 1;   d[1] = 0;
    for(i = 1; i < n; i++)
    {
        min = INF;  st = 1;
        for(j = 1; j <= n; j++)
        {
            if(!v[j] && min > d[j])
            {
                min = d[j]; st = j;
            }

        }
        v[st] = 1;  sum += min;
        for(j = 1; j <= n; j++)
        {
            if(!v[j] && d[j] > dif[st][j])  d[j] = dif[st][j];
        }
    }
    return sum;
}
int main(void)
{
    int i, j;
    while(scanf("%d", &n) && n)
    {
        for(i = 1; i <= n; i++)
            scanf("%s", c[i] + 1);
        for(i = 1; i <= n; i++)
            for(j = i; j <= n; j++)
                dif[i][j] = dif[j][i] = caldif(i, j);
        printf("The highest possible quality is 1/%d.\n", prim());
    }
    return 0;
}
