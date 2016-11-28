#include <cstdio>
#include <cstring>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 210
#define M 84000
#define LL __int64
#define INF 0x3f7f7f7f
int head[N], pre[N], in[N], person[N], d[N], s, e, no, n, m, sum[N];
bool vis[N];
struct point{
    int u, v, flow, cost, next;
    point(){};
    point(int x, int y, int z, int w, int c):u(x), v(y), next(z), flow(w), cost(c){};
}p[M];
struct record{
    int x, y, w;
    record(){};
    record(int u, int v, int z):x(u), y(v), w(z){};
}reca[N], recb[N];


int caldis(int i, int j){
    return abs(reca[i].x - recb[j].x) + abs(reca[i].y - recb[j].y) + 1;
}
void init(){
    memset(head, -1, sizeof(head));
    memset(sum, 0, sizeof(sum));
    memset(in, 0, sizeof(in));
    no = 0;
}

void add(int x, int y, int w, int c){
    p[no] = point(x, y, head[x], w, c); head[x] = no++;
}

int spfa(){
    int i, x, y;
    memset(d, 0x3f, sizeof(d));
    memset(pre, -1, sizeof(pre));
    memset(vis, false, sizeof(vis));
    queue<int>q;

    d[e] = 0;   q.push(e);
    vis[e] = true;      in[e] ++;
    while(!q.empty()){
        x = q.front();  q.pop(); vis[x] = false;
        for(i = head[x]; i != -1; i = p[i].next){
            y = p[i].v;
            if(p[i].flow && d[y] > d[x] + p[i].cost){
                d[y] = d[x] + p[i].cost;
                pre[y] = i;
                if(vis[y])  continue;
                vis[y]  = true;        q.push(y);   in[y] ++;
                if(in[y] > e)   return y;
            }
        }

    }
    return -1;
}
void mcmf(int x){
    int t = pre[x], i, nowflow = INF;
    bool flag = true;
    //printf("!!!");
    for(i = pre[x]; i != t || flag; i = pre[p[i].u]){
        nowflow = min(nowflow, p[i].flow);
        flag = false;
       // printf("!!!!!%d\n", nowflow);
    }
    for(i = pre[x], flag = true; i != t || flag; i = pre[p[i].u]){
        p[i].flow -= nowflow;
        p[i ^ 1].flow += nowflow;
        flag = false;
    }
}

int main(void)
{
    int i, j, x, y, z, now;
    while(scanf("%d%d", &n, &m) != EOF){
        init();
        s = 0;   e= n + m + 1;
        for(i = 1; i <= n; i++)
            scanf("%d%d%d", &reca[i].x, &reca[i].y, &reca[i].w);
        for(i = 1; i <= m; i++)
            scanf("%d%d%d", &recb[i].x, &recb[i].y, &recb[i].w);
        for(i = 1; i <= n; i++){
            for(j = 1; j <= m; j++){
                scanf("%d", &x);    sum[j] += x;
                y = caldis(i, j);
                add(i, n + j, INF - x, y);
                add(n + j, i, x, -y);
            }
        }
        for(i = 1; i <= m; i++){
            add(n + i, e, recb[i].w - sum[i], 0);
            add(e, n + i, sum[i], 0);
        }

//        printf("DEBUG:\n");
//        for(i = s; i <= e; i++){
//            printf("%d:\n", i);
//            for(j = head[i]; j != -1; j = p[j].next){
//                printf("%d  %d  %d\n", p[j].v, p[j].flow, p[j].cost);
//            }
//        }
        now = spfa();
        if(now == -1) {
            printf("OPTIMAL\n");
            continue;
        }
        else {
            printf("SUBOPTIMAL\n");
            memset(vis, 0, sizeof(vis));
            while(!vis[now]){
                vis[now] = true;
                now = p[pre[now]].u;
                //printf("%d\n", now);
            }
           // system("pause");
            mcmf(now);
            for(i = 1; i <= n; i++){
                for(j = 1; j <= m; j++){
                    printf("%d%c", p[2 * ((i - 1) * m + j - 1) + 1].flow, j == m ? '\n':' ');
                }
            }
        }
    }
    return 0;
}
