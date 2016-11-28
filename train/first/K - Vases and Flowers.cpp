#include <stdio.h>

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define MAX  50005
#define INF 0x7f7f7f7f

int f[MAX << 2], cl[MAX << 2], fbl[MAX << 2], n;

int min(int x, int y)
{
    return x < y ? x : y;
}

void pushup(int x)
{
    f[x] = f[x << 1] + f[x << 1 | 1];
    fbl[x] = min(fbl[x << 1], fbl[x << 1 | 1]);
    return;
}

void pushdown(int x, int lside, int rside, int mid)
{
    int l = x << 1, r = x << 1 | 1;
    if(cl[x] != -1)
    {
        cl[l] = cl[r] = cl[x];
        if(cl[x])
        {
            f[l] = mid - lside + 1;
            f[r] = rside - mid;
            fbl[l] = fbl[r] = INF;
        }
        else
        {
            f[l] = f[r] = 0;
            fbl[l] = lside; fbl[r] = mid + 1;
        }
        cl[x] = -1;
    }
    return;
}

void build(int l, int r, int rt)
{
    cl[rt] = -1;
    if(l == r)
    {
        fbl[rt] = l;
        f[rt] = 0;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);    build(rson);
    pushup(rt);
    return;
}

void modify(int L, int R, int l, int r, int rt, int k)
{
    //printf("%d  %d\n", l, r);
    if(L <= l && R >= r)
    {
        cl[rt] = k;
        if(k == 1)
        {
            f[rt] = r - l + 1;
            fbl[rt] = INF;
        }
        else
        {
            f[rt] = 0;
            fbl[rt] = l;
        }
        return;
    }
    int m = (l + r) >> 1;
    pushdown(rt, l, r, m);
    if(L <= m)  modify(L, R, l, m, rt << 1, k);
    if(R > m)   modify(L, R, m + 1, r, rt << 1 | 1, k);
    pushup(rt);
    return;
}
int require(int L, int R, int l, int r, int rt)
{
    if(L <= l && R >= r)
        return f[rt];

    int m = (l + r ) >> 1, temp = 0;
    pushdown(rt,l, r, m);

    if(m >= L)  temp += require(L, R, lson);
    if(m < R)  temp += require(L, R, rson);
    return temp;
}

int findst(int L, int R, int l, int r, int rt)
{
    if(L <= l && R >= r)    return fbl[rt];
    int m = (l + r) >> 1, temp = INF;
    pushdown(rt, l, r, m);
    if(L <= m)  temp = min(temp, findst(L, R, lson));
    if(R > m)   temp = min(temp, findst(L, R, rson));
    pushup(rt);
    return temp;
}

int orzpqywgod(int l, int r, int st, int limit)
{
    int m, temp;
    while(l <= r)
    {
        m = (l + r) >> 1;
        temp = require(st, m, 0, n - 1, 1);
        temp = m - st + 1 - temp;
        if(temp >= limit)
            r = m;
        else l = m + 1;
        if(l == r)  break;
    }
    return l;
}
int main(void)
{
    int T, m, st, end;
    int st1, st2, op;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        build(0, n - 1, 1);
        while(m--)
        {
            scanf("%d%d%d", &op, &st1, &st2);
            if(--op)
            {
                printf("%d\n",require(st1, st2, 0, n - 1, 1));
                modify(st1, st2, 0, n - 1, 1, 0);
            }
            else
            {
                op = require(st1, n - 1, 0, n - 1, 1);
                if(op == n - st1)   printf("Can not put any one.\n");
                else
                {
                    end = min(st2, n - st1 - op);
                    st = findst(st1, n - 1, 0, n - 1, 1);
                    end = orzpqywgod(st1, n - 1, st1, end);
                    printf("%d %d\n", st, end);
                    modify(st, end, 0, n - 1, 1, 1);
                }
            }

        }
        printf("\n");
    }
    return 0;
}
