#include <stdio.h>
#include  <stdlib.h>
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define MAX 50005
#define LL long long

const long long INF = 0x15B000000LL;

struct water
{
    int day, cost;
}w[MAX];

LL f[MAX << 2], dp;
int n;


LL min(LL x, LL y)
{
    return x < y ? x : y;
}

void pushup(int x)
{
    f[x] = min(f[x << 1], f[x << 1 | 1]);
}

LL require(int L, int R, int l, int r, int rt)
{
    if(L <= l && R >= r)
        return f[rt];
    int m = (l + r) >> 1;

    LL temp = INF;
    if(L <= m) temp = min(temp, require(L, R, lson));
    if(R > m) temp = min(temp, require(L, R, rson));
    return temp;

}

void modify(int p, LL k, int l, int r, int rt)
{
    if(l == r)
    {
        f[rt] = k;
        return;
    }
    int m = (l + r) >> 1;

    if(p <= m)  modify(p, k, lson);
    else modify(p, k, rson);
    pushup(rt);

    return;
}
void build(int l, int r, int rt)
{
    f[rt] = INF;
    if(l == r)
        return;
    int m = (l + r) >> 1;
    build(lson);    build(rson);
    return;
}

int main(void)
{
    int i;

    while(scanf("%d", &n) != EOF)
    {
        for(i = 1; i <= n; i++)
            scanf("%d", &w[i].cost);
        for(i = 1; i <= n; i++)
            scanf("%d", &w[i].day);
        build(1, n, 1);


        for(i = n; i >= 1; i--)
        {
            dp = (i + w[i].day > n) ? w[i].cost : w[i].cost + require(i + 1, i + w[i].day, 1, n, 1);
            //printf("%d   %lld\n", i, dp[i]);
            modify(i, dp, 1, n, 1);
        }

        printf("%lld\n", dp);

    }
    return 0;
}
