#include <stdio.h>
#include <string.h>
#define INF 100000002
int v[1002], d[1002], map[1002][1002];

int findmin(int x, int y)
{
    return x < y ? x : y;
}
void dijkstra(int n)
{
    int i,j,st ,max;
    for(i = 1; i <= n;i++)
    {
        v[i] = 0;   d[i] = map[1][i];
    }
    d[1] = 0;   v[1] = 1;
    for(i = 1; i <= n; i++)
    {
        max = 0;    st = 1;
        for(j = 1; j <= n; j++)
        {
            if(!v[j] && d[j] > max)
            {
                st = j;     max = d[j];
            }
        }
        v[st] = 1;
        for(j = 1; j <= n; j++)
        {
             if(!v[j] && d[j] < findmin(d[st], map[st][j]))
               d[j] = findmin(d[st], map[st][j]);
        }
    }
}

int main(void)
{
    int city, ct = 1, p, r, i, st1, st2, stl;
    scanf("%d", &city);
    while(ct <= city)
    {
        memset(map, 0, sizeof(map));
        scanf("%d%d", &p, &r);
        for(i = 1; i <= r; i++)
        {
                scanf("%d%d%d", &st1, &st2, &stl);
                map[st1][st2] = map[st2][st1] = stl;
        }
        dijkstra( p);
        printf("Scenario #%d:\n", ct);
        printf("%d\n\n", d[p]);
        ct++;
    }
    return 0;
}
