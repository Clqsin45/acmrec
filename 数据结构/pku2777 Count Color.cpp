#include <stdio.h>
#define lson l, m, rt << 1
#define rson m+1, r, rt<<1 | 1
#define MAX 100040
int cl[MAX << 2], f[MAX << 2], ret = 0;

void pushup(int x)
{
    f[x] = (f[x<<1] | f[x<<1|1]);
    return;
}
void pushdown(int x)
{
    if(cl[x])
    {
        f[x<<1] = f[x]; f[x<<1|1] = f[x];
        cl[x<<1] = 1;   cl[x<<1|1] = 1;
        cl[x] = 0;
    }
    return;
}

void build(int l, int r, int rt)
{
    cl[rt] = 1;
    if(l == r)
    {
        f[rt] = 1;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
    return;
}

void modify(int L, int R, int c, int l, int r, int rt)
{
    if(L <= l && R >= r)
    {
        f[rt] = c;  cl[rt] = 1;
        return;
    }
    if(f[rt] == c) return;
    int m = (l + r) >> 1;
    pushdown(rt);
    if(L <= m)  modify(L, R, c, lson);
    if(R > m)   modify(L, R, c, rson);
    pushup(rt);
    return;

}

void require(int L, int R, int l, int r, int rt)
{
    if(cl[rt] == 1)
    {
        ret |= f[rt];   return;
    }
    if(L <= l && R >= r)
    {
        ret |= f[rt];
        return;
    }
    int m = (l + r) >> 1;

    if(L <= m)  require(L, R, lson);
    if(R > m)  require(L, R, rson);
    pushdown(rt);
}
int main(void)
{
    int L, T, N, st, ct = 0, i, st1, st2, stt;
    char op[10];
    scanf("%d%d%d", &L, &T, &N);
    build(1, L, 1);
    for(i = 1; i <= N; i++)
    {
        scanf("%s", &op);
        if(op[0] == 'C')
        {
            scanf("%d%d%d", &st1, &st2, &stt);
            modify(st1, st2, 1<<(stt-1), 1, L, 1);

        }
        else
        {
            scanf("%d%d", &st1, &st2);
            ret = 0;    ct = 0;
            require(st1, st2, 1, L, 1);
            st = ret;
            while(st)
            {
                if(st % 2)  ct++;
                st /= 2;
            }
            printf("%d\n", ct);
        }
    }
    return 0;
}
