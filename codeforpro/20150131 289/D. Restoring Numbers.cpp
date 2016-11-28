#include <bits/stdc++.h>
using namespace std;
#define LL __int64
#define N 105

LL f[N][N];
LL gapc[N][N];
LL gapr[N][N];
LL a[N], b[N], up[N];

int main(void){
    int n, m, i, j;
    bool ok = true;
    LL maxn = 0, k = -1;
    scanf("%d%d", &n, &m);
    memset(up, -1, sizeof(up));
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m ; j++){
            scanf("%I64d", &f[i][j]);
            maxn = max(maxn, f[i][j]);
        }
    }
    for(i = 1; i < m &&ok; i++){
        for(j = 1; j <= n; j++){
            gapc[j][i+1] = f[j][i+1]- f[j][i];
            if(j == 1 ) continue;
            if(gapc[j][i+1] != gapc[j-1][i+1]){
                if(k == -1){
                    k = abs(gapc[j][i+1] - gapc[j-1][i+1]);
                //    printf("!!!%I64d\n", k);
                }
                else if(k != abs(gapc[j][i+1] - gapc[j-1][i+1])) ok = false;
            }
        }
    }
 //    printf("YES\n%I64d\n", k);
    for(i = 1; i < n && ok; i++){
        for(j = 1; j <= m; j++){
            gapr[i+1][j] = f[i+1][j] - f[i][j];
            if(gapr[i+1][j] >= 0){
                up[i + 1] = gapr[i+1][j];
            }
            if(j == 1) continue;
            if(gapr[i+1][j] != gapr[i+1][j-1]){

                if(k == -1){
                    k = abs(gapr[i+1][j] - gapr[i+1][j-1]);
                }
                else if(k != abs(gapr[i+1][j] - gapr[i+1][j-1])) ok = false;
            }
        }
        if(up[i+1] == -1) up[i+1] = gapr[i+1][m];
    }
   // printf("")
    if(ok && k >= 0 &&  k <= maxn){
        ok = false;
    }
    if(!ok){
        printf("NO\n");
    }
    else {
        if(k == -1) {
           // printf("!!!\n");
            k = maxn + 1;
        }

        printf("\n");
        printf("YES\n%I64d\n", k);
        a[1] = 0;   printf("%I64d", a[1]);
        for(i = 2; i <= n; i++){
            if(up[i] < 0) {
                up[i] = (up[i] + k) % k; //printf("%I64d ", up[i]);
            }
            a[i] = (a[i-1] + up[i]) % k;
            printf(" %I64d", a[i]);
        }
        printf("\n");
        for(i = 1; i <= m; i++){
            printf("%I64d%c", f[1][i], i == m ? '\n' : ' ');
        }
    }


    return 0;
}
