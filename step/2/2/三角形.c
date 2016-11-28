#include <stdio.h>

__int64 a[10004];
int main(void)
{
    int t, n, i;

    scanf("%d", &t);
    while(t--)
    {
        a[0] = 0; a[1] = 2; a[2] = 8;
        scanf("%d", &n);
        if(n <= 2)
        {
            printf("%d\n",a[n]);
            continue;
        }
        for(i = 3; i <= n; i++)
        {
            a[i] = a[i - 1] + 6 * (i - 1);
        }
        printf("%I64d\n", a[n]);
    }
    return 0;
}
