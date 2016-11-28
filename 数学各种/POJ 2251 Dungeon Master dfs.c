#include <stdio.h>
#include <math.h>

#define MAX 10000000
int map[34][34][34] = {-1}, l, m, n, min;
int gox[10] = {0,0,0, 1, 0, -1}, goy[10] = {0, 0, 1, 0, -1, 0}, got[10] = {1, -1, 0,0,0,0};

void bfs(int t, int x , int y, int s)
{
    int i
    if (map[t][x][y] == 2)
    {
        if(min > (s + 1))   min = s + 1;
        return;
    }
    for(i = 0; i < 6; i++)
    {
        if(f[])
    }
}
int main(void)
{
    int i, j, k, sl, sx, sy;
    char mp[33];
    while(scanf("%d%d%d", &l, &m, &n) && (m || n || l))
    {
        for(i = 1; i <= l; i++)
        {
            for(j = 1; j <= m; j++)
            {
                scanf("%s",mp + 1);
                for(k = 1; k <= n; k++)
                {
                    if(mp[k] == 'S')
                    {
                        sl = i; sx = j; sy = k;
                    }
                    else if(mp[k] == 'E')   map[i][j][k] = 2;
                    else if(mp[k] == '#')  map[i][j][k] = 0;
                    else map[i][j][k] = 1;
                }
            }
        }
        memset(map, -1, sizeof(map));
        min = MAX;
        bfs(sl, sx, sy, 0);
        if(min == MAX)  printf("Trapped!\n");
        else printf("Escaped in %d minute(s).\n", min);


    }
    return 0;
}
