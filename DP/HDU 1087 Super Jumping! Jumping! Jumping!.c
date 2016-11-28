#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f
int f[1002], num[1002];
int main(void)
{
    int n, i, j, max, ans = 0;
    while(scanf("%d", &n) && n)
    {
        for(i = 1; i <= n; i++) scanf("%d", &num[i]);
        f[0] = -INF;   ans = 0;
        for(i = 1; i <= n; i++)
        {
            f[i] = num[i];  max = 0;
            for(j = 1; j < i; j++)
            {
                if(num[j] < num[i] && f[j] > max)
                    max = f[j];
            }
            f[i] += max;
            if(f[i] > ans)  ans = f[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}
