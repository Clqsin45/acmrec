#include <stdio.h>
#include <string.h>

#define MAX 505
int w[MAX], h[MAX], l[MAX], v[MAX], match[MAX], n;
int f[MAX][MAX];

inline int cmp(int x, int y)
{
    return w[x] > w[y] && l[x] > l[y] && h[x] > h[y];
}
int dfs(int x)
{
    int i;
    for(i = 1; i <= n; i++)
    {
        if(f[x][i] && !v[i])
        {
            v[i] = 1;
            if(match[i] == -1 || dfs(match[i]))
            {
                match[i] = x;
                return 1;
            }
        }
    }
    return 0;
}
int main(void)
{
    int i, j, ans;
    while(scanf("%d", &n) && n)
    {
        for(i =  1; i <= n; i++)
        {
            scanf("%d%d%d", &w[i], &l[i], &h[i]);
            match[i] = -1;
        }
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                f[i][j] = 0;
                if(cmp(i, j))
                    f[i][j] = 1;
            }
        }
        ans = 0;
        for(i = 1; i <= n; i++)
        {
            memset(v, 0, sizeof(v));
            ans += dfs(i);
        }
        printf("%d\n", n - ans);
    }

}
