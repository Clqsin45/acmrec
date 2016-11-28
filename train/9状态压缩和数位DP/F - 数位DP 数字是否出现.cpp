#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 10
#define M
#define LL __int64
#define INF 0x3f7f7f7f

int dp[N][2], dig[N];

int dfs(int len, bool pre, bool reac)
{
    if(!len)    return 1;
    if(!reac && dp[len][pre] != -1)  return dp[len][pre];
    int ct = 0, m = reac ? dig[len] : 9, i;
    for(i = 0; i <= m; i++)
    {
        if(i == 4 || (pre && i == 2))   continue;
        ct += dfs(len - 1, i == 6, reac && (i == m));
    }
    if(!reac)   dp[len][pre] = ct;
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
    return dfs(no, 0, 1);
}

int main(void)
{
    int n, m;
    while(scanf("%d%d", &n, &m) && (n || m))
    {
        memset(dp, -1, sizeof(dp));
        printf("%d\n", f(m) - f(n - 1));
    }
    return 0;
}
