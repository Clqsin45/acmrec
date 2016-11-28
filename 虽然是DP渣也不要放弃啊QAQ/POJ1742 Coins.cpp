#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N  = 104;
const int M = 100004;
int a[N], c[N];
int w[N*10];
int q[M];
bool dp[M];
inline int scan_d() {
    char c;
    int ret=0;
    while((c=getchar())<'0'||c>'9');
    while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();
    return ret;
}

int main(){
    int tot, i, j, k, n, m, temp, s, sum, e;
    while(scanf("%d%d", &n, &m) && (n || m)){
        tot = 0;
        memset(dp, 0, sizeof(dp));
        for(i =  1; i <= n; i++)    a[i] = scan_d();
        for(i =  1; i <= n; i++)    c[i] = scan_d();
        dp[0] = true;
        for(i = 1; i <= n; i++){
            if(c[i] == 1){
                for(j = m; j >= a[i]; j--)
                    dp[j] |= dp[j-a[i]];
                continue;
            }
            if(c[i]*a[i] >= m){
                for(j = a[i]; j <= m; j++)
                    dp[j] |= dp[j-a[i]];
                continue;
            }
            for(k = 0; k < a[i]; k++){
                s = 0, e = -1, sum = 0;
                for(j = k; j <= m; j+= a[i]){
                    if(s + c[i] == e)   {
                        sum -= q[s++];
                    }
                    q[++e] = dp[j];
                    sum += dp[j];
                    if(sum) dp[j]  = true;
                }
            }
        }


        int ans = 0;
        for(i = 1; i <= m; i++) if(dp[i])   ans++;
        printf("%d\n", ans);
    }
    return 0;
}
