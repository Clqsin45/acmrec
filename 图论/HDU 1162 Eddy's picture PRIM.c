#include <stdio.h>
#include <math.h>
#define INF 1000000.0

struct point
{
    double x;   double y;
}p[102];
double map[102][102], d[102], dist;
int v[102];

void cal(int a, int b)
{
    map[a][b] = sqrt((p[a].x-p[b].x)*(p[a].x-p[b].x) +(p[a].y-p[b].y)*(p[a].y-p[b].y));
    return;
}

void prim(int n)
{
    int i, j, st;
    double min;
    for(i = 1; i <= n; i++)
    {
        v[i] = 0;   d[i] = map[1][i];
    }
    v[1] = 1;   dist = 0.0;
    for(i = 1; i < n; i++)
    {
        min = INF;
        for(j = 1; j <= n; j++)
        {
            if(!v[j] && min > d[j])
            {
                min = d[j];     st = j;
            }
        }
        v[st] = 1;  dist += min;
        for(j = 1; j <= n; j++)
        {
            if(!v[j] && map[st][j] < d[j])  d[j] = map[st][j];
        }
    }
}
int main(void)
{
    int n, i, j;
    while(scanf("%d", &n) != EOF)
    {
        for(i = 1; i <= n; i++)
        {
            scanf("%lf%lf", &p[i].x, &p[i].y);
        }
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                cal(i, j);
        prim(n);
        printf("%.2f\n", dist);
    }
    return 0;
}
