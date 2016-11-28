#include <stdio.h>
#include <string.h>
#define MAX 55
#define MAXD 1000
char map[MAX][MAX];
bool v[MAXD];
int cx[MAX][MAX], cy[MAX][MAX], match[MAXD], f[MAXD][MAXD] = {0};
int nx, ny, m, n;

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
    int i, j, ans;
    scanf("%d%d", &m, &n);
    nx = 0; ny = 0;
    for(i = 1; i <= m; i++)
        scanf("%s", map[i] + 1);
    for(i = 1; i <= m; i++)
    {
        j = 1;
        while(j <= n)
        {
            if(map[i][j] == '*')
            {
                nx ++;
                while(map[i][j] <= '*')
                {
                    cx[i][j] = nx;
                    j++;
                }
            }
            else j++;
        }
    }
    for(i = 1; i <= n; i++)
    {
        j = 1;
        while(j <= m)
        {
            if(map[j][i] == '*')
            {
                ny ++;
                while(map[j][i] == '*')
                {
                    cy[j][i] = ny;
                    j++;
                }
            }
            else j++;
        }
    }
    for(i = 1; i <= m; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(map[i][j] == '*')
            {
                f[cx[i][j]][cy[i][j]] = 1;
            }
        }
    }
    ans = 0;
    memset(match, -1, sizeof(match));
    for(i = 1; i <= nx; i++)
    {
        memset(v, 0, sizeof(v));
        ans += dfs(i);
    }
    printf("%d\n", ans);
    return 0;
}
