#include <stdio.h>
#include <string.h>
#define MAX 155
int f[MAX][MAX], match[MAX], n;
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
    int i, m, st1, st2, ans, t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        memset(f, 0, sizeof(f));
        memset(match, -1, sizeof(match));
        while(m--)
        {
            scanf("%d%d", &st1, &st2);
            f[st1][st2] = 1;
        }
        ans = 0;
        for(i = 1; i <= n; i++)
        {
            memset(v, false, sizeof(v));
            ans += dfs(i);
        }
        printf("%d\n", n - ans);
    }
    return 0;
}
