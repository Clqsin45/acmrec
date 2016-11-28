#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 5005
#define M  100004
#define LL __int64
#define INF 0x3f7f7f7f

int head[N << 1], dfn[N], low[N], belong[N], st[N], match[N << 1];
int no, top, num, id;

bool vis[N << 1];
struct point{
    int u, v, next;
    point(){};
    point(int x, int y, int z):u(x), v(y), next(z){};
}p[M], g[M];

void init(){
    memset(head, -1, sizeof(head));
    memset(dfn, -1, sizeof(dfn));
    memset(match, -1, sizeof(match));
    memset(vis, false, sizeof(vis));
    no = top = num = id = 0;
}
void add(int x, int y){
    g[no] = point(x, y, head[x]);   head[x] =no++;
}
void tarjan(int x){
    dfn[x] = low[x] = ++num;
    vis[x] = true;  st[top++] = x;

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
    if(low[x] == dfn[x]){
        id ++;
        do{
            y = st[--top];
            vis[y] = false;
            belong[y] = id;
        }while(st[top] != x);
    }
}

int dfs(int x){
    int i, y;
    for(i = head[x]; i != -1; i = g[i].next){
        y = g[i].v;
        if(vis[y])  continue;
        vis[y]  = true;
        if(match[y] == -1 || dfs(match[y])){
            match[y] = x;
            return 1;
        }
    }
    return 0;

}
int main(void)
{
    int TC, n, m, i, x, y, ans;
    scanf("%d", &TC);
    while(TC--){
        init();
        scanf("%d%d", &n, &m);
        for(i = 1; i <= m; i++){
            scanf("%d%d", &x, &y);
            p[i] = point(x, y, head[x]);    head[x] = i;
        }

        for(i = 1; i <= n; i++){
            if(dfn[i] == -1)    tarjan(i);
        }
       // printf("%d\n", id);
        memset(head, -1, sizeof(head));
        no = 0;
        for(i = 1; i <= m; i++){
            x = belong[p[i].u]; y = belong[p[i].v];
            if(x == y)  continue;
            add(x, y + id);
        }
        ans = 0;
        for(i = 1; i <= id; i++){
            memset(vis, 0,sizeof(vis));
            ans += dfs(i);
        }
        printf("%d\n", id - ans);
    }

    return 0;
}
