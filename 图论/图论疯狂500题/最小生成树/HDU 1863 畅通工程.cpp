#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 111
#define M
#define LL __int64
#define INF 0x3f7f7f7f

int f[N][N], d[N];
bool vis[N];
int n, ans;

bool prim(){
    int i, j, now, loc;
    for(i = 1; i <= n; i++){
        d[i] = f[1][i];
    }
    memset(vis, false, sizeof(vis));

    d[1] = 0;   vis[1] = true;
    for(i = 1; i < n; i++){
        now = f[0][0];
        for(j = 1; j <= n; j++){
            if(vis[j])  continue;
            if(now > d[j]){
                now = d[j]; loc = j;
            }
        }
        if(now == f[0][0])  return false;
        ans += now; vis[loc] = true;
        for(j = 1; j <= n; j++){
            if(vis[j])  continue;
            d[j] = min(d[j], f[loc][j]);
        }
    }
    return true;
}
int main(){

    int m, i, x, y, z;
    while(scanf("%d", &m) && m){
        scanf("%d", &n);
        memset(f, 0x3f, sizeof(f));
     //   printf("%d %d\n", f[0][0], INF);
        while(m--){
            scanf("%d%d%d", &x, &y, &z);
            f[x][y] = min(z, f[x][y]);
            f[y][x] = f[x][y];
        }
        ans = 0;

        if(prim()){
            printf("%d\n", ans);
        }
        else printf("?\n");
    }
}
