#include <stdio.h>
#include <string.h>
int a[204];
int main(void)
{
    int t, n, st, end, i, j, max, temp;
    scanf("%d", &t);
    while(t--)
    {
        memset(a, 0, sizeof(a));
        scanf("%d", &n);    max = 0;
        for(i = 1; i <= n; i++)
        {
            scanf("%d%d",&st, &end);
            if(st > end)
            {
                temp = st;  st = end; end = temp;
            }
            for(j = (st + 1) / 2 ; j <= (end + 1) / 2; j++)
            {
                a[j]++;
                if(max < a[j]) max = a[j];
            }
        }
        printf("%d\n", max * 10);
    }
    return 0;
}
