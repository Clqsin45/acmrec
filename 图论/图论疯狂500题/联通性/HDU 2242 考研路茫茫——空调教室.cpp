#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
using namespace std;

#define N 10004
#define M 40004
#define LL __int64
#define INF 0x3f7f7f7f

int head[N], dfn[N], low[N], st[N], cnt[N], w[N], belong[N];
bool vis[N];
int no , top, num, root, ans, id, sum;

struct point{
    int u, v, next;
    point(){};
    point(int x, int y, int z):u(x), v(y), next(z){};
}p[M], g[M];

void init(){
    memset(head, -1, sizeof(head));
    memset(cnt, 0, sizeof(cnt));
    memset(dfn, -1, sizeof(dfn));
    memset(vis, false, sizeof(vis));
    no = top = id = num = 0;
    ans =  INF; sum = 0;
}

bool find(int x, int y){
    int i;
    for(i = head[x]; i != -1; i = g[i].next){
        if(g[i].v == y) return true;
    }
    return false;
}
void dfs(int x, int fa){
    int i, y;
    for(i = head[x]; i != -1; i = g[i].next){
        y = g[i].v;
        if( y == fa)    continue;
        dfs(y, x);
        cnt[x] += cnt[y];
    }
    int t = sum - cnt[x];
    t = abs(t - cnt[x]);
    ans = min(t, ans);
}

void tarjan(int x, int fa){
    dfn[x] = low[x] = ++num;
     st[top ++] = x;

    int i, y;
    bool flag = true;
  //  printf("from%d\n", x);
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

          //  printf("!!!%d %d\n", id, y);
            belong[y] = id;
            cnt[id] += w[y];
        }while(st[top] != x);
    }
}


int main(void)
{
    int n, m, i, x, y;
    while(scanf("%d%d", &n, &m) != EOF){
        init();
        for(i = 0; i < n; i++)  {
            scanf("%d", &w[i]);
            sum += w[i];
        }
        for(i = 1; i <= m; i++){
            scanf("%d%d", &x, &y);
            p[++no] = point(x, y, head[x]);    head[x] = no;
            p[++no] = point(y, x, head[y]);    head[y] = no;
        }

        tarjan(0, -1);  no = 0;
       // printf("%d\n", id);
        memset(head, -1, sizeof(head));
        for(i = 1; i <= m; i++){
            x = belong[p[i << 1].u]; y = belong[p[i << 1].v];
           // printf("%d %d\n", x, y);
            if(x == y)    continue;

            g[++no] = point(x, y, head[x]); head[x] = no;
            g[++no] = point(y, x, head[y]); head[y] = no;
        }
        if(no == 0)  printf("impossible\n");
        else{
          //  printf("!%d %d\n", sum, ans);
            dfs(1, -1);
            printf("%d\n", ans);
        }

    }
    return 0;
}
