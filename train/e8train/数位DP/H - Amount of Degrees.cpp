#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 40
#define M
#define LL __int64
#define INF 0x3f7f7f7f

int dp[N][N], dig[N], k, b;

int dfs(int len, int num, bool reac)
{
    if(!len)    return num == k;
    if(num > k) return 0;
    if(!reac && dp[len][num]!= -1)   return dp[len][num];
    int m = reac ? dig[len] : 1, ans = 0, i;
    if(m > 1)   m = 1;
    for(i = 0; i <= m; i++)
    {
        if(i == 0)      ans += dfs(len - 1, num, reac && i == m && i == dig[len]);
        else ans += dfs(len - 1, num + 1, reac && i == m && i == dig[len]);
    }
    if(!reac)   dp[len][num] = ans;
    return ans;

}

int f(int x)
{
    int no = 0, i;
    while(x)
    {
        dig[++no] = x % b;
        x /= b;
    }
    return dfs(no, 0, 1);
}
int main(void)
{
    int x, y;
    memset(dp, -1, sizeof(dp));
    scanf("%d%d", &x, &y);
    scanf("%d%d", &k, &b);
    printf("%d\n", f(y) - f(x - 1));
    return 0;
}
