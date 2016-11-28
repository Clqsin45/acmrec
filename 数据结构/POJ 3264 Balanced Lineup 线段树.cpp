#include <stdio.h>
#define lson l, m, rt << 1
#define rson m + 1, r, rt<<1 |1
#define MAX 55555
#define INF 0x3f3f3f3f
int fax[MAX<<2], fin[MAX<<2];

int max(int x, int y)
{
    return x >  y ?  x : y;
}
int min(int x, int y)
{
    return x < y ? x:y;
}

void pushup(int x)
{
    fax[x] = max(fax[x<<1], fax[x<<1|1]);
    fin[x] = min(fin[x<<1], fin[x<<1|1]);
    return;
}

void build(int l, int r, int rt)
{
    int st;
    if(l == r)
    {
        scanf("%d", &st);
        fax[rt] = fin[rt] = st;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}

int require(int flag, int L, int R, int l, int r, int rt)
{
    if(L <= l && R >= r)
    {
        return (flag ? fax[rt] : fin[rt]);
    }
    int m = (l + r )>>1;
    int st;
    if(flag)
    {
        st = 0;
        if(L <= m)  st = max(st, require(1, L, R, lson));
        if(R > m)   st = max(st, require(1, L, R, rson));
    }
    else
    {
        st = INF;
        if(L <= m)  st = min(st, require(0, L, R, lson));
        if(R > m)   st = min(st, require(0, L, R, rson));
    }
    return st;
}
int main(void)
{
    int n, m, i, st1, st2, mmax, mmin;
    scanf("%d%d",&n, &m);
    build(1, n, 1);
    for(i = 1; i <= m; i++)
    {
        scanf("%d%d", &st1, &st2);
        mmax = require(1, st1, st2, 1, n, 1);
        mmin = require(0, st1, st2, 1, n, 1);
        printf("%d\n", mmax- mmin);
    }
}
