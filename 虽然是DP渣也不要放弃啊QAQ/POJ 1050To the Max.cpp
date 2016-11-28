#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 105
#define INF 0x3f3f3f3f
int a[N][N], f[N][N], g[N][N], tat[N][N];

int main(){
    int n, i, j, ans, k, all;

    while(scanf("%d", &n) != EOF){
            all = 0;
        memset(f, 0, sizeof(f));
        for(i = 1; i <= n; i++){
            for(j = 1;j  <= n; j++){
                scanf("%d", &a[i][j]);
                all += a[i][j];
            }
        }
        for(i = 1; i <=n ; i++){
            for(j =1; j <= n; j++){
                f[i][j] = f[i][j-1]+ a[i][j];
            }
        }


        ans = -INF;
        for(i = 1; i <= n; i++){
            memset(g, 0x80, sizeof(g));
            for(j = 1;j <= n;j ++){
                for(k = i;k <= n; k++){
                    tat[j][k] = f[j][k] - f[j][k-i];
                //    printf("%d ", tat[j][k]);
                }
              //  printf("\n");
            }

            for(j = 1; j <= n; j++){
                for(k = i; k <= n; k++){
                    g[j][k] = tat[j][k];
                 //   printf("%d ", g[j][k]);ans = max(ans, g[j][k]);
                    g[j][k] = max(g[j][k], g[j][k] + g[j-1][k]);
                    ans = max(ans, g[j][k]);
                    if(g[j][k] < 0) g[j][k] = 0;
                }
               // printf("\n\n");
            }
        }
        if(ans == all){
            int temp = -INF;
            temp = max(ans - f[1][n], ans - f[n][n]);
            int temp1 = 0, temp2 = 0;
            for(i = 1; i <= n; i++){
                temp1 += f[i][1];
                temp2 += f[i][n];
            }
            temp = max(temp, max(ans - temp1, ans - temp2));
            ans = temp;
        }

        printf("%d\n", ans);
    }
}
