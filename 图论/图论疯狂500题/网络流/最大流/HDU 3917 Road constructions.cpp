#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

#define N 5005
#define M 9200004
#define LL __int64
#define INF 0x3f7f7f7f
struct point
{
    int u, v, flow, next;
    point(){};
    point(int x, int y, int z, int w): u(x), v(y), flow(z), next(w){};
}p[M], rec[N];
int head[N], cur[N], d[N], st[M], cnt[N], s, e, no, n, m, k, sum;

void init(){
    memset(head, -1, sizeof(head));
    memset(cnt, 0, sizeof(cnt));
    no = 0;
}

void add(int x, int y, int z){
    p[no] = point(x, y, z, head[x]);    head[x] = no++;
}

void build()
{
    int i, j;
    for(i = 1; i <= k; i++){
        for(j = i + 1; j <= k; j++){
            //if(rec[i].flow == rec[j].flow)  continue;
            //if(rec[i].v == 1 || rec[j].v == 1)  continue;
            if(rec[i].v == rec[j].u){
                add(rec[i].flow , rec[j].flow, INF); add( rec[j].flow,rec[i].flow, 0);
            }
            else if(rec[i].u == rec[j].v){
                add(rec[j].flow, rec[i].flow, INF); add(rec[i].flow,rec[j].flow, 0);
            }
        }
    }
    for(i = 1; i <= m; i++){

        if(cnt[i] >= 0){
            sum += cnt[i];
            add(s, i, cnt[i]);  add(i, s, 0);
        }
        else {
            add(i, e, -cnt[i]); add(e, i, 0);
        }

    }
}

bool bfs()
{
    int i, x, y;
    memset(d, -1, sizeof(d));
    queue<int>q;
    d[s] = 0;   q.push(s);
    while(!q.empty()){
        x = q.front();  q.pop();
        for(i = head[x]; i != -1; i = p[i].next){
            if(p[i].flow && d[y = p[i].v] < 0){
                d[y] = d[x] + 1;
                if(y == e)  return true;
                q.push(y);
            }
        }
    }
    return false;
}

int dinic()
{
    int i, top, x = s,  maxflow = 0, nowflow, loc;
    while(bfs()){
        for(i = s; i <= e; i++) cur[i] = head[i];
        top = 0;
        while(true){
            if(x == e){
                nowflow = INF;
                for(i = 0; i < top; i++){
                    if(p[st[i]].flow < nowflow){
                        nowflow = p[st[i]].flow;
                        loc = i;
                    }
                }
                for(i = 0; i < top; i++){
                    p[st[i]].flow -= nowflow;
                    p[st[i]^1].flow += nowflow;
                }
                maxflow += nowflow;
                top = loc;  x = p[st[top]].u;

            }
            for(i = cur[x]; i != -1; i = p[i].next){
                if(p[i].flow && d[p[i].v] == d[x] + 1)  break;
            }
            cur[x] = i;
            if(i != -1){
                st[top++] = i;
                x = p[i].v;
            }
            else{
                if(!top)    break;
                d[x] = -1;
                x = p[st[--top]].u;
            }
        }
    }
    return maxflow;

}
int main(void)
{
    //freopen("in.txt", "r", stdin);
    int i, x, y, j, ans;
    while(scanf("%d%d", &n, &m) && (m || n)){
        init();
        s = sum = 0;  e = m + 1;
        for(i = 1; i <= m; i++){
            scanf("%d", &x);
            cnt[i] += x;
        }
        scanf("%d", &k);
        for(i = 1; i <= k; i++){
            scanf("%d%d%d%d", &rec[i].u, &rec[i].v, &rec[i].flow, &rec[i].next);
            cnt[rec[i].flow] -= rec[i].next;
        }
        build();
        ans = sum - dinic();
       // if(ans < 0) ans = 0;
        printf("%d\n", ans);
    }
    return 0;
}
