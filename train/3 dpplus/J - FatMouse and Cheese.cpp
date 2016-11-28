#include <stdio.h>
#include <string.h>
#define MAX  111
int m[MAX][MAX], f[MAX][MAX], n, k;
int gox[4] = {0, 1, 0, -1}, goy[4] = {1, 0, -1, 0};
bool inmap(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= n;
}
int dfs(int x, int y)
{
    int i, j, xx, yy, max, temp;
    if(f[x][y]) return f[x][y];
     max = 0;
    for(i = 1; i <= k; i++)
    {

        for(j = 0; j < 4; j++)
        {
            xx = x + gox[j] * i;    yy = y + goy[j] * i;
            if(!inmap(xx, yy)) continue;

            if(m[xx][yy] > m[x][y])
            {
                temp = dfs(xx, yy);
                max = max > temp ? max : temp;
            }
        }
    }
    f[x][y] = max + m[x][y];
    //printf("f[%d][%d] = %d\n", x, y, f[x][y]);
    return f[x][y];
}
int main(void)
{
    int i, j;
    while(scanf("%d%d", &n, &k) && (n != -1 && k != -1))
    {
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                scanf("%d", &m[i][j]);
                f[i][j] = 0;
            }
        }
        f[1][1] = dfs(1, 1);
        printf("%d\n", f[1][1]);
    }
    return 0;
}
