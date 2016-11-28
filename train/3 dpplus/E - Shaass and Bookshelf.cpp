#include <stdio.h>
#include <string.h>
#define MAX 111

int f[MAX * 2];
struct book
{
    int v, c;
}w[MAX];

inline int findmax(int x, int y)
{
    return x > y ? x : y;
}
int main(void)
{
    int i, j, n, sum = 0;
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        scanf("%d%d", &w[i].v, &w[i].c);
        w[i].c += w[i].v;
        sum += w[i].v;
    }
    for(i = 1; i <= n; i++)
    {
        for(j = sum; j >= w[i].c; j--)
        {
            f[j] = findmax(f[j], f[j - w[i].c] + w[i].v);
        }
    }
    printf("%d\n", sum - f[sum]);
    return 0;
}
