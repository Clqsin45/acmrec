#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

#define N 404
#define M 44000
#define LL __int64
#define INF 0x3f7f7f7f


int head[N], pre[N], d[N], vis[N], s, e, n, no;
int scr[N], ha[N], hb[N], a[N], b[N];
struct point{
    int u, v, flow, next, cost;
    point(){};
    point(int x, int y, int z, int w, int c):u(x), v(y), next(z), flow(w), cost(c){};
}p[M];

void add(int x,int y, int w, int c){
    p[no] = point(x, y, head[x], w, c); head[x] = no++;
    p[no] = point(y, x, head[y], 0, -c);    head[y] = no++;
}

void init(){
    memset(head, -1, sizeof(head));
    no = 0;
}

bool spfa(){
    int i, x, y;
    queue<int>q;
    memset(d, 0x80, sizeof(d));
    memset(vis, 0, sizeof(vis));
    memset(pre, -1, sizeof(pre));

    d[s] = 0;   vis[s] = 1; q.push(s);
    while(!q.empty()){
        x = q.front();  q.pop();    vis[x] = 0;
        for(i = head[x]; i != -1; i = p[i].next){
            y = p[i].v;
            if(p[i].flow && d[y] < d[x] + p[i].cost){
                d[y] = d[x] + p[i].cost;
                pre[y] = i;
                if(vis[y])  continue;
                vis[y] = 1; q.push(y);
            }
        }
    }
   //. printf("%d\n", d[e]);
    return d[e] != d[e + 1];
}

void mcmf(){
    int mincost = 0, maxflow = 0, i, j, minflow, sum;
    while(spfa()){
        minflow = INF;
        for(i = pre[e]; i != -1; i = pre[p[i].u])
        {
            minflow = min(minflow, p[i].flow);
        }
        for(i = pre[e]; i != -1; i = pre[p[i].u]){
            p[i].flow -= minflow;
            p[i ^ 1].flow += minflow;
        }
        mincost += d[e] * minflow;
    }
    sum = 0;
    if(mincost / 1000 > 0) {
        printf("%d ", mincost / 1000);
//        for(i = 1; i <= n; i++){
//            for(j = head[i]; j != -1; j = p[j].next){
//                if(p[j].flow)   continue;
//                if(i != p[j].v) sum++;
//            }
//        }
//        printf("%d\n", sum);
        printf("%.3f%%\n", (mincost % 1000) * 1.0 * 100/ n);
    }
    else printf("Oh, I lose my dear seaco!\n");
}
int main(void)
{
    int i, j, x, y;
    while(scanf("%d", &n) && n){
        init();
        for(i = 1; i <= n; i++) scanf("%d", &scr[i]);
        for(i = 1; i <= n; i++) scanf("%d", &ha[i]);
        for(i = 1; i <= n; i++) scanf("%d", &hb[i]);
        for(i = 1; i <= n; i++) scanf("%d", &a[i]);
        for(i = 1; i <= n; i++) scanf("%d", &b[i]);

        s = 0;  e = 2 * n + 1;
        for(i = 1; i <= n; i++){
            add(s, i, 1, 0);    add(i + n, e, 1, 0);
            for(j = 1; j <= n; j++){
                x = ceil((double)hb[j] / a[i]);
                y = ceil((double)ha[i] / b[j]);

                if(x <= y)  {
                    if(i == j)add(i, j + n, 1, scr[i]*1000+1);
                    else add(i, j + n, 1, scr[i]*1000);
                }
                else {
                    if(i == j ) add(i, j + n, 1, -scr[i]*1000+1);
                    else add(i, j + n, 1, -scr[i]*1000);
                }
            }
        }
        mcmf();
    }

    return 0;
}
