#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

#define N 104
#define M 8004
#define LL __int64
#define INF 0x3f7f7f7f
int head[N], d[N], pre[N], in[N], out[N], s, e, no, sum, all;
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
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
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
        //printf("~~%d\n", x);
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

void mcmf(){
    int mincost = 0, maxflow = 0, minflow, i;
    while(spfa()){
        minflow =INF;
        //printf("%d\n", maxflow);
        for(i = pre[e]; i != -1; i = pre[p[i].u])
            minflow = min(minflow, p[i].flow);
        for(i = pre[e]; i != -1; i = pre[p[i].u]){
            p[i].flow -= minflow;
            p[i ^ 1].flow += minflow;
        }
        mincost += d[e] * minflow;
        maxflow += minflow;
    }
    //printf("%d\n", maxflow);
    if(maxflow < all) printf("impossible\n");
    else printf("%d\n", sum + mincost);
}
int main(void)
{
    int TC, tc, i, n, m, j, st, ot,  a, b, x, y;
    scanf("%d", &TC);
    for(tc = 1; tc <= TC; tc++){
        scanf("%d%d%d%d", &n, &m, &st, &ot);
        s = 0;  e = n + 1;
        init();
        sum = all = 0;
        while(m--){
            scanf("%d%d%d%d", &x, &y, &a, &b);
            if(a <= b){
                sum += a;
                add(y, x, 1, b - a);
                out[x] ++;  in[y] ++;
            }
            else{
                sum += b;
                add(x, y, 1, a - b);
               // out[x] ++;  in[y] ++;
            }
        }
        in[st] ++;   out[ot]++;
        for(i = 1; i <= n; i++){
            if(in[i] >= out[i]){
                add(s, i, in[i] - out[i], 0);
            }
            else {
                add(i, e, out[i] - in[i], 0);
                all += (out[i] - in[i]);
            }
        }
//        for(i = s; i <= e; i++){
//            printf("%d:\n", i);
//            for(j = head[i]; j != -1; j = p[j].next){
//                printf("%d %d %d\n", p[i].v, p[i].flow, p[i].cost);
//            }
//        }
        printf("Case %d: ", tc);
        mcmf();
    }
    return 0;
}
