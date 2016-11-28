#include <stdio.h>
#include <string.h>
#define INF 1000002
int map[1002][1002], d[1002], last[1002], v[1002], h[10002],r[10002], max = 0, cost;

int prim(int n)
{
    int i, j, min, st, ct = 0, mm;
    for(i = 1; i <= n; i++)
    {
        v[i] = 0;   d[i] = map[1][i];   last[i] = 1;
    }

    v[1] = 1;   cost = 0;    max = 0;
    for(i = 1; i < n; i++)
    {
        min = INF;//printf("###\n");
        for(j = 1; j <= n; j++)
        {
            if(!v[j] && d[j] < min)
            {
                st = j;    min = d[j];
            }
        }
        v[st] = 1; // cost += min;
        if(max < min)   max = min;
        h[++ct] = last[st];
        r[ct] = st;
        for(j = 1; j <= n; j++)
        {
            if(!v[j] && d[j] > map[st][j])
            {
                d[j] = map[st][j];
                last[j] = st;
            }
        }
    }
    return ct;
}

int main(void)
{
    int n, m, i, j, st1, st2, stt, ct;
    scanf("%d%d", &n, &m);
    for(i = 1; i<= n; i++)
        for(j = 1; j <=n ; j++)
            map[i][j] = INF;
    for(i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &st1, &st2, &stt);
        map[st1][st2] = map[st2][st1] = stt;
    }

    ct = prim(n);
    printf("%d\n%d\n", max, ct);
    for(i = 1; i <= ct; i++)
    {
        printf("%d %d\n", h[i], r[i]);
    }
    return 0;
}
