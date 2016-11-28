#include <stdio.h>
#include <math.h>
#include <string.h>
#define INF 100000
double f[202][202], d[202], px[202],py[202];
int v[202];

double dist(int a, int b)
{
    return sqrt((px[a]-px[b])*(px[a]-px[b]) + (py[a]-py[b])*(py[a]-py[b]));
}
double findmax(double a, double b)
{
    return a>b?a:b;
}
void dijkstra(int  n)
{
    int i, j ,st;
    double min;
    memset(v, 0, sizeof(v));
    for(i = 1; i <=n ; i++) d[i] =f[1][i];
    d[1] = 0;   v[1] = 1;
    for(i = 1; i <= n; i++)
    {
        min = INF; st = 1;
        for(j = 1; j <= n ; j++)
        {
            if(!v[j] && d[j] < min)
            {
                st = j; min = d[j];
            }
        }
        v[st] = 1;
        if(st == 2) return;
        for(j = 1; j <= n; j++)
        {
            if(!v[j] && d[j] > findmax(d[st],f[st][j]) )
            {
                d[j] = findmax(d[st],f[st][j]);
            }
        }
    }
}
int main(void)
{
    int n, j, i, ct = 1;
    while(scanf("%d", &n) && n)
    {
        for(i = 1; i <= n ; i++)    scanf("%lf%lf", &px[i], &py[i]);
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n ; j++)
            {
                f[i][j] = dist(i, j);
            }

        dijkstra(n);
        printf("Scenario #%d\n", ct);
        printf("Frog Distance = %.3f\n\n", d[2]);
        ct++;
    }
    return 0;
}
