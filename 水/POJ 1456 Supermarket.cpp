#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 10005

int dp[N];

struct product{
    int pro, dead;

    void scan(){
        scanf("%d%d", &pro, &dead);
    }

    bool operator< (const product &I)const{
        return dead < I.dead;
    }
}p[N];

int main(){
    int i, j, n, m, ans;
    while(scanf("%d", &n) != EOF){
        m = 0;  ans = 0;
        for(i = 1; i <= n; i++){
            p[i].scan();
            m = max(m, p[i].dead);
        }
        memset(dp, 0, sizeof(dp));

        sort(p + 1, p + n + 1);
        for(i = 1; i <= n; i++){
            for(j = p[i].dead; j >= 1; j--){
                dp[j] = max(dp[j], dp[j-1]+p[i].pro);
                ans = max(ans, dp[j]);
            }
        }
        printf("%d\n", ans);
    }
}
