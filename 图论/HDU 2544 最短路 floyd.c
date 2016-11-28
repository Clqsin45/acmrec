#include <stdio.h>
#include <string.h>
int f[102][102];
void floyd(int n)
{
    int i, j , k;
    for(k = 1; k <= n; k++)
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                if(f[i][j] > f[i][k] + f[k][j]) f[i][j] = f[i][k] + f[k][j];

}
int main(void)
{
    int n, m, i, st1, st2, stt;
    while(scanf("%d%d", &n, &m) && (n || m))
    {
        memset(f, 44, sizeof(f));
        for(i = 1; i <= m; i++)
        {
            scanf("%d%d%d", &st1, &st2, &stt);
            f[st1][st2] = f[st2][st1] = stt;
        }
        floyd(n);
        printf("%d\n",f[1][n]);
    }
    return 0;
}
