#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 25
#define M
#define LL __int64
#define INF 0x3f7f7f7f

LL dp[N][2][2];
int dig[N];

LL dfs(int len, bool app, bool pre, bool reac)
{
    if(!len)     return app;
    if(!reac && dp[len][app][pre] != -1)    return dp[len][app][pre];
    LL ct = 0;
    int i, m = reac ? dig[len] : 9;
    for(i = 0 ; i <= m; i++)
    {
        ct += dfs(len - 1, app || (pre && i == 9), i == 4, reac && i == m);
    }
    if(!reac)   dp[len][app][pre] = ct;
    return ct;
}

LL f(LL x)
{
    int no = 0, i;
    while(x)
    {
        dig[++no] = x % 10; x /= 10;
    }
    return dfs(no, 0, 0, 1);
}

int main(void)
{
    int TC;
    LL x;
    scanf("%d", &TC);
    memset(dp, -1, sizeof(dp));
    while(TC--)
    {
        scanf("%I64d", &x);
        printf("%I64d\n", f(x));
    }
    return 0;
}
