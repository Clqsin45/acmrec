#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

#define N 30005
#define M 150005
#define LL __int64
#define INF 0x3f3f3f3f
struct point{
    int u, v, next;
    point(){};
    point(int x, int y, int z): u(x), v(y), next(z){};
}p[M];
int head[N], belong[N], cnt[N], w[N], d[N], dfn[N], low[N], in[N], st[N];
bool vis[N];
int num, id, top, no;

void init(){
    memset(head,-1, sizeof(head));
    memset(dfn, -1, sizeof(dfn));
    memset(vis, false,sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    memset(d, 0x80, sizeof(d));
    memset(in, 0, sizeof(in));
    id = no = num = top = 0;
}

void tarjan(int x){
    dfn[x] = low[x] = ++num;
    vis[x] = true;  st[top++] = x;
    int i, y;
    for(i = head[x]; i != -1; i = p[i].next){
        y = p[i].v;
        if(dfn[y] == -1)    {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        }
        else if(vis[y]){
            low[x] = min(low[x], dfn[y] );
        }
    }
 //   printf("%d %d\n",x , low[x]);
    if(low[x] == dfn[x]) {
        id++;
        do{
            y = st[--top];
            belong[y] = id;
            cnt[id] +=w[y];
            vis[y] = false;
        }while(y != x);
    }

    return;
}

int gao(int x){
    int i, y;
    int ans = 0;
    queue<int>q;
    q.push(x);  vis[x] = true;  d[x] = cnt[x];
    ans = max(ans, cnt[x]);
    while(!q.empty()){
         x = q.front();     q.pop();    vis[x] = false;
        for(i = head[x]; i != -1; i = p[i].next){
            y = p[i].v;

            if(d[y] < d[x] + cnt[y]){
                d[y] = d[x] + cnt[y];
                ans = max(ans, d[y]);
                if(vis[y])  continue;
                vis[y] = true;  q.push(y);

            }
        }
    }
    return ans;
}
int main(void){
    int n, m, i, j, x, y, ans;
    while(scanf("%d%d", &n, &m) != EOF){
        init();
        for(i = 0; i < n; i++){
            scanf("%d", &w[i]);
            w[i] = max(0, w[i]);
        }

        for(i = 0; i < m; i++){
            scanf("%d%d", &x, &y);
            p[i] = point(x, y, head[x]);    head[x] = i;
        }

        for(i = 0; i < n; i++){
            if(dfn[i] == -1)    tarjan(i);
        }
   //     printf("%d\n", id);
        memset(head, -1, sizeof(head));
        no = 0;
        for(i = 0; i < m; i++){
            x = belong[p[i].u]; y = belong[p[i].v];
            if(x == y) continue;
            p[no] = point(x, y, head[x]);   head[x] = no++;
            in[y] ++;
        }


        //memset(vis, false, sizeof(vis));
        for(i = 1, ans = 0; i <= id; i++){
            if(in[i] == 0)  {
                memset(vis, false, sizeof(vis));
                ans = max(ans, gao(i));
            }
        }
        printf("%d\n", ans);
    }

	return 0;
}
