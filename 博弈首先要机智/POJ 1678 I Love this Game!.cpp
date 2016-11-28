#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 10005;
const int INF = 0x3f3f3f3f;
int n, a, b;

int num[N], dp[N];

int dfs(int x){
    if(dp[x] != dp[0])  return dp[x];

    int i, ans = INF;
    for(i = x + 1; i <= n; i++){
        if(num[i] - num[x] >= a && num[i] - num[x] <= b){
            ans = min(ans, num[x] - dfs(i));
        }
    }
    if(ans == INF)  return dp[x] = num[x];
    else return dp[x] = ans;
}
int gao(){
    int ans = dp[0];
    for(int i = 1; i <= n; i++){
        if(num[i] >= a && num[i] <= b){
            ans = max(ans, dfs(i));
        }
    }
    return ans == dp[0] ? 0 : ans;
}
int main(){
    int TC, i, x, y;
    scanf("%d", &TC);

    while(TC--){
        scanf("%d%d%d", &n, &a, &b);
        memset(dp, 0xbf, sizeof(dp));
        //printf("%d\n", dp[0]);
        for(i = 1; i <= n; i++){
            scanf("%d", &num[i]);
        }
        sort(num + 1, num +n +1);
        printf("%d\n", gao());
    }
    return 0;
}
