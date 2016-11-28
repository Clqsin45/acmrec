#include <stdio.h>
#include <string.h>
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define MAXN 10050
int k;
int f[15][MAXN << 2], cl[MAXN << 2],need[15];


int max(int x, int y)
{
    return x > y ? x : y;
}

void pushdown(int rt)
{
    int i;
    if(cl[rt])
    {
        cl[rt << 1] += cl[rt];
        cl[rt << 1 | 1] += cl[rt];
        for(i = 1; i <= k; i++)
        {
            if(f[i][rt << 1] != -1)  f[i][rt << 1] += cl[rt] * i;
            if(f[i][rt << 1 | 1] != -1) f[i][rt << 1 | 1] += cl[rt] * i;
        }
        cl[rt] = 0;
    }
}
void pushup(int rt)
{
    int i;
    for(i = 1; i<= k; i++)
    {
        f[i][rt] = max(f[i][rt << 1], f[i][rt<<1|1]);
    }
}
void levelup(int i, int l, int r, int rt)
{

    if(l == r)
    {
        while(i < k)
        {
            if(f[i][rt] < need[i])  break;
            f[i + 1][rt] = f[i][rt];
            f[i][rt] = -1;
            i++;
        }
        return;
    }
    pushdown(rt);
    int m = (l + r) >> 1;
    if(f[i][rt << 1] >= need[i])    levelup(i, lson);
    if(f[i][rt << 1 | 1] >= need[i])levelup(i, rson);
    pushup(rt);
}

void modify(int L, int R, int c, int l, int r, int rt)
{
    int i;
    if(L <= l && R >= r)
    {
        cl[rt] += c;
        for(i = k; i >= 1; i--)
        {
            if(f[i][rt] != -1)  f[i][rt] += c * i;
            if(i < k && f[i][rt] >= need[i])    levelup(i, l, r, rt);
        }
        return;
    }
    pushdown(rt);
    int m = (l + r) >> 1;
    if(L <= m)  modify(L, R, c, lson);
    if(R > m)   modify(L ,R, c, rson);
    pushup(rt);
}

int require(int L, int R, int l, int r, int rt)
{
    int i;
    if(L <= l && R >= r)
    {
        for(i = k; i >= 1; i--)
        {
            if(f[i][rt] != -1)  return f[i][rt];
        }
    }
    pushdown(rt);
    int m = (l + r) >> 1;
    int ret = 0;
    if(L <= m)  ret = max(ret, require(L, R, lson));
    if(R > m)   ret = max(ret, require(L, R, rson));
    pushup(rt);
    return ret;
}
int main(void)
{
    int t, cs, i, st1, st2, stt, n, qw;
    char op[10];
    scanf("%d", &t);
    for(cs = 1; cs <= t; cs++)
    {
        scanf("%d%d%d", &n, &k, &qw);
        for(i = 1; i < k; i++)  scanf("%d", &need[i]);
        memset(cl, 0, sizeof(cl));
        memset(f, -1, sizeof(f));   memset(f[1], 0, sizeof(f[1]));
        printf("Case %d:\n", cs);
        while(qw--)
        {
            scanf("%s", op);
            if(op[0] == 'W')
            {
                scanf("%d%d%d", &st1, &st2, &stt);
                modify(st1, st2, stt, 1, n, 1);
            }
            else
            {
                scanf("%d%d", &st1, &st2);
                int p = require(st1, st2, 1, n, 1);
                printf("%d\n", p);
            }
        }
        printf("\n");
    }
    return 0;
}
