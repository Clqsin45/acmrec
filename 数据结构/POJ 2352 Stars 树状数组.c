#include <stdio.h>
#include <string.h>
int a[32004], c[32003];
int n, max = 32004;

int lowbit(int x)
{
    return x & (-x);
}

int getsum(int x)
{
    int sum = 0;
    for(; x > 0; x -= lowbit(x))
    {
        sum += c[x];
    }
    return sum;
}

void modify(int x, int k)
{
    for(; x <= max; x += lowbit(x))
        c[x] += k;
}
int main(void)
{
    int x, y, i;
    memset(c, 0, sizeof(c));
    memset(a, 0, sizeof(a));
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        scanf("%d%d", &x, &y);
        x++;
        printf("!%d\n", getsum(x));
        a[getsum(x)]++;
        modify(x, 1);
    }
    for(i = 0; i < n; i++) printf("%d\n", a[i]);
    return 0;
}
