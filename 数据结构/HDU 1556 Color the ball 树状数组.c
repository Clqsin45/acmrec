#include <stdio.h>
#include <string.h>
int n;
int c[100002];

int lowbit(int x)
{
    return x & (-x);
}
int getsum(int x)
{
    int sum = 0;
    for(; x > 0; x -= lowbit(x))
        sum += c[x];
    return sum;
}

void modify(int x, int k)
{
    for(; x <= n; x += lowbit(x))
        c[x] += k;
}
int main(void)
{
    int a, b ,i;
    while(scanf("%d", &n) && n)
    {
        memset(c, 0, sizeof(c));
        for(i = 1; i <= n; i++)
        {
            scanf("%d%d", &a, &b);
            modify(a, 1);
            modify(b + 1, -1);
        }
        for(i = 1; i < n; i++)
            printf("%d ",getsum(i));
        printf("%d\n", getsum(n));
    }
    return 0;
}
