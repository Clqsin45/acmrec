#include <bits/stdc++.h>
using namespace std;

#define N 105
#define ll __int64

ll dp[1004][N][2][2];
int main(){
    int n, m, i, j, k, t, statepos, statemod, gg;
    ll p = 1ll;
    ll ans ;
    string black = "  ";
    cin >> n >> k >> m;
    memset(dp, 0, sizeof(dp));
    dp[n+1][0][0][0] = 1;

    for(i = n; i >= 1 ;i--){
      //  cout<<"!!!!"<<i << endl;
        for(t = 0; t < k; t++){
            for(statepos = 0; statepos <= 1; statepos ++){
                for(statemod = 0; statemod <= 1; statemod ++){
                    if(dp[i+1][t][statepos][statemod] == 0) continue;
                //    cout<<"yingying"<<t << black << statepos<<black << statemod<<endl;
                    for(j = (i == 1 ); j < 10; j++){
                        gg = (t + j * p) % k;
                        dp[i][gg][statepos|(j>0)][statemod|((gg==0)&&j)] =
                            (dp[i][gg][statepos|(j>0)][statemod|((gg==0)&&j)] +
                                dp[i+1][t][statepos][statemod]) % m;
                      //  cout<<gg<<black<<(statepos|(j>0))<<black<<
                       // (statemod|(gg==0))<<black<<dp[i][gg][statepos|(j>0)][statemod|(gg==0)]<<endl;
                    }

                }
            }
        }
        p *= 10;    p %= k;
    }
    ans = 0;
    for(i = 0; i < k; i++){
            ans = (ans + dp[1][i][1][1]) % m;
    }

    cout << ans << endl;
}
