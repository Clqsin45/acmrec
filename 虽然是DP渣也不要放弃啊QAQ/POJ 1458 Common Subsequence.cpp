#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 10000;

char a[N], b[N];
int dp[2][N];
int main(){
    while(scanf("%s%s", a + 1, b + 1) != EOF){
        int n = strlen(a +1);  int m = strlen(b + 1);
       // printf("%d %d\n", n, m);
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++){
         //   printf("%d\n", i);
            for(int j = 1; j <= m; j++){
               // printf("   %d\n", j);
                if(a[i] == b[j]){
                    dp[i&1][j] = max(dp[i&1][j], dp[!(i&1)][j-1] + 1);
                }
                dp[i&1][j] = max(dp[!(i&1)][j], max(dp[i&1][j-1],dp[i&1][j]));
            }
        }

        printf("%d\n", dp[n&1][m]);
    }
}
