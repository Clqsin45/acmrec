#include <stdio.h>
#include <string.h>
#define INF 1000000
int map[1002][1002], d[1002], q[100002], v[1002];

int min(int x, int y)
{
    return x < y ? x: y;
}
void spfa(int s, int n)
{
    int f, r, i, x;
    memset(v, 0, sizeof(v));
    for(i = 2;  i <= n; i++)    d[i] = 0;
    d[1] = INF;    v[1] = 1;
    for(q[f = r = 1] = s; f <= r; f++)
    {
        x = q[f];
        v[x] = 0;
        for(i = 1; i <= n; i++)
        {
            if(i != x && d[i] < min(d[x],map[x][i]) )
            {
                d[i] = min(map[x][i],d[x]);
                if(!v[i])
                {
                    q[++r] = i;
                    v[i] = 1;
                }
            }
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
        spfa(1, p);
        printf("Scenario #%d:\n", ct);
        printf("%d\n\n", d[p]);
        ct++;
    }
    return 0;
}
