#include <stdio.h>
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define MAX 200004

struct people
{
    int no, name;
}p[MAX];
int f[MAX << 2], record[MAX];

void pushup(int x)
{
    f[x] = f[x << 1] + f[x<< 1 | 1];
}
void build(int l, int r, int rt)
{
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
void modify(int p, int k, int l, int r, int rt)
{
    if(l == r)
    {
        f[rt] = 0;
        record[l] = k;
        return;
    }
    int m = (l + r) >> 1;
    if(p < f[rt << 1])  modify(p, k, lson);
    else modify(p - f[rt << 1], k, rson);
    pushup(rt);

}
int main(void)
{
    int n, i;
    while(scanf("%d", &n) != EOF)
    {
        build(0 , n - 1, 1);
        for(i = 0; i < n; i++)
        {
            scanf("%d%d", &p[i].no, &p[i].name);
        }
        for(i = n - 1; i >= 0; i--)
        {
            modify(p[i].no, p[i].name, 0, n - 1, 1);
        }
        for(i = 0; i < n; i++)
        {
            printf("%d%c", record[i], (i < (n-1)? ' ':'\n'));
        }
    }
    return 0;
}
