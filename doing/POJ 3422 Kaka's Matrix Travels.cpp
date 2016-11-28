#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

#define MAX 5005
#define INF 0x3f7f7f7f

struct point
{
    int u, v, flow, cost, next;
} p[MAX<<3];

int dis[MAX], vis[MAX], head[MAX], pre[MAX];
int no, s, e;
void add(int x, int y, int z, int c)
{
    p[no].u = x;    p[no].v = y;
    p[no].flow = z; p[no].cost = c;
    p[no].next = head[x];   head[x] = no++;
}

inline int re(int x)
{
    return x - (x & 1) + !(x & 1);
}

bool spfa()
{
    int i, f, r, x,y ;
    memset(dis, -1, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    queue<int>q;
    dis[s] = 0;  vis[s] = 1;
    q.push(s);
    while(f < r)
    {
        x = q.front();
        q.pop();
        for(i = x; i != -1; i = p[i].next)
        {
            y = p[i].v;
            if(p[i].flow && dis[y] < dis[x] + p[i].cost)
            {
                dis[y] = dis[x] + p[i].cost;
                pre[y] = i;
                if(!vis[y])
                {
                    vis[y] = 1;
                    q.push(y);
                }
            }
        }
        vis[x] = 0;
    }
    if(dis[e] == -1)    return false;
    return true;
}

int mcmf()
{
    int i, x,  y, maxflow , minflow, maxcost = 0, li;
    while(spfa())
    {
        for(i = e; i != -1; i = pre[re(li)])
        {
            li = pre[x];
            p[li].flow -= 1;
            p[re(li)].flow += 1;

            maxcost += p[li].cost;
        }
    }


}
int main(void)
{
    int map[55][55];
    int i, j, n, k, t, x, y;
    memset(head, -1, sizeof(head));
    memset(vis, 0, sizeof(vis));
    scanf("%d%d", &n, &k);
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &t);
            x = (i - 1) * n + j;
            x = x * 2 - 1;
            y = x + 1;

            add(x, y, 1, t);
            add(y, x, 0, -t);
            add(x, y, k, 0);
            add(y, x, 0, 0);

            if(i < n)
            {
                add(y, x + 2 * n, k, 0);
                add(x + 2 * n, y, 0, 0);
            }
            if(j < n)
            {
                add(y, y + 1, k, 0);
                add(y + 1, y, 0, 0);
            }
        }
    }

    s = 0;  e = 2 * n * n;


    add(0, 1, k, 0);
    add(1, 0, 0, 0);

    int ans = mcmf();
    printf("%d\n", ans);
    return 0;
}
