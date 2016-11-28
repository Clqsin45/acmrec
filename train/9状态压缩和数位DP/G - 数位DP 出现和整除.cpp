#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 14
#define M
#define LL __int64
#define INF 0x3f7f7f7f

int dp[N][N][2][2], dig[N];

int dfs(int len, int mod, bool app, bool pre, bool reac)
{
    if(!len)
    {
        return app && mod == 0;
    }
    if(!reac && dp[len][mod][app][pre] != -1)   return dp[len][mod][app][pre];
    int ct = 0, m = reac ? dig[len] : 9, i, mmd;
    for(i = 0; i <= m; i++)
    {
        mmd = (mod * 10 + i) % 13;
        ct += dfs(len - 1, mmd, app || (pre && i == 3), i == 1, reac && i == m);
    }
    if(!reac) dp[len][mod][app][pre] = ct;
    return ct;
}

int f(int n)
{
    int no = 0;
    while(n)
    {
        dig[++no] = n % 10;
        n /= 10;
    }
    return dfs(no, 0, 0, 0, 1);
}
int main(void)
{
    int n;
    memset(dp, -1, sizeof(dp));
    while(scanf("%d", &n) != EOF)
    {
        printf("%d\n", f(n));
    }
    return 0;
}
