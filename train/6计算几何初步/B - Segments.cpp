#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

#define MAX 105
#define INF 0x3f7f7f7f
#define eps 1e-8

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
}p[2][MAX];
int n;

bool judge(point a, point b)
{
    int i;
    if(fabs(a.x-b.x) < eps && fabs(a.y-b.y)<eps)    return false;
    for(i = 1; i <= n; i++)
        if((a-p[0][i]).xmul(b-p[0][i]) * (a-p[1][i]).xmul(b-p[1][i]) > eps) return false;
    return true;
}

int main(void)
{
    int TC, i, j, k, t;
    bool flag;
    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%d", &n);
        flag = false;
        for(i = 1; i <= n; i++)
        {
            scanf("%lf%lf%lf%lf", &p[0][i].x, &p[0][i].y, &p[1][i].x, &p[1][i].y);
        }
        if(n <= 2)  flag = true;

        for(i = 1; i <= n && !flag; i++)
        {
            for(j = i + 1; j <= n && !flag; j++)
            {
                for(k = 0; k <= 1; k++)
                    for(t = 0; t <= 1; t++)
                        if(judge(p[k][i], p[t][j]))
                        {
                            flag = true;    break;
                        }
            }
        }
        if(flag)    printf("Yes!\n");
        else printf("No!\n");
    }
    return 0;
}
