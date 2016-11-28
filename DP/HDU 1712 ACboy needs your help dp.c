#include <stdio.h>
#include <string.h>
int f[102], d[102][102];
int max(int x, int y)
{
    return x > y ? x : y;
}
int main(void)
{
    int i, j , k, m, n;
    while(scanf("%d%d", &n, &m))
    {
        if(!n && !m) break;
        for(i = 1; i <= n ; i++)
            for(j = 1; j <= m ; j++)    scanf("%d",&d[i][j]);
        memset(f, 0 ,sizeof(f));

        for(i = 1; i <= n; i++)
        {
            for(j = m; j >0; j--)
            {
                for(k = 1; k <= m ; k++)
                {
                    if(j - k >= 0)  f[j] = max(f[j], f[j-k] + d[i][k]);
                }
            }
        }
        printf("%d\n", f[m]);
    }
    system("pause");
    return 0;
}
