#include <stdio.h>
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define MAX 100005
int col[MAX << 2],  f[MAX << 2];

void pushup(int x)
{
    f[x] = f[x << 1] + f[x << 1 | 1];
}

void pushdown(int x, int size)
{
    if(col[x])
    {
        col[x << 1] = col[x << 1 | 1] = col[x];
        f[x << 1] = (size - (size >> 1)) * col[x];
        f[x << 1 | 1] = (size >> 1) * col[x];
        col[x] = 0;
    }
    return;
}
void build(int l, int r, int rt)
{
    f[rt] = 1;  col[rt] = 0;
    if(l == r)  return;
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}

void modify(int L, int R, int k, int l, int r, int rt)
{
    if(L <= l && R >= r)
    {
        col[rt] = k;
        f[rt] = (r - l + 1) * k;
        return;
    }
    pushdown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if(L <= m)  modify(L, R, k, lson);
    if(R > m)   modify(L, R, k, rson);
    pushup(rt);
    return;
}
int main(void)
{
    int n, m, t, i, j, st1, st2, stt;
    scanf("%d", &t);
    for(i  = 1; i <= t; i++)
    {
        scanf("%d%d", &n, &m);
        build(1, n, 1);
        for(j = 1; j <= m; j++)
        {
            scanf("%d%d%d", &st1, &st2, &stt);
            modify(st1, st2, stt, 1, n, 1);
        }
        printf("Case %d: The total value of the hook is %d.\n", i, f[1]);
    }

    return 0;
}
