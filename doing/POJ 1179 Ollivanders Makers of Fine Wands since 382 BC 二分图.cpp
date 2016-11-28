#include <stdio.h>
#include <string.h>
#define MAX 111
int f[MAX][MAX], match[MAX], m, n;
bool v[MAX];

int dfs(int x)
{
    int i;
    for(i = 1; i <= n; i++)
    {
        if(!v[i] && f[x][i])
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
    int i, st1, ans, t;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        memset(f, 0, sizeof(f));
        memset(match, -1, sizeof(match));
        for(i = 1; i <= m; i++)
        {
            scanf("%d", &t);
            while(t--)
            {
                scanf("%d", &st1);
                f[i][st1] = 1;
            }
        }

        ans = 0;
        for(i = 1; i <= m; i++)
        {
            memset(v, 0, sizeof(v));
            ans += dfs(i);
        }

        printf("%d\n", ans);
    }

    return 0;
}
