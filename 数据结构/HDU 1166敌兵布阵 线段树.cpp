#include <stdio.h>
#define lson l, m, rt << 1
#define rson m + 1, r, (rt << 1) + 1
#define MAX 55555
int sum[MAX<<2];

void pushup(int x)
{
    sum[x] = sum[x << 1] + sum[(x << 1)+ 1];
    return;
}

void build(int l, int r, int rt)
{
    if(l == r)
    {
        scanf("%d", &sum[rt]);
        return;
    }
    int m =(l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}

int require(int L, int R, int l, int r, int rt)
{
    if(L <= l && R >= r)
    {
        return sum[rt];
    }
    int ret = 0;
    int m = ((l + r) >> 1 );
    if(L <= m)  ret += require(L, R, lson);
    if(R > m)   ret += require(L, R, rson);
    return ret;
}

void modify(int p, int k, int l, int r, int rt)
{
    if(l == r)
    {
        sum[rt] += k;
        return;
    }
    int m = ((l + r ) >> 1);
    if(p <= m) modify(p, k, lson);
    else modify(p, k, rson);
    pushup(rt);
}
int main(void)
{
    int i, T, st1, st2, n;
    char op[10];
    scanf("%d\n", &T);
    for(i  =1; i <= T; i++)
    {
        printf("Case %d:\n", i);
        scanf("%d", &n);
        build(1, n, 1);         //×ó ÓÒ ROOT
        while(scanf("%s", op))
        {
            if(op[0] == 'E')    break;
            if(op[0] == 'Q')
            {
                scanf("%d%d", &st1, &st2);
                printf("%d\n", require(st1, st2, 1, n, 1));
            }
            else if(op[0] == 'S')
            {
                scanf("%d%d", &st1, &st2);
                modify(st1, -st2, 1, n, 1);
            }
            else
            {
                scanf("%d%d", &st1, &st2);
                modify(st1, st2, 1, n, 1);
            }
        }
    }
    return 0;
}
