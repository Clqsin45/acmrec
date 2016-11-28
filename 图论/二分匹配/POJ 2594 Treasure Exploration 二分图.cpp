#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 555

int f[MAX][MAX], match[MAX], n;
bool v[MAX];

int dfs(int x)
{
    int i;
    for(i = 1; i <= n; i++)
    {
        if(f[x][i] && !v[i])
        {
            v[i] = true;
            if(match[i] == -1 || dfs(match[i]))
            {
                match[i] = x;
                return 1;
            }
        }

    }
    return 0;
}

void floyd(void)
{
    int i, j, k;
    for(k = 1; k <= n; k++)
    {
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(f[i][k] && f[k][j])  f[i][j] = 1;
            }
        }
    }
}

int main(void)
{
    int m, i, st1, st2, ans;
    while(scanf("%d%d", &n, &m) && (m || n))
    {
        memset(f, 0, sizeof(f));
        while(m--)
        {
            scanf("%d%d", &st1, &st2);
            f[st1][st2] = 1;
        }
        floyd();    ans = 0;
        memset(match, -1, sizeof(match));
        for(i = 1; i <= n; i++)
        {
            memset(v, 0, sizeof(v));
            ans += dfs(i);
        }
        printf("%d\n", n - ans);
    }
    return 0;
}
