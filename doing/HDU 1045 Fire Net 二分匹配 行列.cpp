#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define M 20
#define INF 0x7f7f7f7
int xc, xy;
char map[6][6];
int xline[6][6], yline[6][6], f[6][6];
int v[M], match[M];
bool dfs(int x)
{
    int i;
    for(i = 1; i <= xy; i++)
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
    int n, i, j, flag;
    while(scanf("%d", &n) && n)
    {
        memset(match, -1, sizeof(match));
        memset(f, 0, sizeof(f));
        xc = xy = 0;
        for(i = 1; i <= n; i++)
        {
            scanf("%s", map[i] + 1);
            for(j = 1; j <= n; j++)
            {
                if(map[i][j] == 'X')
                    xline[i][j] = yline[i][j] = -1;
            }
        }
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                while(map[i][j] == 'X' && j <= n)   j++;
                xc ++;
                while(map[i][j] != 'X' && j <= n)   xline[i][j++] = xc;
            }
        }

        for(j = 1; j <= n; j++)
        {
            for(i = 1; i <= n; i++)
            {
                while(map[i][j] == 'X' && i <= n)   i++;
                xy ++;
                while(map[i][j] != 'X' && i <= n)   yline[i++][j] = xy;

            }
        }
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
                if(xline[i][j] != -1 && yline[i][j] != -1)
                    f[xline[i][j]][yline[i][j]] = 1;
        }
        int ans = 0;
        for(i = 1; i <= xc; i++)
        {
            memset(v, 0, sizeof(v));
            ans += dfs(i);
        }
        printf("%d\n", ans);
    }
    return 0;
}
