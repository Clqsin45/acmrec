#include <stdio.h>
#include <algorithm>
using namespace std;

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define MAX 500055

struct point
{
    int val, pos;
}p[MAX];
int f[MAX << 2], num[MAX];

bool cmp(point a, point b)
{
    return a.val < b.val;
}

void pushup(int x)
{
    f[x] = f[x << 1] + f[x << 1 | 1];
}

void build(int l, int r, int rt)
{
    if(l == r)
    {
        f[rt] = 0;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);    build(rson);
    pushup(rt);
    return;
}

void modify(int p, int l, int r, int rt)
{
    if(l == r)
    {
        f[rt]++;    return;
    }
    int m = (l + r) >> 1;
    if(p <= m)  modify(p, lson);
    else modify(p , rson);
    pushup(rt);
    return;
}

int require(int L, int R, int l, int r, int rt)
{
    int ret = 0;
    if(L <= l && R >= r)
    {
        return f[rt];
    }
    int m = (l + r) >> 1;
    if(L <= m)  ret += require(L, R, lson);
    if(m < R)   ret += require(L, R, rson);
    return ret;
}
int main(void)
{
    int n, i;
    long long sum;
    while(scanf("%d", &n) && n)
    {
        sum = 0;
        build(1, n, 1);
        for(i = 1; i <= n ;i++)
        {
            scanf("%d", &p[i].val);
            p[i].pos = i;
        }
        sort(p + 1, p + 1 + n, cmp);
        for(i = 1; i <= n; i++)
        {
            num[p[i].pos] = i;
        }
        for(i = 1; i <= n; i++)
        {

            sum += require(num[i], n, 1, n, 1);
            modify(num[i], 1, n, 1);
        }
        printf("%lld\n", sum);
    }
    return 0;
}
