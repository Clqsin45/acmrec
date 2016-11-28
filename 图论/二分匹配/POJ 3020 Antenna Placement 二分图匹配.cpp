#include <stdio.h>
#include <string.h>
#define MAX 55
char map[MAX][20];
int f[MAX * 20][MAX * 20] = {0}, v[MAX * 20], match[MAX * 20], num[MAX][20];
int ct, m, n, gox[5] = {0, 0, 1, 0, -1}, goy[5] = {0, 1, 0, -1, 0};

int dfs(int x)
{
    int i;
    for(i = 1; i <= ct; i++)
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
    int t, i, j, k, x, y, ans;
    scanf("%d", &t);
    while(t--)
    {
        memset(f, 0, sizeof(f));

        scanf("%d%d", &m, &n);
        ct = 0;
        for(i = 1; i <= m; i++)
        {
            scanf("%s",map[i] + 1);
            for(j = 1; j <= n; j++)
            {
                if(map[i][j] == '*')    num[i][j] = ++ct;
            }
        }
        for(i = 1; i <= m; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(map[i][j] == 'o')    continue;
                for(k = 1; k <= 4; k++)
                {
                    x = i + gox[k];
                    y = j + goy[k];
                    if(map[x][y] == '*')
                        f[ num[i][j] ][ num[x][y] ] = 1;
                }
            }
        }
        memset(match, -1, sizeof(match));
        ans = 0;
        for(i = 1; i <= ct; i++)
        {
            memset(v, 0, sizeof(v));
            if(dfs(i))  ans ++;
        }
        printf("%d\n", ct - ans / 2);

    }
    return 0;
}
