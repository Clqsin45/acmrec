#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define N 10005
#define M
#define INF 0x3f3f3f3f
#define LL __int64
#define eps 1e-8
struct  point
{
    double x, y;
    point() {};
    point(double xx, double yy):x(xx), y(yy) {};

    double xmul(const point &I)const
    {
        return x*I.y - y*I.x;
    }
    double dmul(const point &I)const
    {
        return x*I.x+y*I.y;
    }
    point operator -(const point& I)const
    {
        return point(x-I.x, y-I.y);
    }
    double dis(const point &I)const
    {
        return sqrt((x-I.x)*(x-I.x) + (y-I.y)*(y-I.y));
    }

}p[N], q[N];
int n, m;
bool cmpp(point a, point b)
{
    if((p[1] - a).xmul(p[1] - b) == 0)   return a.dis(p[1]) < b.dis(p[1]);
    return (p[1] - a).xmul(p[1] - b) > 0;
}
bool cmpq(point a, point b)
{
    if((q[1] - a).xmul(q[1] - b) == 0)   return a.dis(q[1]) < b.dis(q[1]);
    return (q[1] - a).xmul(q[1] - b) > 0;
}

int graham(point *t, int n)
{
    int i, top;
    for(i = 3, top = 2; i <= n; i++)
    {
        while(top >= 2 && ((t[top]-t[top-1]).xmul(t[i]-t[top - 1]) <= 0)) top--;
        t[++top] = t[i];
    }
    t[0] = t[top];
    return top;
}

double ld(point a, point b, point c)
{
    point s(a - b), t(c - b);
    if(s.dmul(t) < eps) return b.dis(c);
    s = b - a;  t = c - a;
    if(s.dmul(t) < eps) return a.dis(c);
    return fabs((b - a).xmul(c - a) / a.dis(b));
}

double ll(point a, point b, point c, point d)
{
    double ans = 1e10;
    ans = min(ld(a, b, c), ld(a, b, d));
    ans = min(ans, ld(c, d, a));    ans = min(ans, ld(c, d, b));
    return ans;
}
double gun(void)
{
    double ans = 1e10;
    int i, j;
    for(i = 0, j = 1; i < n; i++)
    {
        while(!((p[i]-p[i+1]).xmul(q[j]-q[(j-1+m)%m]) < -eps &&
                (p[i]-p[i+1]).xmul(q[(j+1)%m] - q[j]) >= -eps))  j = (j + 1) % m;
        ans = min(ans, ll(p[i], p[i + 1], q[(j - 1 + m) % m], q[j]));
       // printf("%d\n", i);
    }
    return ans;
}

int main()
{
    int  i;
    int temp, ttemp;
    double ans;
    while(scanf("%d%d", &n, &m) && (n || m))
    {
        temp = 0;   p[0].x = 100000;
        for(i = 1; i <= n; i++)
        {
            scanf("%lf%lf", &p[i].x, &p[i].y);
            if(p[i].x < p[temp].x - eps)  temp = i;
            else if(fabs(p[i].x - p[temp].x) < eps && p[i].y < p[temp].y)  temp = i;
        }
        swap(p[temp], p[1]);
        sort(p + 2, p + n + 1, cmpp);

        ttemp = 0;  q[0].x = 100000;
        for(i = 1; i <= m; i++)
        {
            scanf("%lf%lf", &q[i].x, &q[i].y);
            if(q[i].x < q[ttemp].x - eps)  ttemp = i;
            else if(fabs(q[i].x - q[ttemp].x) < eps && q[i].y < q[ttemp].y)  ttemp = i;
        }
        swap(q[ttemp], q[1]);
        sort(q + 2, q + m + 1, cmpq);
        //for(i = 1; i <= m; i++) printf("%f  %f\n", q[i].x, q[i].y);
        //printf("~~~\n");
        n = graham(p, n);  m = graham(q, m);//printf("%d  %d~~\n", n, m);
       // for(i = 0; i < n; i++)  printf("%f  %f\n", p[i].x, p[i].y);
        //for(i = 0; i < m; i++)  printf("%f  %f\n", q[i].x, q[i].y);
        ans = gun();
        printf("%.5f\n", ans);
    }
	return 0;
}
