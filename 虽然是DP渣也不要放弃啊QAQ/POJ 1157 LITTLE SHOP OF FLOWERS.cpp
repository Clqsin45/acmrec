#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 104

int dp[N][N], f[N][N];

int main(){
    int i, j, n, m, ans, k;
    while(scanf("%d%d", &n, &m)!= EOF){
        for(i = 1; i <= n; i++){
            for(j = 1; j <= m; j++){
                scanf("%d", &f[i][j]);
            }
        }

        memset(dp, 0xbf, sizeof(dp));
        dp[0][0] = 0;

        for(i = 1; i <= n; i++){
            int temp = dp[0][1];

            for(j = 1; j <= m; j++){
                for(k = 0; k < j; k++)  temp = max(temp, dp[i-1][k]);
               //printf("%d %d %d\n", i, j, temp);
                dp[i][j] = temp + f[i][j];
            }
        }
        int ans = dp[0][1];
        for(i = 1; i <= m; i++){
            ans = max(ans, dp[n][i]);
        }
        printf("%d\n", ans);
    }
}
