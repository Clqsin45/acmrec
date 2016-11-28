#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

#define N 100005
#define M 400004
#define LL __int64
#define INF 0x3f3f3f3f
int belong[N], st[N], low[N], dfn[N], head[N], dep[N];
int par[N], f[N];
int num, no, top, id, ans;
bool vis[N];
struct point{
    int u, v, next;
    point(){};
    point(int x, int y,  int z): u(x), v(y), next(z){};
}p[M];

void init(){
    memset(head, -1, sizeof(head));
    memset(dfn, -1, sizeof(dfn));
    memset(vis, false, sizeof(vis));
    no = num = id = top = ans = 0;
}
void add(int x, int y){
    p[no] = point(x, y, head[x]);   head[x] = no++;
    p[no] = point(y, x, head[y]);   head[y] = no++;
}

void tarjan(int x, int fa){
    low[x] = dfn[x] = ++num;
   // printf("%d \n", x);
    st[top ++] = x;
    int i, y;
    bool flag = true;
    for(i = head[x]; i != -1; i = p[i].next){
        y = p[i].v;
        if(y == fa && flag){
            flag = false;   continue;
        }
        if(dfn[y] == -1){
            tarjan(y, x);
            low[x] = min(low[x], low[y]);
        }
        else low[x] = min(low[x], dfn[y]);
    }

    if(low[x] == dfn[x]){
        id++;
        do{
            y = st[--top];
            belong[y] = id;
        }while(y != x);
    }
    return ;
}

void dfs(int x, int fa){
   // printf("%d\n", x);
    f[x] = x;
    int i, y;
    for(i = head[x]; i != -1; i = p[i].next){
        y = p[i].v;
        if(y == fa) continue;
        dep[y] = dep[x] + 1;
        dfs(y, x);  par[y] = x;
        ans ++;
    }
}

int find(int x){
    return x == f[x] ? x : f[x] = find(f[x]);
}

void merge(int x, int y){
    int i;//printf("%d %d\n", x, y);
    x = find(x);    y = find(y);

    top = 0;
    while(x != y){
        if(dep[x] > dep[y]){
            st[++top] = x;  x = find(par[x]);
        }
        else {
            st[++top] = y;  y = find(par[y]);
        }
        ans --;
    }
    for(i = 1; i <= top; i++){
        f[st[top]] = x;
    }
}


int main(void){
    int tc = 0, n, m, i, x, y;
    while(scanf("%d%d", &n, &m) && (n || m)){
        init();
        for(i = 1; i <= m; i++){
            scanf("%d%d", &x, &y);
            add(x, y);
        }
        tarjan(1, -1); // printf("!!!%d\n", id);
        no = 0; memset(head, -1, sizeof(head));

        for(i = 0; i < m; i++){
            x = belong[p[i<<1].u];  y = belong[p[i<<1].v];
            if(x == y) continue;
            add(x, y);
        }

        dep[1] = 0;
        dfs(1, -1);
       // printf("!!%d\n", ans);
        int Q;
        printf("Case %d:\n", ++tc);
        scanf("%d", &Q);
        while(Q--){
            scanf("%d%d", &x, &y);
            x = belong[x];  y = belong[y];
          //  printf("%d %d\n", x, y);
            merge(x, y);
            printf("%d\n", ans);
        }
        printf("\n");

    }
	return 0;
}
