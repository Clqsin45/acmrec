#include <stdio.h>
#include <string.h>
int map[102][102], f[102][102];
int n, m, gox[4] = {-1, 0, 1, 0}, goy[4] = {0, 1, 0, -1};
int dfs(int x, int y)
{
    int i, max = 0, xx, yy;
    if(f[x][y] != -1)   return f[x][y];
    for(i = 0; i < 4; i++)
    {
        xx = x + gox[i];    yy = y + goy[i];
        if(map[xx][yy] < map[x][y] && xx >= 1 && yy >= 1 && xx <= m && yy <= n)
        {
            if(f[xx][yy] == -1)     f[xx][yy] = dfs(xx, yy);
            if(max < f[xx][yy]) max = f[xx][yy];
        }
    }
    f[x][y] = max + 1;
    return f[x][y];
}
int main(void)
{
    int i, j, max = 0;
    scanf("%d%d", &m, &n);
    memset(f, -1, sizeof(f));
    for(i = 1; i <= m; i++)
    {
        for(j = 1; j <= n; j ++)
        {
            scanf("%d",&map[i][j]);
        }
    }
    for(i = 1; i <= m; i++)
    {
        for(j = 1; j <= n; j++)
        {
            f[i][j] = dfs(i, j);
            if(f[i][j] > max)   max = f[i][j];
        }
    }
    printf("%d\n", max);
    return 0;
}
