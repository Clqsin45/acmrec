#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 22
#define M 1804
#define LL __int64
#define INF 0x3f7f7f7f
LL dp[N][N][M];
int dig[N];

LL dfs(int len, int pot, int sum, bool reac)
{
    if(!len)    return !sum;
    if(sum < 0) return 0;


    if(!reac &&  dp[len][pot][sum] != -1)   return   dp[len][pot][sum];
    int i, m = reac ? dig[len] : 9;
    LL ans = 0;
    for(i = 0; i <= m; i++)
    {
        ans += dfs(len - 1, pot, sum + i * (len - pot), reac && i == m);
    }
    if(!reac)   dp[len][pot][sum] = ans;
    return ans;
}
LL f(LL x)
{
    int no = 0, i;
    LL ans = 0;
    while(x)
    {
        dig[++no] = x % 10;
        x /= 10;
    }

    for(i = 1 ; i <= no; i++)
    {
        ans += dfs(no, i, 0, 1);
    }//printf("%I64d\n", ans);
    return ans - no + 1;
}
int main(void)
{
    LL x, y;
    int TC;
    memset(dp, -1, sizeof(dp));
    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%I64d%I64d", &x, &y);
        printf("%I64d\n", f(y) - f(x - 1));
    }
    return 0;
}
