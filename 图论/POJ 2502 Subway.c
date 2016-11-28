#include <stdio.h>
#include <string.h>
#include <math.h>
#define INF 1000000002
int v[402], bl[402];
double x[402], y[402], d[402], f[402][402];
double v1 = 40000.0/60.0, v2 = 10000.0/60.0;
double min( double a, double b)
{
    return a < b ? a : b;
}
double cal(int a, int b)
{
    return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}

void dijkstra(int n)
{
    int i, j, st;
    double min;
    for(i = 1; i <= n; i++)
    {
        v[i] = 0;
        d[i] = INF;
    }
    d[1] = 0;
    for(i = 1; i <= n; i++)
    {
        st = 0; min = INF;
        for(j = 1; j <= n; j++)
        {
            if(!v[j] &&  min > d[j])
            {
                st = j;
                min = d[j];
            }
        }
        v[st] = 1;
        for(j = 1; j <= n;j ++)
        {
            if(!v[j] && d[j] > min + f[st][j])
                d[j] = min + f[st][j];
        }
    }
}
int main(void)
{
    int i= 1, j =1, st= 1, bg, k;
    double sum;
    for(i = 0; i < 302; i++)
    {
        for(j = 0; j < 302; j++)
            f[i][j] = INF;
    }
    i = 1;

    scanf("%lf%lf\n", &x[i], &y[i]);
    i++;
    bl[1] =-1; bl[2] = -2;
    scanf("%lf%lf", &x[i], &y[i]);
    i++;

    while(scanf("%lf%lf", &x[i], &y[i]) != EOF)
    {

        bl[i] = st;  i++;
        while(scanf("%lf%lf", &x[i] ,&y[i]))
        {
            if(x[i] == -1 && y[i] == -1)    break;
            bl[i] = st;
            if(bl[i] == bl[i-1])  f[i][i - 1] = f[i - 1][i] = min(cal(i, i - 1) / v1, f[i][i-1]);
            i++;
        }
        st++;
    }
    for(j = 1; j < i; j++)
    {
        for(k = 1; k < i ;k ++)
        {
                f[j][k] = min(cal(j, k) /v2, f[j][k]);
        }
    }
    dijkstra(i-1);
    printf("%.0f\n", d[2]);
    return 0;
}
