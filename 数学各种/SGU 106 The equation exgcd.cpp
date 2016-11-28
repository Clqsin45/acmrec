#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

#define N
#define M
#define LL __int64
#define INF 0x3f7f7f7f

LL exgcd(LL a, LL b, LL &x, LL &y)
{
    if(!b)  {x = 1; y = 0; return a;}
    LL r = exgcd(b, a % b, x, y), t = x;
    x = y;  y = t - a / b * y;
    return r;
}
void change(LL &a, LL &b, LL &c)
{
    a = -a; b = -b; c = -c;
}
void update(LL &a, LL &t1, LL &t2)
{
    if(a < 0)
    {
        change(a, t1, t2);
        swap(t1, t2);
    }
}
int main(void)
{
    LL a, b, c, x1, x2, y1, y2, ans, x, y, t;
    LL kmax, kmin;
    scanf("%I64d%I64d%I64d", &a, &b, &c);
    scanf("%I64d%I64d%I64d%I64d", &x1, &x2, &y1, &y2);

    if(a == 0 && b == 0)
    {
        if(c == 0)  ans = (x2 - x1 + 1) * (y2 - y1 + 1);
        else ans = 0;
    }
    else if(a == 0 && b != 0)
    {
        if(c % b == 0 && c / b >= y1 && c / b <= y2)       ans = x2 - x1 + 1;
        else ans = 0;
    }
    else if(a != 0 && b == 0)
    {
        if(c % a == 0 && c / a >= x1 && c / a <= x2)       ans = y2 - y1 + 1;
        else ans = 0;
    }
    else
    {
        c = -c;
        if(c < 0)
        {
            change(a, b, c);
        }
        update(a, x1, x2);
        update(b, y1, y2);

        t = exgcd(a, b, x, y);
        if(c % t)   ans = 0;
        else
        {
            a /= t; b /= t; c /= t;
            x *= c; y *= c;

            //printf("%I64d  %I64d\n", x, y);
            kmin = max(ceil((double)(x1 - x) / b), ceil((double)(y - y2) / a));
            kmax = min(floor((double)(x2 - x)/ b), floor((double)(y - y1) / a));
            if(kmax < kmin) ans = 0;
            else ans = kmax - kmin + 1;
        }
    }
    printf("%I64d\n", ans);
    return 0;
}
