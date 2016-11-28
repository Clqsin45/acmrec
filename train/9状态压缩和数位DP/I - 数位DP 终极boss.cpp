#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 60
#define M 2520
#define LL __int64
#define INF 0x3f7f7f7f
LL dp[22][N][M + 4];
int num[M + 4], dig[22];

void init()
{
    int i, no = 0;
    for(i = 1; i <= M; i++)
        if(M % i == 0)   num[i] = ++no;
    memset(dp, -1, sizeof(dp));
    //printf("%d\n", no);
}

LL dfs(int len, int lcm, int sum, bool reac)
{
    if(!len)    return (sum % lcm == 0);
    if(!reac && dp[len][num[lcm]][sum] != -1)  return dp[len][num[lcm]][sum];
    int i, m = reac ? dig[len] : 9;
    LL ct = 0;

    for(i = 0; i <= m; i++)
    {
        ct += dfs(len - 1, i == 0 ? lcm : lcm / __gcd(lcm, i) * i, (sum * 10 + i) % M, reac && i == m);
    }
    if(!reac)dp[len][num[lcm]][sum] = ct;
    return ct;
}
LL f(LL n)
{
    int no = 0;
    while(n)
    {
        dig[++no] = n % 10;
        n /= 10;
    }
    return dfs(no, 1, 0, 1);
}
int main(void)
{
    LL n, m;
    int TC;
    scanf("%d", &TC);
    init();
    while(TC--)
    {
        scanf("%I64d%I64d", &n, &m);
        printf("%I64d\n", f(m) - f(n - 1));
    }


    return 0;
}
