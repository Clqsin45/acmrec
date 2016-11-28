#include <stdio.h>
//…∏∑®«Û÷ 
#define INF 1000004
int a[INF] = {0};
int main(void)
{
    //freopen("out.txt", "w", stdout);
    int i, j, n;
    for(i = 2; i < INF; i++)
    {
        if(i == 2)
        {
            for(j = 4; j < INF; j += 2)
            {
                a[j] = 1;
            }
        }
        else
        {
            for(j = 2 * i ; j < INF; j += i)
            {
                a[j] = 1;
            }
        }
    }
    while(scanf("%d", &n) && n)
    {
        for(i = 2; i < n; i++)
        {
            if(!a[i] && !a[n - i])
            {
                printf("%d = %d + %d\n", n, i, n - i);
                break;
            }
        }
    }

    return 0;
}
