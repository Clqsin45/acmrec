#include <stdio.h>
#include <string.h>
#define NT 3404
int w[NT], v[NT], f[128806], n, m;
int findmax (int a, int b)
{
    return a > b ? a :b;
}
int main(void)
{
    int i, j;
    scanf("%d%d", &n, &m);
    for(i = 1; i <= n; i++)
    {
        scanf("%d%d", &w[i], &v[i]);
    }
    for(i = 0; i <= m; i++) f[i] = 0;
    for(i = 1; i <= n; i++)
    {
        for(j = m; j >= w[i]; j--)
        {
            f[j] = findmax(f[j], f[j - w[i]] + v[i]);
        }
    }
    printf("%d\n", f[m]);
    return 0;
}
