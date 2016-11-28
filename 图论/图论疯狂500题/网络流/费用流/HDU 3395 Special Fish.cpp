#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

#define N 204
#define M 24000
#define LL __int64
#define INF 0x3f7f7f7f

int head[N], d[N], pre[N], src[N], s, e, no;
bool vis[N];
struct point{
    int u, v, flow, next, cost;
    point(){};
    point(int x, int y, int z, int w, int c):u(x), v(y), next(z), flow(w), cost(c){};
}p[M];

void add(int x, int y, int w, int c){
    p[no] = point(x, y, head[x], w, c); head[x] = no++;
    p[no] = point(y, x, head[y], 0, -c); head[y] = no++;
}

void init(){
    memset(head, -1, sizeof(head));
    no = 0;
}

bool spfa(){
    int i, x, y;
    queue<int>q;
    memset(d, 0x80, sizeof(d));
    memset(vis, false, sizeof(vis));
    memset(pre, -1, sizeof(pre));
    d[s] = 0;   vis[s] = true;  q.push(s);
    while(!q.empty()){
        x = q.front();  q.pop();    vis[x] = false;
        //printf("%d\n", x);

        for(i = head[x]; i != -1; i = p[i].next){
            y = p[i].v;
            if(p[i].flow && d[y] < d[x] + p[i].cost){
                d[y] = d[x] + p[i].cost;
                pre[y] = i;
                if(vis[y])  continue;
                vis[y] = true;  q.push(y);
            }
        }
    }
   // printf("@@%d\n", d[e]);
    return d[e] != d[e + 1];
}

int mcmf(){
    int mincost = 0, maxflow = 0, minflow, i;
    while(spfa()){
        minflow = INF;
        //printf("%d\n", mincost);
        for(i = pre[e]; i != -1; i = pre[p[i].u])
            minflow = min(minflow, p[i].flow);
        for(i = pre[e]; i != -1; i = pre[p[i].u]){
            p[i].flow -= minflow;
            p[i ^ 1].flow += minflow;
        }
        //printf("%d\n", minflow);
        mincost += d[e] * minflow;
    }
    return mincost;
}
int main(void)
{
    int n, i, j, t;
    while(scanf("%d", &n) && n){
        init();
        s = 0;  e = 2 * n + 1;
        for(i = 1; i <= n; i++) scanf("%d", &src[i]);
        for(i = 1; i <= n; i++){
            add(s, i, 1, 0);
            add(i + n, e, 1, 0);
            add(i, e, 1, 0);
            for(j = 1; j <= n; j++){
                scanf("%1d", &t);
                if(t){
                    add(i, j + n, 1, src[i]^src[j]);
                }
            }
        }
        printf("%d\n", mcmf());
    }
    return 0;
}
