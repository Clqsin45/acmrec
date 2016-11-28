#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define lson l, m, rt << 1
#define rson  m + 1, r, rt << 1 | 1
#define MAX 10005
int lside[MAX], rside[MAX], ct;
int cl[MAX << 4], a[MAX<<2], flag[MAX];

void pushdown(int rt)
{
    if(cl[rt])
    {
        cl[rt << 1] = cl[rt << 1 | 1] = cl[rt];
        cl[rt] = 0;
    }
}

void require(int l, int r, int rt)
{
    if(cl[rt])
    {
        if(!flag[cl[rt]])
            ct ++;
        flag[cl[rt]] =1;
        return;
    }
    if(l == r)  return;
    int m = (l + r) >> 1;
    require(lson);
    require(rson);
}
void modify(int L, int R, int k, int l, int r, int rt)
{
    if(L <= l && R >= r)
    {
        cl[rt] = k; return;
    }
    pushdown(rt);
    int m = (l + r) >> 1;
    if(L <= m)  modify(L, R, k, lson);
    if(R > m)   modify(L, R, k, rson);
    return;
}

int find(int x, int n)
{
    int l = 0,  r = n - 1;
    while(l <= r)
    {
        int m = (l + r) >> 1;
        if(a[m] == x)   return m;
        if(a[m] < x)    l = m + 1;
        else r = m - 1;
    }
    return -1;
}
int main(void)
{
    int t, n, i, no, m, x, y;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        m = 0;
        for(i = 1; i <= n; i++)
        {
            scanf("%d%d", &lside[i], &rside[i]);
            a[m++] = lside[i];
            a[m++] = rside[i];
        }
        sort(a, a + m);
        for(i = 1, no = 1; i < m; i++)
        {
            if(a[i] != a[i-1])  a[no++] = a[i];
        }
        for(i = no - 1; i > 0; i--)
        {
            if(a[i] != a[i - 1] + 1)    a[no++] = a[i - 1] + 1;
        }
        sort(a, a + no);
        memset(cl, 0, sizeof(cl));
        for(i = 1; i <= n; i++)
        {
            x = find(lside[i], no);
            y = find(rside[i], no);
            modify(x, y, i, 0, no - 1, 1);
        }
        ct = 0;
        memset(flag, 0, sizeof(flag));
        require(0, no - 1, 1);
        printf("%d\n", ct);
    }
    return 0;
}
