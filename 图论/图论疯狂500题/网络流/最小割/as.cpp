#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 110;
const int M = 1010;
const double INF = 1e8;
const double eps = 1e-7;

struct node
{
    int u, v;
    double c;
}e[M*4];

int s, t, n, m, tot, d[N], que[N], h[N], level[N], nxt[M*4];
bool visit[N], map[N][N];

double min(double x, double y)
{
    return  x < y ? x : y;
}

void add(int u, int v, double c)
{
    e[tot].u = u;
    e[tot].v = v;
    e[tot].c = c;
    nxt[tot] = h[u];
    h[u] = tot++;
}

bool bfs(int s, int t)
{
    int u, v, head, tail, p;
    head = tail = 0;
    que[0] = s;
    memset(level, 0, sizeof(level));
    memset(visit, false, sizeof(visit));
    level[s] = 0;
    visit[s] = true;
    while(head <= tail)
    {
        u = que[head++];
        p = h[u];
        while(p != -1)
        {
            v = e[p].v;
            if(!visit[v] && e[p].c>0)
            {
                level[v] = level[u]+1;
                visit[v] = true;
                que[++tail] = v;
            }
            if(visit[t])  return  true;
            p = nxt[p];
        }
    }
    return  false;
}

double dinic_dfs(double delta, int u)
{
    int p, v;
    double tmp, sum = 0.0;
    if(u == t)  return  delta;
    p = h[u];
    while(p != -1)
    {
        v = e[p].v;
        if(level[u]+1==level[v] && e[p].c>0)
        {
            tmp = dinic_dfs(min(delta, e[p].c), v);
            sum += tmp;
            delta -= tmp;
            e[p].c -= tmp;
            e[p^1].c += tmp;
        }
        p = nxt[p];
    }
    return  sum;
}

double Max_flow(int s, int t)
{
    double ans = 0.0;
    while(bfs(s, t))
        ans += dinic_dfs(INF, s);
    return  ans;
}

void dfs(int u)
{
    int p = h[u];
    visit[u] = true;
    while(p != -1)
    {
        if(e[p].c>eps && !visit[e[p].v])  dfs(e[p].v);
        p = nxt[p];
    }
}

int main()
{
  // freopen("in.txt", "r", stdin);
    int i, j, a, b, ans;
    double l, r, mid, U, Cut, tmp;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        memset(map, false, sizeof(map));
        memset(d, 0, sizeof(d));
        for(i = 0; i < m; i++)
        {
            scanf("%d%d", &a, &b);
            map[a][b] = true;
            d[a]++;
            d[b]++;
        }
        if(m == 0)
        {
            printf("1\n1\n");
            return  0;
        }
        l = 0.0;
        r = m;
        s = 0;
         t = n+1;
        U = m;
        while(r-l >= 1.0/n/n)
        {
            mid = (l+r) / 2;
            tot = 0;
            memset(h, -1, sizeof(h));
            for(i = 1; i <= n; i++)
            {
                add(s, i, U);
                add(i, s, 0.0);
                add(i, t, U+2*mid-(double)d[i]);
                add(t, i, 0.0);
            }
            for(i = 1; i <= n; i++)
                for(j = 1; j <= n; j++)
                    if(map[i][j])
                    {
                        add(i, j, 1.0);
                        add(j, i, 1.0);
                    }
            Cut = Max_flow(s, t);
            tmp = (U*n-Cut) / 2;
            printf("%f %f\n", mid, tmp);

            if(tmp > eps)  l = mid;
            else  r = mid;
        }
        tot = 0;
        memset(h, -1, sizeof(h));
        for(i = 1; i <= n; i++)
        {
            add(s, i, U);
            add(i, s, 0.0);
            add(i, t, U+2*l-(double)d[i]);
            add(t, i, 0.0);
        }
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                if(map[i][j])
                {
                    add(i, j, 1.0);
                    add(j, i, 1.0);
                }
        Cut = Max_flow(s, t);
        ans = 0;
        memset(visit, false, sizeof(visit));
        dfs(s);
        for(ans=0,i=1; i <= n; i++)
            if(visit[i])
                ans++;
        printf("%d\n", ans);
        for(i = 1; i <= n; i++)
            if(visit[i])
                printf("%d\n", i);
    }
    return 0;
}
