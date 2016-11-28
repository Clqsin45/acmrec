#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

#define N 322
#define M 480000
#define LL __int64
#define INF 0x3f7f7f7f

int head[N], d[N], pre[N], ct[N], s, e, no;
bool vis[N];
struct point{
    int u, v, flow, next, cost;
    point(){};
    point(int x, int y, int z, int w, int c):u(x), v(y), next(z), flow(w), cost(c){};
}p[M];

void add(int x, int y, int w, int c){
    p[no] = point(x, y, head[x], w, c); head[x] = no++;
    p[no] = point(y, x, head[y], 0, -c);    head[y] = no++;
}
void init(){
    memset(head, -1, sizeof(head));
    memset(ct, 0, sizeof(ct));
    no = 0;
}

bool spfa(){
    int i, x, y;
    queue<int>q;
    memset(d, 0x3f, sizeof(d));
    memset(vis, false, sizeof(vis));
    memset(pre, -1, sizeof(pre));

    d[s] = 0;   vis[s] = true;  q.push(s);

    while(!q.empty()){
        x = q.front();  q.pop();    vis[x] = false;
        for(i = head[x]; i != -1; i = p[i].next){
            y = p[i].v;
            if(p[i].flow && d[y] > d[x] + p[i].cost){
                d[y] = d[x] + p[i].cost;
                pre[y] = i;
                if(vis[y])  continue;
                vis[y] = true;  q.push(y);
            }
        }
    }
    return d[e] != d[e + 1];
}

int mcmf(){
    int mincost = 0, maxflow = 0, minflow, i;
    while(spfa()){
        minflow =INF;
        for(i = pre[e]; i != -1; i = pre[p[i].u])
            minflow = min(minflow, p[i].flow);
        for(i = pre[e]; i != -1; i = pre[p[i].u]){
            p[i].flow -= minflow;
            p[i ^ 1].flow += minflow;
        }
        mincost += d[e] * minflow;
    }
    return mincost;
}
int main(void)
{
    int n, m, k, p, i, j, x, y, z;
    while(scanf("%d%d%d%d", &n, &m, &k, &p) != EOF){
        init();
        for(i = 1; i <= n; i++){
            scanf("%d", &x);    ct[x] ++;
        }
        s = 0;   e = n + m + 1;
        while(k--){
            scanf("%d%d%d", &x, &y, &z);
            add(x, y, INF, z);
            add(y, x, INF, z);
        }
        while(p--){
            scanf("%d%d%d", &x, &y, &z);
            add(y, x + m, INF, z);
        }
        for(i = 1; i <= m; i++){
            if(ct[i]){
                add(s, i, ct[i], 0);
            }
        }
        for(i = 1; i <= n; i++){
            add(i + m, e, 1, 0);
        }

        printf("%d\n", mcmf());
    }
    return 0;
}
