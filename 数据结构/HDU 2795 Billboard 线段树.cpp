#include <stdio.h>
#define lson l, m, rt << 1
#define rson m+1, r, rt << 1 | 1
#define MAX 200004
int f[MAX << 2];

int max(int x, int y)
{
    return x > y ? x : y;
}

void pushup(int x)
{
    f[x] = max(f[x << 1], f[x << 1 | 1]);
}
void build(int l, int r, int rt, int k)
{
    if(l == r)
    {
        f[rt] = k;
        return;
    }
    int m = (l + r) >> 1;
    build(lson, k);
    build(rson, k);
    pushup(rt);
    return;
}
int require(int p, int l, int r, int rt)
{
    if(l == r)
    {
        f[rt] -= p;
        return l;
    }
    int m = (l + r) >> 1;
    int ret;
    ret = (f[rt << 1] >= p ? require(p, lson) : require(p, rson));
    pushup(rt);
    return ret;
}
int main(void)
{
    int h, w, n, t, i;
    while(scanf("%d%d%d", &h, &w, &n) != EOF)
    {
        if(h > n) h = n;
        build(1, h, 1, w);
        for(i = 1; i <= n; i++)
        {
            scanf("%d", &t);
            if(f[1] < t)    printf("-1\n");
            else printf("%d\n", require(t, 1, h, 1));
        }
    }
    return 0;
}
