#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

#define N 2004
#define M 1000005
#define LL __int64
#define INF 0x3f7f7f7f

struct point
{
    int u, v, flow, next;
    point(){};
    point(int x, int y, int w, int z):u(x), v(y), flow(w), next(z){};
}p[M];
int f[N], a[N], head[N], cur[N], d[N], st[M], s, e, no, n, ans;
void init()
{
    memset(head, -1, sizeof(head));
    no = 0;
}

void add(int x, int y, int z)
{
    p[no] = point(x, y, z, head[x]);
    head[x] = no++;
}
void dp()
{
    int i, j;
    ans = 0;
    for(i = 1; i <= n; i++){
        f[i] = 1;
        for(j = i - 1; j > 0; j--){
            if(f[j] >= f[i] && a[j] < a[i])
                f[i] = f[j] + 1;
        }
        ans = max(ans, f[i]);
    }
    printf("%d\n", ans);
}

bool bfs()
{
    int i, x, y;
    memset(d, -1, sizeof(d));
    queue<int>q;
    d[s] = 0;   q.push(s);

    while(!q.empty())
    {
        x = q.front();  q.pop();
        //printf("%d\n", x);
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
    int top, i, x = s, maxflow = 0, nowflow, loc;
    while(bfs())
    {
        for(i = s; i <= e; i++) cur[i] = head[i];
        top = 0;
        //printf("%d\n", maxflow);
        while(true){
            if(x == e){
                nowflow = INF;
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
                maxflow += nowflow;
                top = loc;  x = p[st[top]].u;
            }
            for(i = cur[x]; i != -1; i = p[i].next)
                if(p[i].flow && d[p[i].v] == d[x] + 1)  break;
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
    int i, j;
    while(scanf("%d", &n) != EOF){
        for(i = 1; i <= n; i++) scanf("%d", &a[i]);
        dp();
        init();
        s = 0;  e = 2 * n + 1;
        for(i = 1; i <= n; i++){
            add(i, i + n, 1);   add(i + n, i, 0);
            if(f[i] == ans){
                add(i + n, e, 1);   add(e, n + i, 0);
            }
            if(f[i] == 1){
                add(s, i, 1);   add(i, s, 0);
                continue;
            }
            for(j = 1; j < i; j++){
                if(f[j] == f[i] - 1 && a[j] < a[i]){
                    add(j + n, i, 1);   add(i, j + n, 0);
                }
            }

        }


        printf("%d\n", dinic());
    }
    return 0;
}
