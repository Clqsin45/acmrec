#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

#define T 55
#define N 122
#define M 4004
#define LL __int64
#define INF 0x3f7f7f7f
struct point
{
    int u, v, flow, next;
    point(){};
    point(int x, int y, int z, int w):u(x), v(y), flow(z), next(w){};
}p[M * 20], r[M], fr[M];
int head[N], hp[T], fp[T], no, ct, d[N], fd[N], cur[N], n, k, s, e, st[M];
int f[T][T];

void init()
{
    memset(head, -1, sizeof(head));
    memset(hp, -1, sizeof(hp));
    memset(fp, -1, sizeof(fp));
    memset(f, 0, sizeof(f));
    no = ct = 0;
}
void add(int x, int y, int z)
{
    p[no] = point(x, y, z, head[x]);    head[x] = no++;
}
void addp(int x, int y)
{
    r[ct] = point(x, y, 0, hp[x]);  hp[x] = ct;
    fr[ct] = point(y, x, 0, fp[y]); fp[y] = ct++;
}

void bfs(int *h, point *rec, int *dis, int sor)
{
    int i, x, y;
    memset(dis, -1, sizeof(dis));
    dis[sor] = 0;
    queue<int>q;
    q.push(sor);

    while(!q.empty())
    {
        x = q.front();  q.pop();
        for(i = h[x]; i != -1; i = rec[i].next)
        {
            if(dis[y = rec[i].v] < 0)
            {
                dis[y] = dis[x] + 1;
                q.push(y);
            }
        }
    }
}

void build()
{
    int i, j, x, y;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(f[i][j])
            {
                add(i + n, j, INF); add(j, i + n, 0);
            }
        }
        if(i == 1 || i == n)    continue;
        if(d[i] + fd[i] <= k)
        {
            add(i, i + n, 1);
            add(i + n, i, 0);
        }
    }
    add(1, 1 + n, INF);   add(1 + n, 1, 0);
    add(n, n + n, INF);   add(n + n, n, 0);
}

bool find()
{
    int i, x, y;
    memset(d, -1, sizeof(d));
    queue<int>q;
    q.push(s);  d[s] = 0;
    while(!q.empty())
    {
        x = q.front();  q.pop();
        for(i = head[x]; i != -1; i = p[i].next)
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
    int i, top, nowflow, maxflow = 0, x = s, loc;
    while(find())
    {
        for(i = s; i <= e; i++) cur[i] = head[i];
        top = 0;
        while(true)
        {
            if(x == e)
            {
                nowflow = INF;
                for(i = 0; i < top; i++)
                {
                    if(nowflow > p[st[i]].flow)
                    {
                        nowflow = p[st[i]].flow;
                        loc = i;
                    }
                }
                for(i = 0 ; i < top; i++)
                {
                    p[st[i]].flow -= nowflow;
                    p[st[i] ^ 1].flow += nowflow;
                }
                maxflow += nowflow;
                top = loc;
                x = p[st[top]].u;
            }
            for(i = cur[x]; i != -1; i =p[i].next)
            {
                if(p[i].flow && d[p[i].v] == d[x] + 1)  break;
            }
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
    int k, x, i, y, j, m;
    while(scanf("%d%d%d", &n, &m, &k) && (n || m || k))
    {
        s = 1;  e = 2 * n;
        init();

        while(m--)
        {
            scanf("%d%d", &x, &y);
            addp(x, y);
            f[x][y] = 1;
        }
        bfs(hp, r, d, 1);
       // printf("!!!\n");
        bfs(fp, fr, fd, n);

        build();
        printf("%d\n", dinic());
    }
    return 0;
}
