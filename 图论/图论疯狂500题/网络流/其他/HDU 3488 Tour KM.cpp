#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 204
#define M
#define LL __int64
#define INF 0x3f7f7f7f

bool vx[N], vy[N];
int f[N][N], slack[N], lx[N], ly[N], match[N], n, m;


void init(){
    memset(f, 0x80, sizeof(f));
    memset(lx, 0x80, sizeof(lx));
    memset(ly, 0, sizeof(ly));
    memset(match, 0, sizeof(match));
}

bool dfs(int x){
    vx[x] = true;
    int i, j, t;
    for(i = 1; i <= n; i++){
        if(vy[i])   continue;
        t = lx[x] + ly[i] - f[x][i];
        if(t == 0){
            vy[i] = 1;
            if(!match[i] || dfs(match[i])){
                match[i] = x;
                return true;
            }
        }
        else {
            slack[i] = min(slack[i], t);
        }
    }
    return false;

}
int km()
{
    int i, j, minm, ans;
    for(i = 1; i <= n; i++){
        memset(slack, 0x3f, sizeof(slack));
        while(true){
            memset(vx, 0, sizeof(vx));
            memset(vy, 0, sizeof(vy));
            if(dfs(i)) break;

            minm = INF;
            for(j = 1; j <= n; j++)
                if(!vy[j])  minm = min(slack[j], minm);

            for(j = 1; j <= n; j++){
                if(vx[j])   lx[j] -= minm;
                if(vy[j])   ly[j] += minm;
                else slack[j] -= minm;
            }

        }
    }
    ans = 0;

    for(i = 1; i <= n; i++){
        ans += f[match[i]][i];
    }
    return ans;
}
int main(void)
{
    int tc, x, y, z, i, j;
    scanf("%d",  &tc);
    while(tc--){
        scanf("%d%d", &n, &m);
        init();

        while(m--){
            scanf("%d%d%d", &x, &y, &z);
            z = -z;
            if(f[x][y] < z){
                f[x][y] = z;
                lx[x] = max(z, lx[x]);
            }
        }

        printf("%d\n", 0-km());
    }
    return 0;
}
