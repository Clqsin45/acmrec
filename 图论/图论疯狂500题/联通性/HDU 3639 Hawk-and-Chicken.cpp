#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define N  5005
#define M 30005
#define LL __int64
#define INF 0x3f7f7f7f

int head[N], dfn[N], low[N], cnt[N], in[N], st[N],  belong[N];
int ans, top, no, id, num;

bool vis[N];
struct point{
    int u, v, next;
    point(){};
    point(int x, int y, int z):u(x), v(y), next(z){};
}p[M], g[N];
vector<int>v;
vector<int>f[N];
vector<int>store;

void init()
{
    memset(head, -1, sizeof(head));
    memset(dfn, -1, sizeof(dfn));
    memset(in, 0, sizeof(in));
    memset(cnt, 0, sizeof(cnt));
    v.clear();
    store.clear();
    fill(f, f + N, vector <int>());
    no = ans = num = id = top = 0;
}

void tarjan(int x){
    dfn[x] = low[x] = ++num;
    vis[x] = true;  st[top++] = x;

    int i,  y;
    for(i = head[x]; i != -1; i = p[i].next){
        y = p[i].v;
        if(dfn[y] == -1){
            tarjan(y);  low[x] = min(low[x], low[y]);
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
            f[id].push_back(y);
            cnt[id] ++;
        }while(st[top] != x);
    }
}

int dfs(int x){


   //printf("%d %d\n", x, ans);
    vis[x] = true;
    int tot  = cnt[x];
    int i, y;

    for(i = head[x]; i != -1; i = g[i].next){
        y = g[i].v; if(vis[y])  continue;

        tot +=  dfs(y);;

    }


    return tot;
}
bool find(int x, int y){
    int i;
    for(i = head[x]; i != -1; i = g[i].next){
        if(y == g[i].v) return true;
    }
    return false;
}
int main(void)
{
    int TC, tc, i, j, x, y, n, m;
    scanf("%d", &TC);
    for(tc = 1; tc <= TC; tc++){
        scanf("%d%d",  &n, &m);
        init();
        for(i = 1; i <= m; i++){
            scanf("%d%d", &x, &y);
            p[i] = point(x,  y, head[x]);   head[x] = i;
        }
      //  printf("!!\n");
        for(i = 0; i < n; i++){
            if(dfn[i] == -1)  tarjan(i);
        }
   //  printf("%d\n", id);
        memset(head, -1, sizeof(head));
        memset(vis, 0, sizeof(vis));
        no = 0;
        for(i = 1; i <= m; i++){
            x = belong[p[i].u]; y = belong[p[i].v];
          //  printf("%d %d\n", x,y);
            if(x == y)  continue;
            if(find(y, x))  continue;
            g[no] = point(y, x, head[y]);   head[y] = no++;
            in[y] ++;
        }
        for(i = 1; i <= id; i++){
          //  printf("%d \n", cnt[i]);
            if(vis[i] == 0)  {
                memset(vis, false, sizeof(vis));
            //    printf("%d\n", i);
                int tot = dfs(i);
                if(tot > ans){
                    v.clear();  v.push_back(i);
                    ans = tot;
                }
                else if(tot == ans){
                    v.push_back(i);
                }
                //printf("%d %d %d\n", x, tot, ans);
            }
        }
        n = v.size();

        for(i = 0; i < n; i ++){
            m = f[v[i]].size();
            y = v[i];
            for(j = 0; j < m; j++){
                store.push_back(f[y][j]);
            }
        }
        sort(store.begin(), store.end());
        n = store.size();
        printf("Case %d: %d\n", tc, ans - 1);
        for(i = 0; i < n; i++){
            printf("%d%c", store[i], i == n - 1? '\n' : ' ');
        }


    }
    return 0;
}
