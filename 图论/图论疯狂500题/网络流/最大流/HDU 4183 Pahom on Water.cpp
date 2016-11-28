#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iostream>
using namespace std;
#define T 304
#define N 610
#define M 420000
#define LL __int64
#define INF 0x3f7f7f7f
#define eps 1e-9

struct point{
    int u, v, flow, next;
    point(){};
    point(int x, int y, int w, int z):u(x), v(y), flow(w), next(z){};
}p[M];
struct record{
    int x, y, r;
    double f;
}rec[T];
int head[N], cur[N], d[N], no, s, e, st[M], n, m;

void add(int x, int y, int z){
    p[no] = point(x, y, z, head[x]);    head[x] = no++;
    p[no] = point(y, x, 0, head[y]);    head[y] = no++;
}
void init(){
    memset(head, -1, sizeof(head));
    no = 0;
}

bool cross(int i, int j){
    int temp = (rec[i].x - rec[j].x)*(rec[i].x - rec[j].x) + (rec[i].y - rec[j].y)*(rec[i].y - rec[j].y);
    if(temp <= (rec[i].r + rec[j].r)*(rec[i].r + rec[j].r)) return true;
    return false;
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
        for(i = 0; i <= n; i++) cur[i] = head[i];
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
    int TC, i, j, x, y;
    scanf("%d", &TC);
    while(TC--){
        scanf("%d", &n);
        for(i = 0; i < n; i++){
            init();
            scanf("%lf%d%d%d", &rec[i].f, &rec[i].x, &rec[i].y, &rec[i].r);
            if(fabs(rec[i].f - 400.0) < eps)    s = i;
            else if(fabs(rec[i].f - 789.0) < eps)   e = i;
        }
       // printf("!!!\n");
        for(i = 0; i < n; i++){
            for(j = i + 1; j < n; j++){
                if(!cross(i, j))    continue;
                //printf("%d %d\n", i, j);
                if(rec[i].f - rec[j].f > eps){
                    x = i << 1; y = j << 1;
                    add(y ^ 1, x, INF);
                }
                else if(rec[j].f - rec[i].f > eps){
                    x = i << 1;  y = j << 1;
                    add(x ^ 1, y, INF);
                }
            }
        }
        //printf("!!!!!!!!!!!!!!!\n");
        for(i = 0; i < n; i++){
            x = i << 1;
            if(i == s || i == e){
                add(x, x ^ 1, INF);
            }
            else add(x, x ^ 1, 1);
        }
        s *= 2; e *= 2;
        n *= 2;

        if(dinic() == 2){
            printf("Game is VALID\n");
        }
        else printf("Game is NOT VALID\n");
    }

    return 0;
}
