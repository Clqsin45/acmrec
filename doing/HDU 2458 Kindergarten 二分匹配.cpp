#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAX 222
#define INF 0x7f7f7f7

int f[MAX][MAX], match[MAX];
bool v[MAX];
int g, b;

bool dfs(int x)
{
    int i;
    for(i = 1; i <= b; i++)
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
    int TC = 1, m, st1, st2, i, j;
    while(scanf("%d%d%d", &g, &b, &m) && (g || b || m))
    {

        memset(match, -1, sizeof(match));
        for(i = 1; i <= g; i++)
            for(j = 1; j <= b; j++)
                f[i][j] = 1;
        while(m--)
        {
            scanf("%d%d", &st1, &st2);
            f[st1][st2] = 0;
        }
        int ans = 0;
        for(i = 1; i <= g; i++)
        {
            memset(v, 0, sizeof(v));
            ans += dfs(i);
        }
        printf("Case %d: %d\n", TC++, g + b - ans);
    }
    return 0;
}
