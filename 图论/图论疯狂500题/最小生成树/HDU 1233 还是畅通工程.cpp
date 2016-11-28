#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 104
#define M
#define LL __int64
#define INF 0x3f7f7f7f

int f[N][N], n, d[N], ans;
bool vis[N];

void prim(){
    int i, j, now, loc;

    for(i = 1; i <= n; i++){
        d[i] = f[1][i];
    }
    memset(vis, false, sizeof(vis));
    d[1] = 0;   vis[1] = true;

    for(i = 1; i < n; i++){
        now = INF;
        for(j = 1; j <= n; j++){
            if(vis[j])  continue;
            if(now > d[j]){
                now = d[j]; loc = j;
            }
        }
        ans += now; vis[loc] = true;

        for(j = 1; j <= n; j++){
            if(vis[j])  continue;
            d[j] = min(d[j], f[loc][j]);
        }
    }
}
int main(void)
{
    int i, j, x, y, z, m;
    while(scanf("%d", &n) && n){
        m = (n - 1) * n / 2;
        while(m--){
            scanf("%d%d%d", &x, &y, &z);
            f[x][y] = f[y][x] = z;
        }
        ans = 0;
        prim();
        printf("%d\n", ans);
    }
    return 0;
}
