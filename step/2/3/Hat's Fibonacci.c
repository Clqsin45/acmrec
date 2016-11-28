#include <stdio.h>
#include <string.h>

int a[5][10000];
int main(void)
{
    char op[10], s[10];
    int l, i, j, n, d, sign;
    while(scanf("%d", &n)!= EOF)
    {
        if(n <= 4)
        {
            printf("1\n");
            continue;
        }
        d = 0;  memset(a, 0, sizeof(a));
        a[0][0] = a[1][0] = a[2][0] = a[3][0] = 1;
        for(i = 5; i <= n; i++)
        {
            sign = 0;
            for(j = 0; j <= d; j++)
            {
                a[i % 4][j] = a[0][j] + a[1][j] + a[2][j] + a[3][j] + sign;
                sign = a[i % 4][j] / 10;
                a[i % 4][j] %= 10;
            }
            if(sign > 0)
            a[i % 4][++d] = sign;
        }
        for(i = d; i >= 0; i--)
            printf("%d", a[n % 4][i]);
        printf("\n");

    }
    return 0;
}
