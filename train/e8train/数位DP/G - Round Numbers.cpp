#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 40
#define M
#define LL __int64
#define INF 0x3f7f7f7f

int dp[N][N][N], dig[N], sum;

int dfs(int len, int ein, int nul,  bool reac)
{
    if(!len)
    {
        return nul >= ein;
    }

    if(!reac && dp[len][ein][nul] != -1) return dp[len][ein][nul];

    int ans = 0, i, m = reac ? dig[len] : 1;
    for(i = 0; i <= m; i++)
        ans += dfs(len - 1, ein + i, nul + ((!i) && ein), reac && i == m);
    if(!reac)   dp[len][ein][nul] = ans;
    return ans;
}
int f(int x)
{
    int no = 0, i;
    while(x)
    {
        dig[++no] = (x & 1); x >>= 1;
    }
    sum = no;
    return dfs(no, 0, 0, 1);
}
int main(void)
{
    memset(dp, -1, sizeof(dp));
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d\n", f(y) - f(x - 1));
    return 0;
}
