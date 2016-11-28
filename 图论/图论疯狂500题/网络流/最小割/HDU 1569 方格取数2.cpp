#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

#define N 4004
#define M 55555
#define LL __int64
#define INF 0x3f7f7f7f
int head[N], cur[N], st[M], d[N], s, e, no;
struct point{
    int u, v, next, flow;
    point(){};
    point(int x, int y, int z, int w): u(x), v(y), next(z),flow(w){};
}p[M];

void add(int x, int y, int z){
    p[no] = point(x, y, head[x], z);    head[x] = no++;
    p[no] = point(y, x, head[y], 0);    head[y] = no++;
}

void init(){
    memset(head, -1, sizeof(head));
    no = 0;
}

bool bfs(){
    int i, x, y;
    memset(d, -1, sizeof(d));
    queue<int>q;
    d[s] = 0;   q.push(s);

    while(!q.empty()){
        x = q.front();  q.pop();
        for(i = head[x]; i != -1; i = p[i].next){
            y = p[i].v;
            if(p[i].flow && d[y] < 0){
                d[y] = d[x] + 1;
                if(y == e)  return true;
                q.push(y);
            }
        }
    }
    return false;
}

int dinic(){
    int nowflow, i, top, x = s, loc, maxflow = 0;
    while(bfs()){
        for(i = s; i <= e; i++) cur[i] = head[i];
        top = 0;
        while(true){
            nowflow = INF;
            if(x == e){
                for(i = 0; i < top; i++){
                    if(nowflow > p[st[i]].flow){
                        nowflow = p[st[i]].flow;
                        loc = i;
                    }
                }
                for(i = 0; i < top; i++){
                    p[st[i]].flow -= nowflow;
                    p[st[i] ^ 1].flow += nowflow;
                }
                top = loc;
                x = p[st[top]].u;
                maxflow += nowflow;
            }

            for(i = cur[x]; i != -1; i = p[i].next)
                if(p[i].flow && d[p[i].v] == d[x] + 1)   break;
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
    int n, m, all, i, j, w, sum, x;
    while(scanf("%d%d", &n, &m) != EOF){
        init();
        sum = 0;
        s = 0;  e = n * m  + 1;
        all = n * m;
        for(i = 1; i <= n; i++){
            for(j = 1; j <= m; j++){
                x = (i - 1) * m + j;
                scanf("%d", &w);    sum += w;
                if((i + j) & 1)
                {
                    if(i > 1) add(x, (i - 2) * m + j, INF);
                    if(i < n) add(x, i * m + j, INF);
                    if(j > 1) add(x, x - 1, INF);
                    if(j < m) add(x, x + 1, INF);
                    add(s, x, w);
                }
                else add(x, e, w);
            }
        }

        printf("%d\n", sum - dinic());

    }
    return 0;
}
