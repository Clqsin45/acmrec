#include <stdio.h>
#define lson l, m, rt << 1
#define rson m+1, r, rt<<1|1
#define MAX 100005
__int64 f[MAX << 2], col[MAX << 2];

void pushup(int x)
{
    f[x] = f[x << 1] + f[x << 1 | 1];
    return;
}
void pushdown(int x, int size)
{
    if(col[x])
    {
        col[x << 1] = col[x];
        col[x << 1 | 1] = col[x];
        f[x << 1] += ((size - (size >> 1));
        f[x << 1 | 1] +=  ((size >> 1);
        col[x] = 0;
    }
    return;
}

void modify(int L, int R, __int64 c, int l, int r, int rt)
{
    if( L <= l&& R >= r)
    {
        col[rt] += c;
        f[rt] += ((r - l + 1) * c);
        return;
    }
    pushdown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if(L <= m)  modify(L, R, c, lson);
    if(m < R) modify(L, R, c, rson);
    pushup(rt);
    return;
}
__int64 require(int L, int R, int l, int r, int rt)
{
    if(L <= l && R >= r)
    {
        return f[rt];
    }
     pushdown(rt, r - l + 1);
    int m = (l + r) >> 1;
    __int64 ret = 0;

    if(L <= m)  ret += require(L, R, lson);
    if(R > m)   ret += require(L, R, rson);
    return ret;
}
void build(int l, int r, int rt)
{
    col[rt] = 0;
    if(l == r)
    {
        scanf("%I64d", &f[rt]);
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
    return;
}

int main(void)
{
    int N, Q,st1, st2, i;
    __int64 c;
    char op[10];
    scanf("%d%d", &N, &Q);
    build(1, N, 1);
    for(i = 1; i <= Q; i++)
    {
        scanf("%s", op);
        if(op[0] == 'C')
        {
            scanf("%d%d%I64d", &st1, &st2, &c);
            modify(st1, st2, c, 1, N, 1);
        }
        else if(op[0] == 'Q')
        {
            scanf("%d%d", &st1, &st2);
            printf("%I64d\n", require(st1, st2, 1, N, 1));
        }
    }
    return 0;
}
