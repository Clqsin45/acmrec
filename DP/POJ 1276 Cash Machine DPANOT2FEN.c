#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f
int c[12], v[12], f[100002];

int max(int x, int y)
{
    return x > y ? x : y;
}
int main(void)
{
    int n, i, m, j, k, t;
    while(scanf("%d%d", &m, &n) != EOF)
    {
        for(i = 1; i <= n; i++)
        {
            scanf("%d%d", &c[i], &v[i]);
        }
        for(i = 0 ; i<= m; i++) f[i] = 0;
        for(i = 1; i <= n; i++)
        {
            for(j =1; j <= c[i]; j *= 2)
            {
                c[i] -=j;
                for(k = m; k >= j * v[i]; k--)
                {
                    f[k] = max(f[k], f[k - j*v[i]] + j*v[i]);
                }
            }
            t = c[i];
            if(t > 0)
            {
                for(k = m; k >= t * v[i]; k--)
                {
                    f[k] = max(f[k], f[k - v[i]*t] + t*v[i]);
                }
            }
        }
        printf("%d\n", f[m]);
    }
    return 0;
}
