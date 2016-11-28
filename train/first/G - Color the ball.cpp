#include <stdio.h>
#include <string.h>

#define MAX 100002
int n, c[MAX];

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
    int x, y,i;
    while(scanf("%d", &n) && n)
    {
        memset(c, 0, sizeof(c));
        for(i = 1; i <= n; i++)
        {
            scanf("%d%d", &x, &y);
            modify(x, 1);
            modify(y + 1, -1);
        }
        for(i = 1; i <= n; i++)
            printf("%d%c",getsum(i), i == n ? '\n': ' ');
    }
    return 0;
}
