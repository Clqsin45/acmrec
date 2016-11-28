#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 304;
const int M = 1005;

struct point{
    int u, v, next;
    point(){};
    point(int x, int y, int w){u = x, v = y, next = w;};
}p[M<<1];

int head[N], dfn[N], low[N], cntedge[N], cntver[N], belong[N], st[M<< 1], sg[N], fa[N];
bool vis[N];

int no , id, num, top;
void tarjan(int x, int fa){
    dfn[x] = low[x] = ++num;
    st[top ++] = x;

    int i, y;
    bool flag = true;
    for( i = head[x]; i != -1; i = p[i].next){
        y = p[i].v;
        if(y == fa && flag){
            flag = false;
            continue;
        }
        if(dfn[y] == -1){
            tarjan(y, x);
            low[x] = min(low[x], low[y]);
        }
        else low[x] = min(low[x], dfn[y]);
    }
    if(low[x] == dfn[x]){
        id ++;
        do{
            y = st[--top];
            belong[y] = id;
            cntver[id] ++;
        }while(st[top] != x);
    }
}

void init(){
    memset(head, -1, sizeof(head));
    memset(dfn, -1, sizeof(dfn));
    memset(low, -1, sizeof(low));
    memset(cntedge, 0, sizeof(cntedge));
    memset(cntver, 0, sizeof(cntver));
    no = id = num = top = 0;
}
void add(int x, int y){
    p[no] = point(x, y, head[x]);   head[x] = no++;
    p[no] = point(y, x, head[y]);   head[y] = no++;
}

void pred(){
    tarjan(1, -1);
  //  printf("%d\n", id);
    int m = no, i, x, y, n = id;
    memset(head , -1, sizeof(head));
    no = 0;
    for(i = 0; i < m; i+=2){
        x = belong[p[i].u]; y = belong[p[i].v];
        if(x == y){
            cntedge[x] ++;
        }else add(x, y);
    }

    for(i = 1; i <= n; i++){
        if((cntedge[i] & 1) )   add(i, ++id);
    }


}

void dfs(int x){
    int i, y;  vis[x] = true;
    sg[x] = 0;
    for(i = head[x]; i != -1; i = p[i].next){
        if(vis[y = p[i].v]) continue;
        dfs(y); sg[x] ^= (sg[y] + 1);
    }
    return ;
}
int main(){

    int TC, i, j, x, y, m, n, ans;
    while(scanf("%d", &TC) != EOF){
         ans = 0;
        while(TC--){
            init();
            scanf("%d%d", &n, &m);
            for(i = 0; i < m; i++){
                scanf("%d%d", &x, &y);
                add(x, y);
            }
            pred();
            memset(vis, false, sizeof(vis));

            dfs(belong[1]); ans ^= sg[belong[1]];
         //   printf("%d\n", ans);
        }
        printf("%s\n", ans ? "Sally" : "Harry");

    }
    return 0;

}
