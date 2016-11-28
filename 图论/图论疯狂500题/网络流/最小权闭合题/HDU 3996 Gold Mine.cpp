#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 2540
#define M 425004
#define R 125004
#define LT 103
#define LL __int64
#define INF 0x3f7f7f7f7f7fLL
struct point{
    int u, v, next;
    LL flow;
    point(){};
    point(int x, int y, LL w, int z):u(x), v(y), flow(w), next(z){};
}p[M];
struct record{
    int now, lay, num;
}rec[R];

int head[N], cur[N], d[N], su[LT],  no, s, e, st[M], n, m, ct, com;
LL val[N];

void add(int x, int y, LL z){
    p[no] = point(x, y, z, head[x]);    head[x] = no++;
    p[no] = point(y, x, 0, head[y]);    head[y] = no++;
}
void init(){
    memset(head, -1, sizeof(head));
    memset(su, 0, sizeof(su));
    no = 0;
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

LL dinic(){
    int i, top, x = s,   loc;
    LL maxflow = 0, nowflow;
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
    int TC, tc, i, j, x, y, z;
    LL dig, ear, sum;
    scanf("%d", &TC);
    for(tc = 1; tc <= TC; tc++){
        scanf("%d", &n);
        init(); ct = sum = com = 0;
        for(i = 1; i <= n; i++){
            scanf("%d", &x);
            su[i] = su[i - 1] + x;
            for(j = 1; j <= x; j++){
                scanf("%I64d%I64d", &dig, &ear);
                val[++ct] = ear - dig;
                scanf("%d", &m);
                while(m--){
                    rec[++com].now = ct;
                    scanf("%d%d", &rec[com].lay, &rec[com].num);
                }
            }
        }
        //printf("!!!\n");
        s = 0;  e = ct + 1;
        for(i = 1; i <= ct; i++){
            if(val[i] >= 0){
                sum += val[i];
                add(s, i, val[i]);
            }
            else
                add(i, e, -val[i]);
        }
        for(i = 1; i <= com; i++){
            x = rec[i].now;
            y = su[rec[i].lay - 1] + rec[i].num;
            add(x, y, INF);
        }
        printf("Case #%d: %I64d\n",  tc, sum - dinic());
    }
    return 0;
}
