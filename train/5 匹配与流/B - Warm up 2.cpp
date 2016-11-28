#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 1004
#define INF 0x3f7f7f7f

struct point
{
    int x, y;
}h[MAX], s[MAX];

int n, m;
int match[MAX], v[MAX], f[MAX][MAX];

bool dfs(int x)
{
    int i;
    for(i = 1; i <= m; i++)
    {
        if(!v[i] && f[x][i])
        {
            v[i] = 1;
            if(match[i] == -1 || dfs(match[i]))
            {
                match[i] = x;
                return true;
            }
        }
    }
    return false;
}

bool judge(int i, int j)
{
    int x, y;
    for(x = 0; x <= 1; x++)
    {
        for(y = 0; y <= 1; y++)
        {
            if(h[i].x + x == s[j].x && h[i].y == s[j].y + y) return true;
        }
    }
    return false;
}

int main(void)
{
    int i, j;
    while(scanf("%d%d", &n, &m) && (n || m))
    {
        memset(f, 0, sizeof(f));
        for(i = 1; i <= n; i++) scanf("%d%d", &h[i].x, &h[i].y);
        for(i = 1; i <= m; i++) scanf("%d%d", &s[i].x, &s[i].y);

        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= m; j++)
            {
                if(judge(i, j))
                    f[i][j] = 1;
            }
        }
        memset(match, -1, sizeof(match));
        int ans = 0;
        for(i = 1; i <= n; i++)
        {
            memset(v, 0, sizeof(v));
            ans += dfs(i);
        }
        printf("%d\n", n + m - ans);
    }
    return 0;

}
