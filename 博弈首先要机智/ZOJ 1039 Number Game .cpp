#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N  = 22;
const int M  = 1<<19;
int a[N], dp[M];


int gao(int state, int x){
    int ans = state, i, j;
    //x的倍数
    for(i = x; i <= 20; i+= x){
        ans &= (~(1<<(i-2)));
    }
    //和
    for(i = 2; i <= 20; i++){
        if(!(ans & (1<<(i-2)))) continue;   //i不在集合里
        for(j = x; i - j - 2 >= 0; j+= x){
            if(ans & (1 << (i-j-2))) continue;//差在集合里 挂
            ans &= (~(1<<(i-2)));
            break;
        }
    }
    return ans;
}
int dfs(int state){
    if(dp[state] != -1) return dp[state];
   // printf("%d\n", state);
    int i;
    for(i = 2; i <= 20; i++){
        if(state & (1 << (i-2))){
         //   printf("!!!%d\n", i);
            if(dfs(gao(state, i)) == 0){
                return dp[state] = 1;
            }
        }
    }
    return dp[state] = 0;
}
int main(){
    int TC, tc, i, n, j;
    int state, ans;
    memset(dp, -1, sizeof(dp));
    scanf("%d", &TC);
    dp[0] = 0;
    for(tc= 1; tc <= TC; tc++){
        scanf("%d", &n);
        state = 0;

        for(i = 1; i <= n; i++){
            scanf("%d",&a[i]);
            state |= (1<<(a[i]-2));
        }

        printf("Scenario #%d:\n", tc);

        if(dfs(state)){
            printf("The winning moves are:");
            for(i = 1; i <= n; i++){
                if(dfs(gao(state, a[i])) == 0)
                    printf(" %d", a[i]);
            }
            printf(".\n");
        }
        else printf("There is no winning move.\n");
        printf("\n");
    }
    return 0;
}
