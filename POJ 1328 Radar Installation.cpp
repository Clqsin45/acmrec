#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
struct point
{
    double min, max, x, y;
}p[1004];
bool cmp(point a, point b)
{
    if(a.x == b.x) return a.y > b.y;
    return a.x < b.x;
}
int main(void)
{
    //freopen("in.txt", "r", stdin);
    int n, i, ct, sign, t = 1;
    double d, st = -10000, temp;
    while(scanf("%d%lf", &n, &d))
    {
        ct = 0;     st = -10000;
        sign = 1;
        if(n == 0 && d == 0) break;
        for(i = 1; i <= n; i++)
        {
            scanf("%lf%lf",&p[i].x, &p[i].y);
            if(d < p[i].y)  sign = 0;
            if(sign)
            {
                temp = sqrt(d*d - p[i].y*p[i].y);
                p[i].min = p[i].x - temp;
                p[i].max = p[i].x + temp;
            }
        }
        sort(p + 1, p + n + 1, cmp);
        for(i = 1; i <= n; i++)
        {
            if(st < p[i].min )
            {
                ct ++;
                st = p[i].max;
            }
            else
                st = (p[i].max < st ? p[i].max : st);
        }
        if(!sign)    printf("Case %d: -1\n", t);
        else printf("Case %d: %d\n",t, ct);
        t++;
    }
    return 0;
}
