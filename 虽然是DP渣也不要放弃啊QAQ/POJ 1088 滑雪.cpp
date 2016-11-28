#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 104

int dp[N][N], a[N][N];
int gox[4] = {0, 0, -1, 1}, goy[4] = {-1, 1, 0, 0};
int ans;

void dfs(int x, int  y){
    int xx, yy, i, temp = 0;
    if(dp[x][y] != -1)  return;
    for(i = 0; i < 4; i++){
        xx = x + gox[i];    yy = y + goy[i];
        if(a[x][y] > a[xx][yy]){
            dfs(xx, yy);
            temp = max(temp, dp[xx][yy]);
        }
    }
    dp[x][y] = temp+ 1;
}

int main(){
    int n, i, j, ans, m;
    memset(a, 0x3f, sizeof(a));
    while(scanf("%d%d", &n, &m) != EOF){
        memset(dp, -1, sizeof(dp));
        ans = 0;

        for(i = 1; i <= n; i++){
            for(j =1; j <= m; j++)  scanf("%d", &a[i][j]);
        }
        for(i = 1; i <= n; i++){
            for(j = 1; j <= m; j++){
                if(dp[i][j] == -1){
                    dfs(i, j);
                    ans = max(ans, dp[i][j]);
                }
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}
