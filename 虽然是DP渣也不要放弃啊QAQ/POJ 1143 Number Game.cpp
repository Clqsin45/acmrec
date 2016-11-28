#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

#define N 1148576
int  dp[N], out, maxm;

int a[22];
int dfn = 0;
bool app[22];
vector<int>ans;
bool dfs(int one, bool needpro[]){

    int i, x;
    bool temp[22];


    memcpy(temp, needpro, sizeof(bool)*22);
    for(i = 2; i + one <= maxm; i++){
        if(temp[i]) continue;
        x = i + one;
        temp[x] = false;
    }
    int now = 0;
    for(i = 2; i<= maxm ;i++){
        if(temp[i])  now |= 1;
        now <<= 1;
    }
    now >>= 1;

    if(dp[now] != -1) return dp[now];
    bool  gg = false;
    for(i = 2; i <= maxm ; i++){
        if(temp[i]){
            temp[i] = false;
            if(dfs(i, temp)) {
                gg = true;
                break;
            }
            temp[i] = true;
        }
    }
    if(gg) dp[now] = 0;
    else dp[now] = true;
    return dp[now];
}

int main(){
    int n, tc = 0, m, i, j;
    memset(dp, -1, sizeof(dp));
    while(scanf("%d", &n) && n){
       maxm  =-1;
        memset(app, false, sizeof(app));

        for(i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            app[a[i]] = true;
            maxm = max(maxm, a[i]);
        }
        //memset(dp, -1, sizeof(dp));

        ans.clear();
        for(i = 2; i <= maxm; i++){

            if(!app[i])continue;

            app[i] = false;
            if(dfs(i, app)) {
                ans.push_back(i);
            }
            app[i] = true;
        }
        printf("Test Case #%d\n", ++tc);
        if(ans.size()){
            printf("The winning moves are:");
            for(i = 0; i < ans.size(); i++){
                printf(" %d", ans[i]);
            }
            printf("\n");
        }
        else printf("There's no winning move.\n");
        printf("\n");
    }
    return 0;
}
