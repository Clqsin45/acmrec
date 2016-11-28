#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <queue>
using namespace std;

#define MAX 222
#define INF 0x3f7f7f7f
int head[MAX], d[MAX], vis[MAX], pre[MAX];
int n, m, s, e, no;
struct point
{
    int u, v, cost, flow, next;
}p[MAX * MAX];

struct location
{
    int x, y;
}man[MAX], h[MAX];

void add(int x, int y, int z, int ct)
{
    p[no].u = x;    p[no].v = y;    p[no].cost = ct;
    p[no].flow = z;
    p[no].next = head[x];   head[x] = no++; return;
}
bool spfa()
{
    queue<int>q;
    int x, y, now, i;
    for(i = s; i <= e; i++)
    {
        d[i] = INF; vis[i] = 0;   pre[i] = -1;
    }
    q.push(s);  d[s] = 0;   vis[s] = 1;
    while(!q.empty())
    {
        x = q.front();  q.pop();
        //printf("%d\n", x);
        vis[x] = 0;
        for(i = head[x]; i != -1; i = p[i].next)
        {
            y = p[i].v;
            //printf("%d  %d  %d\n", y, d[y], p[i].flow);
            if(p[i].flow && d[y] > d[x] + p[i].cost)
            {
                d[y] = d[x] + p[i].cost;
                //printf("%d\n", d[y]);
                pre[y] = i;
                if(!vis[y])
                {
                    q.push(y);
                    vis[y] = 1;
                }
            }
        }
    }
    return (d[e] != INF);


}

int mcmf()
{
    int maxflow = 0, i, minflow, mincost = 0;
    while(spfa())
    {
        minflow = INF + 1;
        for(i = pre[e]; i != -1; i = pre[p[i].u])
        {
            if(p[i].flow < minflow)
                minflow = p[i].flow;
        }
        for(i = pre[e]; i != -1; i = pre[p[i].u])
        {
            p[i].flow -= minflow;
            p[i ^ 1].flow += minflow;
        }
        mincost += d[e] * minflow;
       // printf("%d\n", mincost);
    }
    return mincost;
}

int main(void)
{
    int cm, ch, i, j, temp;
    char c;
    while(scanf("%d%d", &n, &m) && (n || m))
    {
        memset(head, -1, sizeof(head));
        cm = ch = no = 0;
        s = 0;
        getchar();
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= m; j++)
            {
                scanf("%c", &c);
                //printf("%c\n", c);
                if(c == 'm')
                {
                    man[++cm].x = i;    man[cm].y = j;
                }
                else if(c == 'H')
                {
                    h[++ch].x = i;  h[ch].y = j;
                }
            }
            getchar();
        }
        e = cm + ch + 1;
        for(i = 1; i <= cm; i++)
        {
            for(j = 1; j <= ch; j++)
            {
                temp = abs(man[i].x - h[j].x) + abs(man[i].y - h[j].y);
                add(i, cm + j, 1, temp);
                add(cm + j, i, 0, -temp);
            }
            add(s, i, 1, 0);
            add(i, s, 0, 0);
        }
        for(i = 1; i <= ch; i++)
        {
            add(i + cm, e, 1, 0);
            add(e, i + cm, 0, 0);
        }

        int ans = mcmf();
        printf("%d\n", ans);
    }
    return 0;
}
