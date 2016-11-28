#include<stdio.h>
#include<string.h>
#include<queue>
#include <cstdlib>
using namespace std;
#define maxn 222
#define maxm maxn * maxn
#define inf 1000000000

int min(int a, int b)
{
    return a < b ? a : b;
}
struct E
{
    int u, v, next, c, w;
}edge[maxm<<3];

int head[maxn], tot;
int n, m;
int S, T;

void add(int s, int t, int c, int cc, int w)
{
    edge[tot].u = s;
    edge[tot].v = t;
    edge[tot].c = c;
    edge[tot].w = w;
    edge[tot].next = head[s];
    head[s] = tot++;

    edge[tot].u = t;
    edge[tot].v = s;
    edge[tot].c = cc;
    edge[tot].w = -w;
    edge[tot].next = head[t];
    head[t] = tot++;
}

void init()
{
    tot = 0;
    memset(head, -1, sizeof(head));
}


int pre[maxn];
int dis[maxn];
int in[maxn];
bool vis[maxn];

int spfa(int s, int n)
{
    int i, u, v;
    for(i = 0; i <= n; i++)
        dis[i] = inf, pre[i] = -1, vis[i] = 0, in[i] = 0;
    queue<int> q;
    dis[s] = 0; vis[s] = 1; in[s]++; q.push(s);
    while(!q.empty())
    {
        u = q.front(); q.pop(); vis[u] = 0;
        for(i = head[u]; i != -1; i = edge[i].next)
        {
            v = edge[i].v;
            if(edge[i].c && dis[v] > dis[u] + edge[i].w)
            {
                dis[v] = dis[u] + edge[i].w;
                pre[v] = i;
                if(!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                    in[v]++;
                    if(in[v] >= n)
                        return v;
                }
            }
        }
    }
    return -1;
}

int ax[maxn], ay[maxn], ac[maxn], bx[maxn], by[maxn], bc[maxn];
int b[maxn];

int Dis(int i, int j)
{ return abs(ax[i] - bx[j]) + abs(ay[i] - by[j]) + 1; }

void update(int p) // 更新费用流
{
    int u = pre[p], i;
    int aug;
    aug = min(aug, edge[u].c);
    for(i = pre[edge[u].u]; i != u; i = pre[edge[i].u])
        aug = min(aug, edge[i].c);
    edge[u].c -= aug; edge[u^1].c += aug;
    for(i = pre[edge[u].u]; i != u; i = pre[edge[i].u])
    {
        edge[i].c -= aug;
        edge[i^1].c += aug;
    }
}

void solve()
{
    int p = spfa(T, T);
    int i, j;
    if(p == -1)
    {
        printf("OPTIMAL\n");
        return;
    }
    printf("SUBOPTIMAL\n");
    memset(vis, 0, sizeof(vis));
    while(!vis[p])
    {
        vis[p] = 1;
        p = edge[pre[p]].u;
    }
    update(p);
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j < m; j++)
            printf("%d ", edge[(((i-1)*m+j-1)*2)^1].c);
        printf("%d\n", edge[(((i-1)*m+j-1)*2)^1].c);
    }
}

int main()
{
    int i, j;
    int z;
    while( ~scanf("%d%d", &n, &m))
    {
        S = 0; T = n+m+1;
        init();
        memset(b, 0, sizeof(b));
        for(i = 1; i <= n; i++)
            scanf("%d%d%d", &ax[i], &ay[i], &ac[i]);
        for(i = 1; i <= m; i++)
            scanf("%d%d%d", &bx[i], &by[i], &bc[i]);
        for(i = 1; i <= n; i++)
            for(j = 1; j <= m; j++)
            {
                scanf("%d", &z);
                b[j] += z;
                add(i, j+n, ac[i]-z, z, Dis(i, j));
            }
        for(i = 1; i <= m; i++)
            add(i+n, T, bc[i]-b[i], b[i], 0);

        printf("DEBUG:\n");
        for(i = S; i <= T; i++){
            printf("%d:\n", i);
            for(j = head[i]; j != -1; j = edge[j].next){
                printf("%d  %d  %d\n", edge[j].v, edge[j].c, edge[j].w);
            }
        }
        solve();
    }
    return 0;
}
