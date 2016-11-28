#include <stdio.h>
#include <string.h>
#define MAX 555
int f[MAX][MAX], match[MAX], nx, ny;
bool v[MAX];

int dfs(int x)
{
    int i;
    for(i = 1; i <= ny; i++)
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
    int k, i, st1, st2, ans;
    while(scanf("%d", &k) && k)
    {
        memset(f, 0, sizeof(f));
        scanf("%d%d", &nx, &ny);
        while(k--)
        {
            scanf("%d%d", &st1, &st2);
            f[st1][st2] = 1;
        }
        ans = 0;
        memset(match, -1, sizeof(match));
        for(i = 1; i <= nx; i++)
        {
            memset(v, false, sizeof(v));
            ans += dfs(i);
        }
        printf("%d\n", ans);
    }
    return 0;
}
