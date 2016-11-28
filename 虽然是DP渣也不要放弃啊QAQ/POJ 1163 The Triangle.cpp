#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 122
int f[N][N], dp[N][N];

int main(){
    int n, i, j;
    while(scanf("%d", &n) != EOF){
        for(i = 1; i <= n; i++){
            for(j = 1; j <= i; j++){
                scanf("%d", &f[i][j]);
            }
        }
        memset(dp, 0, sizeof(dp));
        dp[1][1] = f[1][1];
        for(i = 2; i<= n; i++){
            for(j = 1; j<= i; j++){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) +f[i][j];
            }
        }
        int ans = 0;
        for(i = 1; i <= n; i++) ans = max(dp[n][i], ans);
        printf("%d\n", ans);
    }
    return 0;
}
