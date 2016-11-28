//thinkagain
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include <queue>
using namespace std;
#define N 404
#define M 2004
#define S 100005
#define INF 0x3f3f3f3f
struct point
{
    int u, v, flow, cost, next;
}p[M];
struct lir
{
    int u, v, w;
}lir[N];

int head[N], cur[N], d[N], pre[N], f[S], dir[N], s, e, no = 0;
bool v[N];

void init()
{
    no = 0;memset(head, -1, sizeof(head));
    memset(f, 0, sizeof(f));
}

void add(int x, int y, int z, int cost)
{
    p[no].u = x;    p[no].v = y;    p[no].flow = z;
    p[no].cost = cost;      p[no].next = head[x];   head[x] = no++;
    p[no].u = y;    p[no].v = x;    p[no].flow = 0;
    p[no].cost = - cost;    p[no].next = head[y];   head[y] = no++;
}

bool spfa()
{
    int i, x, y, now;
    queue<int>q;
    for(i = s; i <= e; i++)
    {
        v[i] = false;   d[i] = INF; pre[i] = -1;
    }
    q.push(s);  d[s] = 0;   v[s] = true;
    while(!q.empty())
    {
        x = q.front();  q.pop();
        v[x] = false;
        for(i = head[x]; i != -1; i = p[i].next)
        {
            y = p[i].v;
            if(p[i].flow && d[y] > d[x] + p[i].cost)
            {
                d[y] = d[x] + p[i].cost;
                pre[y] = i;
                if(v[y])    continue;
                q.push(y);  v[y] = true;
            }
        }
    }
    return d[e] != INF;
}

int mcmf()
{
    int x, y, i, minflow, mincost = 0, sumflow = 0;
    while(spfa())
    {
        minflow = INF;
        for(i = pre[e]; i != -1; i = pre[p[i].u])
        {
            minflow = min(p[i].flow, minflow);
        }
        sumflow += minflow;
        for(i = pre[e]; i != -1; i = pre[p[i].u])
        {
            p[i].flow -= minflow;
            p[i ^ 1].flow += minflow;
        }
        mincost += d[e] * minflow;
    }
    return mincost;
}
int main()
{
    int TC, i, k, n, a, b, w, tot;
    scanf("%d", &TC);
    while(TC--)
    {
        init(); tot = 0;
        scanf("%d%d", &n, &k);
        for(i = 1; i <= n; i++)
        {
            scanf("%d%d%d", &lir[i].u, &lir[i].v, &lir[i].w);
            dir[++tot] = lir[i].u;  dir[++tot] = lir[i].v;
        }
        sort(dir + 1, dir + tot + 1);
        for(i = 1; i <= tot; i++)
        {
            if(dir[i] == dir[i - 1])    continue;
            dir[++no] = dir[i];   f[dir[i]] = no;
        }
        tot = no;   no = 0;
        s = 0;  e = tot + 1;
        for(i = s; i < e; i++)  add(i, i + 1, k, 0);
        for(i = 1; i <= n; i++)
        {
            add(f[lir[i].u], f[lir[i].v], 1, -lir[i].w);
        }
        printf("%d\n", -mcmf());

    }
	return 0;
}
