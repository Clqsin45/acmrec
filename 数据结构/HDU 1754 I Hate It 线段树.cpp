#include <stdio.h>
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define MAX 200005
int f[MAX << 2];

int max(int x, int y)
{
    return x > y ? x : y;
}
void pushup(int x)
{
    f[x] = max(f[x << 1], f[x<<1|1]);
}

int require(int L, int R, int l, int r, int rt)
{
    if(L <= l && R >= r)
    {
        return f[rt];
    }
    int ret = 0;
    int m = (l + r) >> 1;
    if(L <= m) ret = max(ret, require(L, R, lson));
    if(R > m)   ret = max(ret, require(L, R, rson));
    return ret;
}
void modify(int p, int k, int l, int r, int rt)
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
}
void build(int l, int r, int rt)
{
    if(l == r)
    {
        scanf("%d\n", &f[rt]);
        return;
    }
    int m = (l  + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}
int main(void)
{
    int N, M, i, st1, st2;
    char op[10];
    while(scanf("%d%d", &N, &M) != EOF)
    {
        build(1, N, 1);
        for(i = 1; i<= M; i++)
        {
            scanf("%s%d%d", op, &st1, &st2);
            if(op[0] == 'U')
            {
                modify(st1, st2, 1, N, 1);
            }
            else
            {
                printf("%d\n", require(st1, st2, 1, N, 1));
            }
        }
    }
    return 0;
}
