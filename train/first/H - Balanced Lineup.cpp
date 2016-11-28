#include <stdio.h>

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define MAX 50005
#define INF 0x7f7f7f7f

int fmax[MAX << 2], fmin[MAX << 2];
int max(int x, int y)
{
    return x > y ? x : y;
}

int min (int x, int y)
{
    return x < y ? x : y;
}

void pushup(int rt)
{
    fmax[rt] = max(fmax[rt << 1], fmax[rt << 1 | 1]);
    fmin[rt] = min(fmin[rt << 1], fmin[rt << 1 | 1]);
    return;
}

void build(int l, int r, int rt)
{
    int m = (l + r) >> 1, temp;
    if(l == r)
    {
        scanf("%d", &temp);
        fmax[rt] = fmin[rt] = temp;
        return;
    }
    build(lson);    build(rson);
    pushup(rt);
    return;
}

int require(int flag, int L, int R, int l, int r, int rt)
{
    if(L <= l && R >= r)    return (flag ? fmax[rt] : fmin[rt]);

    int m = (l + r) >> 1, temp;
    if(flag)
    {
        temp = 0;
        if(L <= m)  temp = max(temp, require(flag, L, R, lson));
        if(R > m)   temp = max(temp, require(flag, L, R, rson));
    }
    else
    {
        temp = INF;
        if(L <= m)  temp = min(require(flag, L, R, lson), temp);
        if(R > m)   temp = min(require(flag, L, R, rson), temp);
    }
    return temp;

}

int main(void)
{
    int n, m, i, st1, st2, tmax, tmin;
    scanf("%d%d", &n, &m);
    build(1, n, 1);
    while(m--)
    {
        scanf("%d%d", &st1, &st2);
        tmax = require(1, st1, st2, 1, n, 1);
        tmin = require(0, st1, st2, 1, n, 1);
        printf("%d\n", tmax - tmin);
    }
    return 0;
}
