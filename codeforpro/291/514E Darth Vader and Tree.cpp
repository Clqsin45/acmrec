#include <bits/stdc++.h>
using namespace std;
typedef __int64 ll;

const int N = 104;
const ll MOD = 1000000007ll;
int d[N];
ll dp[N];
ll x;   int n;


struct Matrix{
    ll f[N][N];

    Matrix operator +(const Matrix &I)const{
        Matrix ans;
        int i, j;
        for(i = 1; i <= 101; i++)
            for(j = 1; j <= 101; j++)
                ans.f[i][j] = (f[i][j] + I.f[i][j]) % MOD;
        return ans;
    }

    Matrix operator *(const Matrix &I)const{
        int i, j, k;
        Matrix ans;
        for(i = 1; i <= 101; i++){
            for(j = 1; j <= 101; j++){
                ans.f[i][j] = 0;
                for(k = 1; k <= 101; k++){
                    ans.f[i][j] = (ans.f[i][j]+f[i][k]*I.f[k][j]%MOD)%MOD;
                }
            }
        }
        return ans;
    }

    void init(){
        memset(f, 0, sizeof(f));
        int i;
        for(i = 1;i <= 100; i++){
            f[i][1] = f[i][101] = d[i];
        }
        for(i = 1; i < 100; i++)
            f[i][i+1] = 1;
        f[101][101] = 1;
    }

    void initI(){
        memset(f, 0, sizeof(f));
        int i;
        for(i = 1; i <= 101; i++){
            f[i][i] = 1;
        }
    }
};

Matrix mat;

void quickpow(ll p){
    Matrix I;   I.initI();
    Matrix temp = mat;
    while(p){
        if(p & 1LL)
            I = I*temp;
        temp = temp * temp;
        p >>= 1LL;
    }
    mat = I;
}
int main(){
    int i,j, t;
    ll ans, temp;
    ans = 0;
    memset(d, 0, sizeof(d));
    memset(dp, 0, sizeof(dp));
    scanf("%d%I64d", &n, &x);
    while(n--){
        scanf("%d", &t);
        d[t] ++;
    }
    mat.init();
    dp[0] = 1;
    for(i = 1; i <= 100; i++){
        for(j = 1; j <= i ; j++){
            dp[i] = (dp[i-j]*d[j] % MOD + dp[i]) % MOD;
        }
    }

    if(x <= 100){
        for(i = 0; i <= x; i++) ans = (ans + dp[i]) % MOD;
        printf("%I64d\n", ans);
    }
    else{
        quickpow(x-99);
        temp = 0ll;
        for(i = 0; i <= 99; i++) temp = (temp + dp[i]) % MOD;
        for(i = 1; i <= 100; i++) ans = (ans + dp[100-i]*mat.f[i][101] % MOD) % MOD;
        ans = (ans + temp*mat.f[101][101]%MOD)%MOD;
        printf("%I64d\n", ans);
    }
    return 0;

/**************
10 100000
1 2 3 4 5 6 7 8 9 10

***********/
}
