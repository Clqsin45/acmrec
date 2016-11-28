#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 30
#define M 60049
#define XT 59049
#define LL __int64
#define ll long long
#define INF 0x3f7f7f7f

ll dp[N][M];
int dig[N], rec[N];
bool val[M];
int get(int x, int d)
{
    int i;
    x /= rec[d];
    return x % 3;
}
ll dfs(int len, int s, bool reac)
{
    if(!len) {return val[s];}
    if(!reac && dp[len][s] != -1)   return dp[len][s];
    int m = reac ? dig[len] : 9, i, temp;
    ll ans = 0;
    for(i = 0 ; i <= m; i++)
    {
        if(!s && i == 0)    {ans += dfs(len - 1, s, reac && i == m); continue;}
        temp = get(s, i);
        if(temp == 2)   ans += dfs(len - 1, s - rec[i], reac && i == m);
        else ans += dfs(len - 1, s + rec[i], reac && i == m);
    }
    if(!reac)   dp[len][s] = ans;
    return ans;
}

ll f(ll x)
{
    int no = 0, i;

    while(x)
    {
        dig[++no] = x % 10; x /= 10;
    }
    return dfs(no, 0, 1);
}

bool judge(int x)
{
    int i, now = 0,temp;
    //printf("%d\n", x);
    while(x)
    {
        temp = x % 3;
        x /= 3;
        //printf("%d %d\n", now, temp);
        if(temp == 0){now ++;   continue;}
        if((now & 1) == 1 && (temp & 1) == 1)  return false;
        if((now & 1) == 0 && (temp & 1) == 0) return false;
        now ++;
    }
    return true;
}
void init()
{
    int i;
    for(i = rec[0] = 1; i <= 9; i++ )  rec[i] = rec[i - 1] * 3;
    for(i = 0; i <= XT; i++)
    {
        val[i] = judge(i);
        //if(i <= 10)printf("~~~%d %d\n", i, val[i]);
    }

}
int main(void)
{
    int TC;
    ll x, y;
    memset(dp, -1, sizeof(dp));
    init();
    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%lld%lld", &x, &y);
        printf("%lld\n", f(y) - f(x - 1));
    }
    return 0;
}
