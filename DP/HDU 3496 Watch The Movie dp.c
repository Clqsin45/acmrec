#include <stdio.h>
#define MIN -1000000000

int d[102], c[102], f[102][1002];

int max(int x, int y)
{
    return x > y ? x : y;
}

int main(void)
{
    int t, n, m , tl, i, j, k;
    scanf("%d", &t);
    while(t --)
    {
        scanf("%d%d%d", &n, &m,&tl);
        for(i = 1; i <= n; i++)     scanf("%d%d", &c[i], &d[i]);
        for(i = 0; i <= m; i++)
            for(j = 0; j <= tl; j++)
            {
                if(i == 0)  f[i][j] = 0;
                else        f[i][j] = MIN;
			}
        for(i = 1; i <= n ; i++)
        {
           for(j = m; j >= 1; j--)
           {
               for(k = tl; k >= c[i]; k--)
               {
                   if(f[j - 1][k - c[i]] != MIN)   f[j][k] = max(f[j -1][k - c[i]] + d[i], f[j][k]);
               }
           }
        }
        if(f[m][tl] == MIN) printf("0\n");
        else printf("%d\n",f[m][tl]);
    }
    system("pause");
    return 0;
}
