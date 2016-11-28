#include <stdio.h>
#include <string.h>
#define MAX 100004
int map[MAX][14], f[14], st[14];
inline int findmax(int x, int y)
{
    return x > y ? x : y;
}
inline int judge(int x)
{
    return x >= 0 && x <= 10;
}
int main(void)
{
    int n, i, j, st1, st2, max;
    while(scanf("%d", &n)&& n)
    {
        memset(map, 0, sizeof(map));

        max = 0;
        for(i = 1; i <= n; i++)
        {
            scanf("%d%d", &st2, &st1);
            map[st1][st2] ++;
            max = findmax(max, st1);
        }
        n = max;

        for(i = 0; i <= 10; i++)
        {
            f[i] = map[n][i];
        }

        for(i = n - 1; i >= 0 ; i--)
        {
            for(j = 0; j <= 10; j++)
            {
                max = 0;
                for(int k = -1; k <= 1; k++)
                {
                    if(judge(j + k))
                        max = findmax(f[j + k], max);
                }
                st[j] = max + map[i][j];
               //printf("f[%d][%d] = %d\n", i, j, f[i][j]);
            }
            for(j = 0; j <= 10; j++)    f[j] = st[j];
        }
        printf("%d\n", f[5]);
    }
    return 0;
}
