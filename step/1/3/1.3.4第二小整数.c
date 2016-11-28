#include <stdio.h>

int main(void)
{
    int t, n, a[100], i, j, tp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d", &n);
        for(i = 1; i <= n; i++) scanf("%d", &a[i]);
        for(i = 1; i <= n ;i ++)
        {
            for( j = 1; j <= n - i; j++)
            if(a[j] > a[j + 1])
            {
                tp = a[j];   a[j] = a[j + 1]; a[j + 1] = tp;
            }
        }
        printf("%d\n",a[2]);
    }
    return 0;
}
