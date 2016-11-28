#include <stdio.h>
#define lson l, m,  rt << 1
#define rson m + 1, r, rt << 1 | 1
#define MAX 5555
int f[MAX << 2], num[MAX];

void pushup(int x)
{
    f[x] = f[x << 1] + f[x << 1 | 1];
}

void build(int l, int r, int rt)
{
    if(l == r)
    {
        f[rt] = 0;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
    return;
}

int require(int L, int R, int l, int r, int rt)
{
    int ret = 0;
    if(L <= l && R >= r)
    {
        return f[rt];
    }
    int m = (l + r) >> 1;
    if(L <= m)  ret += require(L, R, lson);
    if(R > m)   ret += require(L, R, rson);
    return ret;
}

void modify(int p, int l, int r, int rt)
{
    if(l == r)
    {
        f[rt] ++;
        return;
    }
    int m = (l + r) >> 1;
    if(p <= m)  modify(p, lson);
    else modify(p, rson);
    pushup(rt);
}

int min(int x, int y)
{
    return x < y ? x : y;
}
int main(void)
{
    int n, sum, ans, i;
    while(scanf("%d", &n) != EOF)
    {
        build(0, n-1, 1);
        sum = 0;
        for(i = 0; i <n ;i ++)
        {
            scanf("%d", &num[i]);
            sum+= require(num[i], n-1, 0, n-1, 1);
            modify(num[i], 0, n-1, 1);
        }
        ans = sum;
        for(i = 0 ; i < n; i++)
        {
            sum += (n - num[i]);
            sum -= (num[i] + 1);
            ans = min(sum, ans);
        }
        printf("%d\n", ans);

    }
    return 0;
}
