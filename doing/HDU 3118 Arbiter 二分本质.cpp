#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 20
#define INF 0x3f7f7f7f
int f[MAX][MAX], n, m;
int flag[MAX];
int main(void)
{
    //printf("%d\n", (-3) / 3);
    int TC, i, j, k, x, y, now, ans, all, temp;
    scanf("%d", &TC);
    while(TC--)
    {
        memset(f, 0, sizeof(f));
        scanf("%d%d", &n, &m);

        for(i = 1; i <= m; i++)
        {
            scanf("%d%d", &x, &y);
            if(x > y)   swap(x, y);
            f[x][y] ++; //¥¶¿Ì÷ÿ±ﬂ
        }
        if(n == 0)
        {
            printf("0\n");  continue;
        }
        all = (1 << n);
        ans = INF;
        for(i = 0; i < all; i++)
        {
            memset(flag, 0, sizeof(flag));
            temp = 0;

            for(j = 0; j < n; j++)
            {
                now = (i & (1 << j));
                if(now) flag[j] = 1;
            }

            for(j = 0; j < n; j++)
            {
                for(k = j + 1; k < n; k++)
                {
                    if(flag[j] == flag[k])  temp += f[j][k];
                }
            }
            ans = min(ans, temp);
        }
        printf("%d\n", ans);
    }
    return 0;
}
