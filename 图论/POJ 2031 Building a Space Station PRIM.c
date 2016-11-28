#include <stdio.h>
#include <string.h>
#include <math.h>
#define INF 100000.0
struct point
{
    double x;  double y;  double z;  double r;
}p[102];
int v[102];
double map[102][102], d[102], dist;

void cal(int a, int b)
{
    double dt;
    dt = sqrt((p[a].x-p[b].x)*(p[a].x-p[b].x) +( p[a].y-p[b].y)* (p[a].y-p[b].y)+(p[a].z-p[b].z)* (p[a].z-p[b].z));
    if(dt <= (p[a].r + p[b].r))   map[a][b] = 0;
    else map[a][b] = dt -  (p[a].r + p[b].r) ;
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
            if(!v[j] && d[j] < min)
            {
                st = j;     min = d[j];
            }
        }
        v[st] = 1;  dist += min;
        for(j = 1; j <= n; j++)
        {
            if(!v[j] && d[j] > map[st][j])  d[j] = map[st][j];
        }
    }
}

int main(void)
{
    int n, i, j;
    while(scanf("%d", &n) && n)
    {

        for(i = 1; i <= n; i++)
        {
            scanf("%lf%lf%lf%lf", &p[i].x, &p[i].y, &p[i].z, &p[i].r);
        }
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
                cal(i, j);
        }
        prim(n);
        printf("%.3f\n", dist);
    }
    return 0;
}
