#include <stdio.h>
#include <string.h>

int ans[50][5005], l[50];
int main(void)
{
    int n, base, st, i, j;
    while(scanf("%d%d", &base, &n) && (n || base))
    {
        if(n == 0)
        {
            printf("1\n");
            continue;
        }
        memset(ans, 0, sizeof(ans));
        ans[0][0] = 1; l[0] = 0;
        for(i = 1; i <= n; i++)
        {
            for(j = 0; j <= l[i-1]; j++)
            {
                ans[i][j] = base*ans[i-1][j];
            }
            st = (l[i - 1]+1) * base;
            for(j = 0; j <= st;j++)
            {
                ans[i][j +1] += ans[i][j]/10;
                ans[i][j] %= 10;
            }
            while(ans[i][st] == 0 && st >= 0)
            {
                st--;
            }
            l[i] = st;
        }

        for(i = l[n]; i >= 0; i--)
        {
            printf("%d",ans[n][i]);
        }
        printf("\n");
    }
    return 0;
}
