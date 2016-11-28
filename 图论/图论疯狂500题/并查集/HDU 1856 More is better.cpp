#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 200004
#define M 10000005
#define LL __int64
#define INF 0x3f7f7f7f

int dir[M], f[N], vis[N], rank[N], n;

void init(){
    int i;
    n <<= 1;
    for(i = 1; i <= n; i++){
        f[i] = i;   rank[i] = 1;
    }
    memset(vis, false, sizeof(vis));
}
int find(int x){
    if(x == f[x])   return x;
    return f[x] = find(f[x]);
}

void merge(int x, int y){
    x =find(x); y = find(y);
    if(x==y)    return;

    if(rank[y] > rank[x]){
        rank[y] += rank[x];
        f[x] = f[y];
    }
    else {
        rank[x] += rank[y];
        f[y] = f[x];
    }
}
int main(void)
{
    int i, x, y, m, ans;
    while(scanf("%d", &n) != EOF){
        if(n == 0)  {
            printf("1\n");  continue;
        }
        init(); m = 0;  ans = 0;
        n >>= 1;
        for(i = 1; i <= n; i++){
            scanf("%d%d", &x, &y);
            if(!vis[x]){
                dir[x] = ++m;
                vis[x] = true;
            }
            if(!vis[y]){
                dir[y] = ++m;
                vis[y] = true;
            }
            merge(dir[x], dir[y]);
        }

        for(i = 1; i <= m; i++){
            ans = max(ans, rank[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
