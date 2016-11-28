#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

#define N 104
#define M
#define LL __int64
#define eps 1e-9
const double INF = 1000000000000.0;
struct point
{
    double x, y;
    double dis(const point &I)const
    {
        return sqrt((x-I.x)*(x-I.x) + (y-I.y)*(y-I.y));
    }
}p[N];
int n;
double d[N], f[N][N], ans;
bool v[N];

bool prim()
{
    int i, j, temp;
    double now; ans = 0;
    for(i = 1; i <= n; i++)
    {
        d[i] = f[1][i]; v[i] = false;
    }
    v[1] = true;    d[1] = 0;
    for(i = 1; i < n; i++)
    {
        now = INF;  temp = -1;
        for(j = 1; j <= n; j++)
        {
            if(!v[j] && now > d[j])
            {
                temp = j;   now = d[j];
            }
        }
        //printf("%f\n", now);
        if(temp == -1)  return false;
        ans += now; v[temp] = true;
        for(j = 1; j <= n; j++)
        {
            if(!v[j] && d[j] > f[temp][j])
                d[j] = f[temp][j];
        }
    }
    return true;
}
int main(void)
{
    int TC, i, j;
    double temp;
    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%d", &n);

        for(i = 1; i <= n; i++)
            scanf("%lf%lf", &p[i].x, &p[i].y);
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                temp = p[i].dis(p[j]);
                if(temp >= 10 - eps && temp <= 1000 + eps)  f[i][j] = temp;
                else f[i][j] = INF;
            }
        }

        if(prim())  printf("%.1f\n", ans * 100);
        else printf("-1\n");
    }
    return 0;
}
