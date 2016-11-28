#include <stdio.h>
#include <string.h>
#include <math.h>
#define INF 1000002
int a[INF] = {0};
int main(void)
{
    //freopen("output.txt", "w", stdout);
    int i, j, st, x, k, n;
    a[1] = 1;
    st = sqrt(INF);
    for(i = 2; i <= st + 1; i++)
    {
        for(j = 2 * i; j <= INF; j += i)
        {
            a[j] = 1;
        }
    }
   // for(i = 1; i <= 10000; i++)
        // printf("%d  %d\n", i, a[i]);
    while(scanf("%d%d%d", &x, &k ,&n) && (x + k + n))
    {

        for(i = x; i < INF; i += k)
        {
            //printf("%d  %d\n", i, a[i]);
            if(!a[i])  n--;
            if(n == 0)  break;
        }
        printf("%d\n", i);
    }
    return 0;
}
