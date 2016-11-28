#include <stdio.h>
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define mm int m = (l + r) >> 1
#define MAX 150000
int lsum[MAX << 2], rsum[MAX << 2], msum[MAX << 2];
int num[MAX];

int min(int x, int y)
{
    return x < y ? x : y;
}

int max(int x, int y)
{
    return x > y ? x : y;
}

void pushup(int l, int r, int rt)
{
    lsum[rt] = lsum[rt << 1];
    rsum[rt] = rsum[rt << 1 | 1];
    mm;
    msum[rt] = max(msum[rt << 1], msum[rt << 1| 1]);
    if(num[m] < num[m + 1])
    {
        if(lsum[rt] == m - l + 1)   lsum[rt] += lsum[rt << 1 | 1];
        if(rsum[rt] == r - m)       rsum[rt] += rsum[rt << 1];
        msum[rt] = max(msum[rt], lsum[rt << 1 | 1] + rsum[rt << 1]);
    }

}

void build(int l, int r, int rt)
{
    if(l == r)
    {
        lsum[rt] = rsum[rt] = msum[rt] = 1;
        return;
    }
    mm;
    build(lson);
    build(rson);
    pushup(l, r, rt);
}

void modify(int p, int v, int l, int r, int rt)
{
    if(l == r)
    {
        num[p] = v; return;
    }
    mm;
    if(p <= m) modify(p, v, lson);
    else modify(p, v, rson);
    pushup(l, r, rt);
}

int require(int L, int R, int l, int r, int rt)
{
    if(L <= l && R >= r)
    {
        return msum[rt];
    }
    mm;
    int ret = 0;
    if(L <= m) ret = max(ret, require(L, R, lson));
    if(m < R)   ret = max(ret, require(L, R, rson));
    if(num[m] < num[m + 1])
    {
        ret = max(ret, min(m - L + 1 , rsum[rt << 1]) + min(R - m, lsum[rt << 1 | 1]));
    }
    return ret;
}
int main(void)
{
    int t, n, m, i, st1, st2, p;
    char op[10];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        for(i = 1; i <= n; i++) scanf("%d", &num[i]);
        build(1, n, 1);
        while(m--)
        {
            scanf("%s%d%d", op, &st1, &st2);
            if(op[0] == 'Q')
            {
                p = require(st1 + 1, st2 + 1, 1, n, 1);
                printf("%d\n", p);
            }
            else modify(st1 + 1, st2, 1, n, 1);
        }
    }
    return 0;
}
