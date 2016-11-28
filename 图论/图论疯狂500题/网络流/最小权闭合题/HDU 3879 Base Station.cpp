#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

#define N 55010
#define M 430004
#define LL __int64
#define INF 0x3f7f7f7f
struct point{
    int u, v, flow, next;
    point(){};
    point(int x, int y, int w, int z):u(x), v(y), flow(w), next(z){};
}p[M];
int head[N], cur[N], d[N], no, s, e, st[M], n, m;

void add(int x, int y, int z){
    p[no] = point(x, y, z, head[x]);    head[x] = no++;
    p[no] = point(y, x, 0, head[y]);    head[y] = no++;
}
void init(){
    memset(head, -1, sizeof(head));
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
    int i, j, x, y, z, sum;
    while(scanf("%d%d", &n, &m) != EOF){
        s = 0;  e = n + m + 1;
        init(); sum = 0;
        for(i = 1; i <= n; i++){
            scanf("%d", &x);
            add(s, i , x);
        }
        for(i = 1; i <= m; i++){
            scanf("%d%d%d", &x, &y, &z);
            sum += z;
            add(i + n, e, z);
            add(x, i + n, INF);
            add(y, i + n, INF);
        }
        printf("%d\n", sum - dinic());
    }
    return 0;
}
