#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

#define N 1004
#define M 6006
#define LL __int64
#define INF 0x3f3f3f3f

int head[N], belong[N], dfn[N], low[N], st[N];
bool vis[N];

struct point{
    int u, v, next;
    point(){};
    point(int x, int y, int z): u(x), v(y), next(z){};
}p[M];
int no, num, id, top;

void init(){
    memset(head, -1, sizeof(head));
    memset(dfn, -1, sizeof(dfn));
    memset(vis, false, sizeof(vis));
    no = num = id = top = 0;
}

void tarjan(int x){
    dfn[x] = low[x] = ++num;
    vis[x] = true;
    st[top++] = x;
    int i, y;
    for(i = head[x]; i != -1; i = p[i].next){
        y = p[i].v;
        if(dfn[y] == -1){
            tarjan(y);
            low[x] = min(low[x], low[y]);
        }
        else if(vis[y]){
            low[x] = min(low[x], dfn[y]);

        }
    }
    if(low[x] = dfn[x]){
        id ++;
        do{
            y = st[--top];
            belong[y] = id;
            vis[y] = false;
        }while(y != x);
    }
    return ;
}


int main(){
    int n, m, i, j, x, y, TC;
    scanf("%d", &TC);
    while(TC--){
        init();
        scanf("%d%d", &n, &m);
        for(i = 0; i < m; i++){
            scanf("%d%d", &x, &y);
            add(x, y);
        }

        for(i = 1; i <= n; i++){
            if(dfn[i] == -1)    tarjan(i);
        }

        memset(head, -1, sizeof(head));
        no = 0;

        for(i = 0; i < m; i++){
            x = belong[p[i].x]; y = belong[p[i].v];
            if(x == y || get(x, y)) continue;
            add(x, y);
        }



}
