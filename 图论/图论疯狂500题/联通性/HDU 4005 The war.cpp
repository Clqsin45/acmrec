//#pragma comment(linker,"/STACk:10240000,10240000")

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

#define N 11111
#define M 444444

#define LL __int64
#define INF 0x3f3f3f3f

int head[N], low[N], dfn[N], belong[N], st[N];
bool vis[N];
int num, id, no, ans, top;
struct point{
    int u, v, next, cost;
    point(){};
    point(int x, int y, int z, int c):u(x), v(y), next(z), cost(c){};
}p[M], g[M];
void init(){
    memset(head, -1, sizeof(head));
    memset(dfn, -1, sizeof(dfn));
    memset(vis, false, sizeof(vis));
    id = num = no = top = 0;
    ans = INF;
}

void tarjan(int x, int fa){
    int i, y;
    bool flag =  true;
    low[x] = dfn[x] = ++num;
    st[top++] = x; vis[x] = true;
    for(i = head[x]; i != -1; i = p[i].next){
        y = p[i].v;
        if(y == fa && flag){
            flag = false;
            continue;
        }
        if(dfn[y] == -1) {
            tarjan(y, x);
            low[x] = min(low[x], low[y]);
        }
        else if(vis[x]) low[x] = min(low[x], dfn[y]);
    }
    if(low[x] == dfn[x]){
       // printf("%d\n", x);
        id ++;
        do{
            y = st[--top];
            belong[y] = id;
            vis[y] == false;
        }while(st[top] != x);
    }
}
int dfs(int x, int fa){
    int i, t = INF, tt = INF, y, ct = 0;

    for(i = head[x]; i != -1; i = g[i].next){
        y = g[i].v;
        if(y == fa)  continue;
        ct = dfs(y, x);
        tt = min(tt, min(ct, g[i].cost));
        if(t > tt)  swap(tt, t);
    }
    ans = min(ans, tt);
    return t;
}


int main(void){
    int n, m, x, y, z, i, temp, locx, locy, ct;
    while(scanf("%d%d", &n, &m ) != EOF){
        init(); ct = 0;
        for(i = 0; i < m; i++){
            scanf("%d%d%d", &x, &y, &z);
            p[no] = point(x, y, head[x], z);    head[x] = no++;
            p[no] = point(y, x, head[y], z);    head[y] = no++;
        }
        for(i = 1; i <= n; i++){
            if(dfn[i] == -1) {
                tarjan(i, -1);
                ct ++;
            }

        }
      //  printf("%d\n", id);
        if(ct  > 1 || id == 1){
            printf("-1\n");
            continue;
        }
        memset(head, -1, sizeof(head));
        no = 0;
        temp = INF;
        for(i = 0; i < m; i++){
            x = belong[p[i<<1].u];  y = belong[p[i<<1].v];
            if(x == y) continue;
            g[no] = point(x, y, head[x], p[i<<1].cost); head[x] = no++;
            g[no] = point(y, x, head[y], p[i<<1].cost); head[y] = no++;
            if(temp > p[i<<1].cost){
                temp = p[i<<1].cost;
                locx = x;   locy = y;
            }
        }
        //printf("%d\n", no);
        //memset(dfn, 0, sizeof(dfn));
        if(temp != INF){
            dfs(locx, locy);
            dfs(locy, locx);
        }
        if(ans == INF) ans = -1;
        printf("%d\n", ans);
    }
	return 0;
}
