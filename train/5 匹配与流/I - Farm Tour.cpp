#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

#define MT 1004
#define MD 1000200
#define INF 0x3f7f7f7f

struct point
{
    int u, v, flow, cost, next;
}p[MD << 2];

int no, head[MT], d[MT], pre[MT], s, e, n;
bool v[MT];

void init()
{
    memset(head, -1, sizeof(head));
    no = 0; return;
}

void add(int x, int y, int z, int ct)
{
    p[no].u = x;    p[no].v = y;    p[no].flow = z;
    p[no].cost = ct;    p[no].next = head[x];   head[x] = no ++;
}

bool spfa()
{
    int i, x, y;
    queue<int>q;

    for(i = s; i <= e; i++)
    {
        d[i] = INF;   v[i] = false; pre[i] = -1;
    }

    v[s] =  true;   d[s] = 0;
    q.push(s);
    while(!q.empty())
    {
        x = q.front();  q.pop();        v[x] = false;
        for(i = head[x]; i != -1; i = p[i].next)
        {
            y = p[i].v;

            if(p[i].flow > 0 && d[y] > d[x] + p[i].cost)
            {
                d[y] = d[x] + p[i].cost;
                pre[y] = i;
                if(!v[y])
                {
                    q.push(y);
                    v[y] =  true;
                }
            }
        }
    }
    return d[e] != INF;
}

int mcmf()
{
    int maxflow = 0, i, minflow, mincost = 0;
    while(spfa())
    {
        minflow = INF + 1;
        for(i = pre[e]; i != -1; i = pre[p[i].u])
        {//printf("%d\n",i);
            if(p[i].flow < minflow) minflow = p[i].flow;

        }
        maxflow += minflow;

        for(i = pre[e]; i != -1; i = pre[p[i].u])
        {
            p[i].flow -= minflow;
            p[i ^ 1].flow += minflow;
        }

        mincost += d[e] * minflow;
        //printf("%d\n", mincost);
    }
    return mincost;
}
int main(void)
{
    int m, j, ans, x, y, z;

    while(scanf("%d%d", &n, &m) != EOF)
    {
        s = 0;  e = n;
        init();
        while(m--)
        {
            scanf("%d%d%d", &x, &y, &z);
            add(x, y, 1, z);
            add(y, x, 0, -z);
            add(y, x, 1, z);
            add(x, y, 0, -z);
        }
        add(s, 1, 2, 0);
        add(1, s, 0, 0);
        ans = mcmf();
        printf("%d\n", ans);
    }
    return 0;
}
