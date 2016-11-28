#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

#define MAX 80
#define eps 1e-10
#define INF 0x3f7f7f7f

struct point
{
    double x, y;
    point(){};
    point(double xx, double yy) : x(xx), y(yy) { };
    double xmul(const point &I)const
    {
        return x*I.y - y*I.x;
    }
    point operator -(const point& I)
    {
        return point(x-I.x, y-I.y);
    }
    double dis(const point &I)  const
    {
        return sqrt((x-I.x)*(x-I.x)+(y-I.y)*(y-I.y));
    }
}p[MAX], lin[2][MAX];

double d[MAX][MAX];

void init(int n)
{
    int i, j;
    for(i = 0; i <= n; i++)
        for(j = 0; j <= n; j++)
            d[i][j] = 1000000000;
    p[0]=point(0, 5);   p[n] = point(10, 5);
}

double floyd(int n)
{
    int i, j, k;
    for(k = 0; k <= n; k++)
        for(i = 0; i <= n; i++)
            for(j = 0; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    return d[0][n];
}

bool judge(point a, point b, point s, point e)
{
    if((fabs(a.x-s.x)< eps) || (fabs(b.x - s.x) < eps))
        {//printf("~~~%.2f  %.2f  %.2f %d %d\n", a.x, b.x, s.x, fabs(a.x-s.x)<eps, (fabs(b.x < s.x) < eps));
        return false;}
    point x(b - a), y(e - s);
    printf("%f  %f\n", x.xmul(s-a))
    return (x.xmul(s-a)*x.xmul(e-a) < eps && y.xmul(a-s)*y.xmul(b-s) < eps);
}

int main(void)
{
    int n, i, temp, j, k;
    double x, y[6];
    bool flag;
    y[0] = 0;   y[5] = 10;
    while(scanf("%d", &n) && (n != -1))
    {
        temp = n * 4 + 1;   init(temp);
        for(i = 0; i < n; i++)
        {
            scanf("%lf", &x);
            for(j = 1; j <= 4; j++)
            {
                scanf("%lf", &y[j]);
               // printf("%d  %lf\n", i, y[i]);
                p[i * 4 + j] = point(x, y[j]);
            }
            for(j = 0; j <= 5; j++)
            {
                lin[j&1][i*3+j/2] = point(x, y[j]);
               //printf("lin[%d][%d] = x= %f   y= %f \n", j&1, i*3+j/2,lin[j&1][i*3+j/2].x, lin[j&1][i*3+j/2].y);
            }
        }

        for(i = 0; i <= temp; i++)
        {
            for(j = i + 1; j <= temp; j++)
            {
                flag = true;
                for(k = 0; k < n*3; k++)
                {
                    if(judge(p[i], p[j], lin[0][k], lin[1][k]))  {
                        printf("!!!%d  %d  %d\n", i, j, k);
                        flag = false; break;
                    }
                }
                 if(flag)   {
                //     printf("!!!\n");
                    printf("%d  %d\n", i, j);
                    d[i][j] = d[j][i] = p[i].dis(p[j]);}
            }

        }

        printf("%.2f\n", floyd(temp));
    }
    return 0;
}

