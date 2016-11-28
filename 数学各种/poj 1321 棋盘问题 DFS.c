#include <stdio.h>
#include <string.h>
int n, k, ct, f[10][10], v[10];
char map[10];
void dfs(int x, int s)
{
    int j;
    //printf("x = %d s = %d\n", x, s);
    if(s == k)
    {
        ct++;   return;
    }
    if(x > n)   return;
    for(j = 1; j <= n; j++)
    {
       // printf("x = %d  y = %d  f[x][y] = %d  v[j] = %d\n", x, j, f[x][j], v[j]);
        if(f[x][j] && v[j])
        {
            //printf("x= %d   j = %d \n", x, j);
            v[j] = 0;     dfs(x + 1, s + 1);
            v[j] = 1;
        }
    }
    dfs(x + 1, s);
}

int main(void)
{
    int i, j;
    while(scanf("%d%d", &n, &k))
    {
        if(n == -1 && k == -1)  break;
        memset(f, -1, sizeof(f));
        for(i = 1; i <= n; i++)
        {
            scanf("%s",map + 1);
            for (j = 1; j <= n ; j++)
            {
                if(map[j] == '.')  f[i][j] = 0;
                else f[i][j] = 1;
            }
            v[i] = 1;
        }
        ct = 0;
        dfs(1, 0);
        printf("%d\n",ct);
    }
    return 0;
}
