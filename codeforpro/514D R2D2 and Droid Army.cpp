#include <bits/stdc++.h>
using namespace std;
const int N = 100004;
typedef __int64 ll;
ll f[6][N], dp[6][N][17];
ll maxm[6], out[6], lim;
int n, m;
void st(int t){
    int i, j, k, m;
    k = (int)(log(n*1.0)/log(2.0));
    for(i = 0; i < n; i++){
        dp[t][i][0] = f[t][i];
    }
    for(j = 1; j <= k; j++){
        for(i = 0; i + (1 << j) - 1 < n; i++){
            m =  i + (1 << (j - 1));
            dp[t][i][j] = max(dp[t][i][j-1], dp[t][m][j-1]);
        }
    }
}

ll ask(int t, int i, int j){
    int k = (int)(log(j-i+1)/log(2.0));
    return max(dp[t][i][k], dp[t][j-(1<<k)+1][k]);
}
bool gao(int mid){
    int i, j, k;
    ll all = 0;
    for(j = 0; j + mid - 1 < n; j ++){
        all = 0;
        for(i = 0; i < m; i++){
            maxm[i] = ask(i, j, j + mid - 1);
            all += maxm[i];
        }

        if(all <= lim) return true;
    }
    return false;
}
int main(){
    int  i, j, l, r;
    ll ans, mid, low, high;
    scanf("%d%d%I64d", &n, &m, &lim);
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++)
            scanf("%I64d", &f[j][i]);
    }
    for(i = 0; i < m; i++) st(i);
//    for(i = 0; i < n; i++){
//        for(j = 0; (1<<j) + i - 1 < n; j++)
//        printf("%I64d ", dp[0][i][j]);
//        printf("\n");
//    }
    low = 0;    high = n;
    //low = high = 3;
    while(low <= high){
        mid = (low + high) >> 1;
        if(gao(mid)){
            ans = mid;
            for(i = 0; i < m; i++)out[i] = maxm[i];
            low = mid +1;
        }
        else high = mid - 1;
    }

    for(i = 0; i < m; i++){
        printf("%I64d ", out[i], i == m -1 ? '\n' : ' ');
    }
    return 0;
}
