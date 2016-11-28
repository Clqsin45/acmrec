#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 11;
int dp[N][N];

void init(){
    int i, j;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(i = 1; i <= 10; i++){
        dp[i][1] = 1;
        dp[0][i] = 1;
    }
    for(i = 1; i <= 10; i++){
        for(j = 2; j <= 10; j++){
            dp[i][j] = dp[i][j-1] + (i >= j ? dp[i-j][j] : 0);
        }
    }
   // cout<<dp[3][3]<<endl;
}
int  main(){
    init();
    int TC, n, m;
    cin>>TC;
    while(TC--){
        cin>>n>>m;
        cout<<dp[n][m]<<endl;
    }
    return 0;

}
