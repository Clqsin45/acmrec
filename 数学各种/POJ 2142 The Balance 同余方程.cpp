#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define N
#define M
#define INF 0x3f3f3f3f
#define LL __int64

int exgcd(int a, int b, int &x, int &y)
{
    if(!b)  {x = 1; y = 0; return a;}
    int r = exgcd(b, a % b, x, y), t = x;
    x = y;  y = t - a / b * y;
    return r;
}


int main(void)
{
    int a, b, d, x, y, e, t, temp;
    int xx, yy, fx, fy;
    int test;
    while(scanf("%d%d%d", &a, &b, &d) &&(a || d))
    {
        t = exgcd(a, b, x, y);
        temp = d / t;
        x *= temp;  y *= temp;

        a /= t; b /= t;   d /= t;

        xx = (x % b + b) % b;   yy = (d - a * xx) / b;  if(yy < 0)  yy = -yy;
        fy = (y % a + a) % a;   fx = (d - b * fy) / a;  if(fx < 0)  fx = -fx;
        if(xx + yy < fx + fy)
        {
            printf("%d %d\n", xx, yy);
        }
        else if(xx + yy == fx + fy)
        {
            printf("%d %d\n", xx * a + yy * b < fx * a + fy * b ? xx, yy: fx, fy);
        }
        else printf("%d %d\n", fx, fy);
    }
	return 0;
}
