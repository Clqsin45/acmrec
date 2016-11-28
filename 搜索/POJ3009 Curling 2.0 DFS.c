#include <stdio.h>
#include <string.h>
#define MAX 2147483647
int map[22][22];
int n, m, min;

void dfs(int x, int y, int step)
{
    int i;
    if(step > 10)   return;
    for(i = x + 1; i <= m; i++)
    {
        //printf("1:%d    %d",i,y);   system("pause");
        if(i == x + 1 && map[i][y] == 1)  break;
        if(map[i][y] == 3 && step < min)
        {
            min = step;
            return;
        }
        if(map[i][y] == 1&& step < min)
        {
            map[i][y] = 0;  dfs(i - 1, y, step+1);
            map[i][y] = 1;    break;
        }
    }
    for(i = x - 1; i >= 1; i--)
    {
        //printf("2:%d   %d",i,y);system("pause");
        if(i == x - 1 && map[i][y] == 1)  break;
        if(map[i][y] == 3 && step < min)
        {
            min = step;
            return;
        }
        if(map[i][y] == 1 && step < min)
        {
            map[i][y] = 0;  dfs(i + 1, y, step+1);
            map[i][y] = 1;    break;
        }
    }
    for(i = y + 1; i <= n; i++)
    {
        //printf("3:%d   %d   step%d",x,i,step);system("pause");
        if(i == y + 1 && map[x][i] == 1)  break;
        if(map[x][i] == 3 && step < min)
        {
            min = step;
            return;
        }
        if(map[x][i] == 1 && step < min)
        {
            map[x][i] = 0;  dfs(x, i - 1, step + 1);
            map[x][i] = 1;    break;
        }
    }
    for(i = y - 1; i >= 1; i--)
    {
        //printf("4:%d   %d",x,i);system("pause");
        if(i == y - 1 && map[x][i] == 1)  break;
        if(map[x][i] == 3 && step < min)
        {
            min = step;
            return;
        }
        if(map[x][i] == 1 && step < min)
        {
            map[x][i] = 0;  dfs(x, i + 1, step+1);
            map[x][i] = 1;    break;
        }
    }
}
int main(void)
{
    int i, j, sx, sy;
    while(scanf("%d%d", &n, &m) && m && n)
    {
        memset(map, -1, sizeof(map));
        for(i = 1; i <= m; i++)
        {
            for(j = 1; j <= n; j++)
            {
                scanf("%d", &map[i][j]);
                if(map[i][j] == 2)
                {
                    sx = i; sy = j;
                    map[i][j] = 0;
                }
            }
        }

        min = MAX;
        dfs(sx, sy, 1);
        if(min == MAX) printf("-1\n");
        else printf("%d\n", min);

    }

    return 0;
}
