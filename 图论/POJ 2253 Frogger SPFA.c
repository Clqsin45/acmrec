#include <stdio.h>
#include <string.h>
#include <math.h>
#define INF 10000002

double map[202][202], d[202], px[202], py[202];
int v[202], q[INF];

double dist(int a, int b)
{
    return sqrt((px[a]-px[b])*(px[a]-px[b]) + (py[a]-py[b])*(py[a]-py[b]));
}
double findmax(double x, double y)
{
    return x > y ? x : y;
}

void spfa(int n)
{
    int i, x, y, f, r;
    for(i = 1; i <= n; i++)
    {
        v[i] = 0;   d[i] = INF;
    }
    v[1] = 1; d[1] = 0;
    for(q[f = r = 1] = 1; f <= r; f ++)
    {
        x = q[f];   v[x] = 0;
        for(y = 1; y <= n; y++)
        {
            if(x != y && d[y] > findmax(d[x], map[x][y]))
            {
                d[y] = findmax(d[x], map[x][y]);
                if(!v[y])
                {
                    q[++r] = y; v[y] = 1;
                }
            }
        }
    }
}
int main(void)
{
    int n, i, j, ct = 1;
    while(scanf("%d", &n) && n)
    {
        for(i = 1; i <= n; i++) scanf("%lf%lf", &px[i], &py[i]);

        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)     map[i][j] = dist(i, j);
        spfa(n);
        printf("Scenario #%d\n", ct);
        printf("Frog Distance = %.3f\n\n", d[2]);
    }
    return 0;
}
