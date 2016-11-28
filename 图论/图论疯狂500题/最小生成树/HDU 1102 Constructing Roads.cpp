#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 102
#define M
#define LL __int64
#define INF 0x3f7f7f7f

int d[N], f[N][N], n, ans;
bool vis[N];

void prim(){
    int i, j, now, loc;

    memset(vis, false, sizeof(vis));
    //printf("!!%d\n",f[1][3]);
    for(i = 1; i <= n; i++){
        d[i] = f[1][i];
       // printf("%d\n", d[i]);
    }
    d[1] = 0;   vis[1] =true;
    for(i = 1; i < n; i++){
        now = INF;
        for(j = 1; j <= n; j++){
            if(vis[j])  continue;
            if(d[j] < now){
                now = d[j];
                loc = j;
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
    int i, j, m, x, y;
    while(scanf("%d", &n) != EOF){
        ans = 0;
        for(i = 1; i <= n; i++){
            for(j = 1; j <= n; j++){
                scanf("%d", &f[i][j]);
            }
        }
       //
        scanf("%d", &m);
        while(m--){
            scanf("%d%d", &x, &y);
            f[x][y] = f[y][x] = 0;
        }//printf("%d\n", f[1][3]);
        prim();
        printf("%d\n", ans);
    }
    return 0;
}
