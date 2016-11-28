#include <stdio.h>
#define MAX 1000008
__int64 s[MAX] = {0};
int main(void)
{
    int  x, y, i;
    __int64 ans, total, n, m, sum = 0;
    scanf("%I64d%I64d", &n, &m);
    while(m--)
    {
        scanf("%d%d", &x, &y);
        s[x] ++;    s[y] ++;
    }
    if(n >= 3) ans = n * (n - 1) * (n - 2) / 6;     //总共可以组成这么多个。。排列组合 cn3
    else n = 0;
    for(i = 1; i <= n; i++)
    {
        sum += s[i] * (n - 1 - s[i]);     //对于任意一个点， 都有n - 1条边连出 在m图中的边*不在m中的边即为该点的边组成的非同色角个数
    }
    sum /= 2;      //每条边被计算了两次
    ans -= sum;
    printf("%I64d\n", ans);
    return 0;
}
