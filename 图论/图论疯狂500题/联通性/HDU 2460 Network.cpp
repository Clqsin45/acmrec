#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

#define N  100005
#define M  400004
#define LL __int64
#define INF 0x3f3f3f3f
int low[N], dfn[N], st[N], belong[N], fa[N], pre[N], head[N], deep[N], ans;

int num, id, no, top;
struct point{
    int u, v, next;
    point(){};
    point(int x, int y, int z):u(x), v(y), next(z){};
}p[M], g[N * 2];

void init(){
    memset(head, -1, sizeof(head));
    memset(dfn, -1, sizeof(dfn));
    no = id = num = top = 0;
    ans = 0;
}
void tarjan(int x, int father){
    dfn[x] = low[x] = ++num;
    st[top++] = x;
    int i, y;
    bool flag = true;
    for(i = head[x]; i != -1; i = p[i].next){
        y = p[i].v;
        if(y == father && flag){
            flag=  false;   continue;
        }
        if(dfn[y] == -1){
            tarjan(y, x);
            low[x] = min(low[x], low[y]);
        }
        else low[x] = min(low[x], dfn[y]);
    }
    if(dfn[x] == low[x]){
        id ++;
        do{
            y = st[--top];
            belong[y] = id;
        }while(st[top] != x);
    }
}

void dfs(int x, int father){
    int i, y;
    pre[x] = x;
    for(i = head[x]; i != -1; i = g[i].next){
        y = g[i].v;
        if(y == father) continue;
        ans ++; fa[y] = x;
        deep[y] = deep[x] + 1;
        dfs(y, x);
    }

}
int find(int x){
    if(x == pre[x]) return x;
    return pre[x] = find(pre[x]);
}
void merge(int x, int y){
    int i;
    top = 0;
    x = find(x);    y = find(y);
    while(x != y){
        if(deep[x] < deep[y]) {
            st[++top] = y;  y = find(fa[y]);
        }
        else {
            st[++top] = x;  x = find(fa[x]);
        }
        ans--;
    }
    while(top){
        i = st[top];    pre[i] = x;
        top--;
    }
}
int main(void){
    int n, m, Q, x, y, i, tc = 0;

    while(scanf("%d%d", &n, &m) && (n || m)){
        init();
        for(i = 0; i < m; i++){
            scanf("%d%d", &x, &y);
            p[no] = point(x, y, head[x]);   head[x] = no++;
            p[no] = point(y, x, head[y]);   head[y] = no++;
        }
       // BlackTechnologyVonTarjan();
       tarjan(1, -1);
        memset(head, -1, sizeof(head));
        no = 0;
       // printf("%d\n", id);
        for(i = 0; i < m; i++){
            x = p[i << 1].v;    y = p[i << 1].u;
            x = belong[x];  y = belong[y];
            if(x == y)  continue;
            g[no] = point(x, y, head[x]);   head[x] = no++;
            g[no] = point(y, x, head[y]);   head[y] = no++;
        }
        deep[1] = 1;
        dfs(1, -1);

        scanf("%d", &Q);
       // printf("!!!!!!!!!!\n");
       printf("Case %d:\n", ++ tc);
        while(Q--){
            scanf("%d%d", &x, &y);
            x = belong[x];  y = belong[y];
            merge(x, y);
            printf("%d\n", ans);
        }
        printf("\n");
    }
	return 0;
}
