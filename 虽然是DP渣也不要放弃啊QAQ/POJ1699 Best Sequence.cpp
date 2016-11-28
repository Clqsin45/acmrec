#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 12;
const int M  = 5000;
int dis[N][N];
int dp[M][N];
char ch[N][22];
int next[22];
bool vis[N];

int cal(int a, int b){
    int i, j, k, ans;
    int la = strlen(ch[a]); int lb = strlen(ch[b]);
    i = lb < la ? la - lb:0;
    for(; i < la; i++){
        k = i;  j = 0;
        for(; k < la && j < lb; k++, j++){
            if(ch[a][k] != ch[b][j])    break;
        }
        if(la == k) return j;
    }
    return 0;
}
int main(){
    //freopen("out.txt","w", stdout);
    int TC, n, m, s, e, i, j, k, state, ans;
    scanf("%d", &TC);

    while(TC--){
        memset(dp, 0x3f, sizeof(dp));
        memset(vis, 0,sizeof(vis));
        scanf("%d", &n);
        for(i = 1; i <= n; i++)scanf("%s", ch[i]);

//        for(i = 1; i <= n; i++){
//            for(j = 1; j <= n; j++){
//                if(i == j)continue;
//                char *p = strstr(ch[i], ch[j]);
//                if(p == NULL)   continue;
//                if(p-ch[i]==0)  vis[j] = true;
//                else if(strlen(p) == strlen(ch[j])) vis[j] = true;
//            }
//          //  printf("\n");
//        }

//
//        for(i = 1, j = 0; i <= n; i++)  {
//            if(vis[i])  continue;
//          //  printf("!!%d\n", i);
//            strcpy(ch[++j], ch[i]);
//        }
//        n = j;
        s = 0;  e = n + 1;
        for(i = 1; i <= n; i++) {
            dis[0][i] = strlen(ch[i]), dis[i][e] = 0;
          //  printf("%d\n", dis[0][i]);
        }

        for(i = 1; i <= n; i++){

            for(j = 1; j <= n; j++){
                if(i == j)continue;
                dis[i][j] = strlen(ch[j])- cal(i, j);
//printf("%d ", dis[i][j]);
            }
  //          printf("\n");
        }
        dp[1][0] = 0; m = 1 << (e+1);
     //   printf("%d\n", m);
        for(state = 2; state < m; state ++){
            for(j = 1; j <= e; j++){
                if(state & (1<<j))  {
                    for(k = 0; k < e; k++){
                        if(!(state & (1 << k))) continue;
                        if(j == k)continue;
                        dp[state][j] = min(dp[state][j], dp[state-(1<<j)][k]+dis[k][j]);
                       // if(dp[state][j]!=ans)printf("%d %d %d %d\n", dp[state][j], state, j, k);
                    }
                }
            }
        }
       printf("%d\n", dp[m-1][e]);
    }
    return 0;
}
