#include <stdio.h>
#include <string.h>
#define MAX 100002
int b[12], r[12], f[MAX];

int max(int x, int y)
{
    return x > y ? x : y;
}
int main(void)
{
    int t , n, y, tt, i , j, k;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &tt, &y);
        scanf("%d", &n);
        for(i = 1; i <= n; i++)
        {
            scanf("%d%d", &b[i], &r[i]); b[i] /= 1000;
        }

        for(i = 1; i <= y; i++)
        {
            for(j = 0; j <= MAX; j++ ) f[j] = 0;
            for(j = 1; j <= n ; j++)
            {

                for(k = b[j]; k <= (tt / 1000); k++)
                {
                    f[k] = max(f[k] , f[k - b[j]] + r[j]);
                }
            }
            tt = f[tt/1000] + tt;
        }
        printf("%d\n", tt);
    }

    system("pause");
    return 0;
}
