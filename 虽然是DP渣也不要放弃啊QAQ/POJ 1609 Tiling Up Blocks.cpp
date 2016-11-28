#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 105;
const int M = 11004;
int dp[N];

struct point{
    int l, r;
    void scan(){
        scanf("%d%d", &l, &r);
    }

    bool operator<(const point &I)const{
        if(l == I.l) return r < I.r;
        return l < I.l;
    }
}p[M];

int main(){
    int n, m, i, j, ans;

    while(scanf("%d", &n) && n){
        for(i = 1; i <= n; i++){
            p[i].scan();
        }
        ans = 0;
        sort(p + 1, p + n + 1);
        memset(dp, 0, sizeof(dp));
        for(i = 1; i <= n; i++){
            for(j = p[i].r+1; j >= 1; j--){

                dp[p[i].r] = max(dp[p[i].r], dp[j-1] + 1);
              //  printf("%d %d %d\n", i, j, dp[j]);
                ans = max(ans, dp[j]);
            }
        }
        printf("%d\n", ans);
    }
    printf("*\n");
    return 0;
}
