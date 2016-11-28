#include <stdio.h>
#include <algorithm>
#include <string.h>
#define INF 20002
using namespace std;

struct point
{
    int v;  int x;
}p[20002];
long long c[20002], t[20002];
int n;
bool cmp(point a, point b)
{
    if(a.v == b.v) return a.x < b.x;
    return a.v < b.v;
}

int lowbit(int x)
{
    return x & (-x);
}
long long getsum(long long *v, int x)
{
    long long sum = 0;
    for(; x > 0; x -= lowbit(x))
        sum += v[x];
    return sum;
}

void modify(long long *v, int x, int k)
{
    for(; x <= INF; x += lowbit(x))
        v[x] += k;
    return;
}
int main(void)
{
    int i;
    long long sum = 0, max = 0, st1, st2;
    scanf("%d", &n);
    memset(c, 0, sizeof(c));
    memset(t, 0, sizeof(t));
    for(i = 1; i <= n; i++)
    {
        scanf("%d%d", &p[i].v, &p[i].x);
    }
    sort(p + 1, p + n + 1, cmp);
    modify(c, p[1].x, 1);
    modify(t, p[1].x, p[1].x);
    max += p[1].x;

    for(i = 2; i <= n; i++)
    {
        modify(c, p[i].x, 1);
        modify(t, p[i].x, p[i].x);
        st1 = getsum(c, p[i].x);
        st2 = getsum(t, p[i].x);
        max += p[i].x;
        sum += p[i].v * (st1 * p[i].x - st2 + max - st2 - p[i].x*(i- st1));
    }
      //  sum += (p[i].v * (getsum(c, p[i].x) * p[i].x - getsum(t, p[i].x) + max - getsum(t, p[i].x) - (i - getsum(c, p[i].x) - 1) * p[i].x));
    printf("%lld\n", sum);

    return 0;
}
