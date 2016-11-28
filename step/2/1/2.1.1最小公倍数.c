#include <stdio.h>

int main(void)
{
    int m, n, i, cl;
    while(scanf("%d%d", &m, &n) == 2)
    {
        for(i = 1, cl = m; i <= n; i++, cl += m)
        {
            if(cl % n == 0) break;
        }
        printf("%d\n",cl);
    }
    return 0;
}
