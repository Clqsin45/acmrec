#include <stdio.h>
#include <string.h>
int main(void)
{
    int a, t, n, m, ans;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        m = n % 10;
        ans = 1;
        for(;n; n>>= 1)
        {
            if(n & 1) ans = ans * m % 10;
            m = m*m % 10;
        }
        printf("%d\n",ans);
    }

    return 0;
}
