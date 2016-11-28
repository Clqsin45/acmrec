#include <bits/stdc++.h>
using namespace std;

#define N 14

int f[N][N];

int main(){
    int n, i, j, ans = 0;
    cin>> n;
    for(i = 1; i <= n; i++){
        f[1][i] = f[i][1] = 1;
    }
    ans = 1;
    for(i = 2; i <= n; i++){
        for(j = 2; j <= n; j++){
            f[i][j] = f[i-1][j] + f[i][j-1];
            ans = max(ans, f[i][j]);
          //  cout<<f[i][j]<<" ";
        }
        //cout <<endl;
    }
    cout <<ans<<endl;
}
