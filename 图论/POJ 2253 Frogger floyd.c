#include <stdio.h>
#include <string.h>
#include <math.h>
double map[202][202], px[202], py[202];

double dist(int a, int b)
{
    return sqrt((px[a]-px[b])*(px[a]-px[b]) + (py[a]-py[b])*(py[a]-py[b]));
}
double findmax(double x, double y)
{
    return x > y ? x : y;
}

void floyd(int n)
{
    int i, j, k;
    for(k = 1; k <= n; k++)
    {
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(map[i][j] > findmax(map[i][k], map[k][j]))
                    map[i][j] = findmax(map[i][k], map[k][j]);
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
            for(j = 1; j <= n; j++)
                map[i][j] = dist(i, j);


        floyd(n);


        printf("Scenario #%d\n", ct);
        printf("Frog Distance = %.3f\n\n", map[1][2]);
        ct++;
    }
    return 0;
}
