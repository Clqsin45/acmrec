#include <stdio.h>
#include <string.h>
int map[102][102],  f[102][102];

int main(void)
{
    int t, i, n, j;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= i; j++)
            {
                scanf("%d", &map[i][j]);
                if(i == n)  f[i][j] = map[i][j];
            }
        }
        for(i = n - 1; i >= 1; i--)
        {
            for(j = 1; j <= i; j++)
            {
                f[i][j] = (f[i + 1][j] > f[i + 1][j + 1] ? f[i + 1][j] : f[i + 1][j + 1]) + map[i][j];
            }
        }
        printf("%d\n", f[1][1]);
    }
    return 0;
}
