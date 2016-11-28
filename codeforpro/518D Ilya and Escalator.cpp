#include <bits/stdc++.h>
using namespace std;
const int N = 2003;

double dp[N][N];

int main(){
    int n, t,i, j;
    double p;
    cin>>n>>p>>t;
    dp[0][0] = 1;
    for(i = 0; i <= n; i++){
        for(j = 1; j <= t; j++){

            if(i == n) dp[i][j] += dp[n][j-1];
            else dp[i][j] += dp[i][j-1]*(1-p);
            if(i != 0)dp[i][j] += dp[i-1][j-1]* p;
           // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
    }
    double ans = 0.0;
    for(i = 0; i <= n; i++){
        ans+= i * dp[i][t];
    }
    printf("%.10f\n", ans);
    return 0;
}
