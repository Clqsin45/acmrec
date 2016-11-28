#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

#define N 1004
#define M 3004
#define LL __int64
#define INF 0x3f7f7f7f
struct point
{
    int u, v, next, flow;
    point(){};
    point(int x, int y, int z, int w): u(x),v(y),next(z),flow(w){};
}p[M];
int head[N], d[N], st[M], cur[N], s, e, no;

void init()
{
    memset(head, -1, sizeof(head));
    no = 0;
}

void add(int x, int y, int z )
{
    p[no] = point(x, y, head[x], z);    head[x] = no++;
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
        for(i = head[x] ; i != -1; i = p[i].next)
        {
            if(p[i].flow && d[y = p[i].v] == -1)
            {
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
    int i, x = s, y, top, nowflow, maxflow = 0, loc;
    while(bfs())
    {
        top = 0;
        for(i = s; i <= e; i++) cur[i] = head[i];
        while(true)
        {
            if(x == e)
            {
                nowflow = INF;
                for(i = 0; i < top; i++)
                {
                    if(p[st[i]].flow < nowflow)
                    {
                        nowflow = p[st[i]].flow;
                        loc = i;
                    }
                }
                for(i = 0; i < top; i++)
                {
                    p[st[i]].flow -= nowflow;
                    p[st[i]^1].flow += nowflow;
                }
                maxflow += nowflow;
                top = loc;    x = p[st[top]].u;
            }
            for(i = cur[x]; i != -1; i = p[i].next)
                if(p[i].flow && d[p[i].v] == d[x] + 1) break;
            cur[x] = i;
            if(i != -1)
            {
                st[top++] = i;
                x = p[i].v;
            }
            else
            {
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
    int TC, tc, i, j, x, y, z, n, m;
    scanf("%d", &TC);
    for(tc = 1; tc <= TC; tc++)
    {
        scanf("%d%d", &n, &m);
        init();
        while(m--)
        {
            scanf("%d%d%d", &x, &y, &z);
            add(x, y, z);   add(y, x, 0);
        }
        s = 1;  e = n;
        printf("Case %d: %d\n", tc, dinic());
    }
    return 0;
}
