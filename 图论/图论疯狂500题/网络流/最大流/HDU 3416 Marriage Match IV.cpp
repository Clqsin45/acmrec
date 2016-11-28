#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 1004
#define M 320000
#define LL __int64
#define INF 0x3f7f7f7f

struct point
{
    int u, v, flow, next;
    point(){};
    point(int x, int y, int z, int w):u(x), v(y), flow (z), next(w){};
}p[M], r[M];
int head[N], hp[N], st[M], d[N], cur[N], v[N], s, e, no, ct, n, m;

void addp(int x,int y, int z)
{
    r[ct] = point(x, y, z, hp[x]);    hp[x] = ct++;
}

void add(int x,int y, int z)
{
    p[no] = point(x, y, z, head[x]);    head[x] = no++;
}

void init()
{
    memset(hp, -1, sizeof(hp)); memset(head, -1, sizeof(head));
    no = ct = 0;
}

void spfa()
{
    int i, x, y;
    memset(v, 0, sizeof(v));
    queue<int>q;

    for(i = 1; i <= n; i++) d[i] = INF;
    q.push(s);  d[s] = 0;   v[s] = 1;

    while(!q.empty())
    {
        x = q.front();  q.pop();    v[x] = 0;
        for(i = hp[x]; i != -1; i = r[i].next)
        {
            y = r[i].v;
            if(d[y] > d[x] + r[i].flow)
            {
                d[y] = d[x] + r[i].flow;
                if(!v[y])
                {
                    q.push(y);  v[y] = true;
                }
            }
        }
    }
}

void build()
{
    int i, j, x, y;
    for(i = 0; i < ct; i++)
    {
        x = r[i].u; y = r[i].v;
        if(d[x] + r[i].flow == d[y])
        {
            add(x, y, 1);   add(y, x, 0);
        }
    }
}

bool bfs()
{
    int x, y, i;
    memset(d, -1, sizeof(d));
    queue<int>q;
    d[s] = 0;   q.push(s);

    while(!q.empty())
    {
        x = q.front();  q.pop();
        for(i = head[x] ; i != -1; i = p[i].next)
        {
            if(p[i].flow && d[y = p[i].v] < 0)
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
    int top, x = s, nowflow, maxflow = 0, loc, i;
    while(bfs())
    {
        for(i = 1; i <= n; i++) cur[i] = head[i];
        top = 0;
        //printf("")
        while(true)
        {
            if(x == e)
            {
                 nowflow = INF;
                 for(i =0 ; i < top; i++)
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
                 top = loc;
                 x = p[st[top]].u;
            }
            for(i = cur[x]; i != -1; i = p[i].next)
                if(p[i].flow && d[p[i].v] == d[x] + 1)  break;
            cur[x] = i;
            if(i != -1)
            {
                st[top++] = i;
                x=  p[i].v;
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
    int TC, i, x, y, z;
    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%d%d", &n, &m);
        init();
        for(i = 1; i <= m; i++)
        {
            scanf("%d%d%d", &x, &y, &z);
            addp(x, y, z);
        }
        scanf("%d%d", &s, &e);
        spfa();

        build();//printf("!!!!!!!!!!!\n");
        printf("%d\n", dinic());
    }

    return 0;
}
