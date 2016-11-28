#include <bits/stdc++.h>
using namespace std;

#define N 304

int f[N][N];
int a[N], pos[N];

void gao(int n){
    int i, j, k;
    for(k = 1; k <= n; k++){
        for(i = 1; i <= n; i++){
            for(j = 1; j <= n; j++){
                if(f[i][k] && f[k][j])  f[i][j] = 1;
            }
        }
    }
}
int main(void){
    int n, i, j;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            pos[a[i]] = i;
    }
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            scanf("%1d", &f[i][j]);
    gao(n);
    for(i = 1; i <= n; i++){
        for(j = 1; j <= pos[i]; j++){
            if(f[pos[i]][j] && i < a[j]){
               int aim = a[j];
               a[j] = i;  a[pos[i]] = aim;
               pos[aim] = pos[i];
               pos[i] = j;

               break;
            }
        }
    }
    for(i = 1; i <= n; i++) {
        printf("%d%c", a[i], i == n ? '\n' : ' ');
    }
}
