#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N
#define M
#define LL __int64
#define INF 0x3f7f7f7f


int main(void)
{
    int i, n, a, sum, TC, tc, ans, st, end, ts;
    scanf("%d", &TC);
    for(tc = 1; tc <= TC; tc++)
    {
        if(tc > 1)  printf("\n");
        scanf("%d", &n);    sum = 0;
        ans = -INF; ts = 1;
        for(i = 1; i <= n; i++)
        {
            scanf("%d", &a);    sum += a;
            if(ans < sum)
            {
                ans = sum;
                st = ts;
                end = i;
            }
            if(sum < 0)
            {
                ts = i + 1;
                sum = 0;
            }

        }
        printf("Case %d:\n", tc);
        printf("%d %d %d\n", ans, st, end);
    }
    return 0;
}
