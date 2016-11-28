#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

#define N 104
#define M 54000
#define LL __int64
#define INF 0x3f7f7f7f
int d[N], head[N], vis[N], pre[N], s, e, no, k, m;

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
    no = 0;
}

bool spfa(){
    int x, y, i;
    queue<int>q;
    memset(d, 0x3f, sizeof(d));
    memset(vis, 0, sizeof(vis));
    memset(pre, -1, sizeof(pre));

    q.push(s);  vis[s] = true;  d[s] = 0;
    while(!q.empty()){
        x = q.front();  q.pop();    vis[x] = 0;
        for(i = head[x]; i != -1; i = p[i].next){
            y = p[i].v;
            if(p[i].flow && d[y] > d[x] + p[i].cost){
                d[y] = d[x] + p[i].cost;
                pre[y] = i;
                if(vis[y])  continue;
                q.push(y);  vis[y] = 1;
            }
        }
    }
    return d[e] != d[e + 1];
}

void mcmf(){
    int mincost = 0, maxflow = 0, minflow, i, sum;

    while(spfa()){
        minflow = INF;
        //printf("%d\n", maxflow);
        for(i = pre[e]; i != -1; i = pre[p[i].u])
            minflow = min(minflow, p[i].flow);
        for(i = pre[e]; i != -1; i = pre[p[i].u]){
            p[i].flow -= minflow;
            p[i ^ 1].flow += minflow;
        }
        maxflow += minflow;
        mincost += d[e] * minflow;
    }
    //printf("%d\n", minflow);
    if(maxflow < k){
        printf("-1\n");
    }
    else printf("%d\n", mincost);
    return;
}

int main(void)
{
    int n, i, j, x, y, z, lim;
    while(scanf("%d%d%d", &n, &m, &k) != EOF){
        s = 0;  e = n + 1;
        init();
        for(i = 1; i <= m; i++){
            scanf("%d%d%d%d", &x, &y, &z, &lim);
            for(j = 1; j <= lim; j++){
                add(x, y, 1, (2 * j - 1) * z);
            }
        }
        add(s, 1, k, 0);    add(n, e, k, 0);
        mcmf();
    }
    return 0;
}
