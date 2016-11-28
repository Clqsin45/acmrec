#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 1004;
const int M = 104;

double dp[2][M];

int main(){
    int n, m, i, j;
    int c;
    while(scanf("%d", &c) && c){
        scanf("%d%d", &n, &m);
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1.0;
        if(m > c){
            printf("0.000\n");
            continue;
        }
        if(n > 1000) n = 1000 | (n & 1);
        for(i = 1;i <= n; i++){
            memset(dp[i&1], 0, sizeof(double)*(c+2));
            for(j = 0; j <= c;j++){
                if(j == 0){
                    dp[i&1][j] += dp[!(i&1)][1]/c;
                }else{
                    dp[i&1][j] += dp[!(i&1)][j-1]/c * (c-j+1);
                    dp[i&1][j] += dp[!(i&1)][j+1]/c*(j+1);
                }
            }
        }
        printf("%.3f\n",dp[n&1][m]);
    }
}
