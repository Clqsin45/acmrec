#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 60004
#define INF 9999999999999LL
#define LL __int64


struct point
{
    int u, v, next;
    LL flow;
}p[MAX << 2];

int head[MAX], sk[MAX], q[MAX * 6], lev[MAX], vis[MAX], cur[MAX];
int s, e, no;

void add(int x, int y, LL fl)
{
    p[no].u = x;    p[no].v = y; p[no].flow = fl;
    p[no].next = head[x];  head[x] = no++;
}

bool bfs()
{
    int i, x, f, r, y;

    memset(lev, -1, sizeof(lev));
    f = r = 0;
    lev[s] = 0;
    q[r++] = s;
    while(f < r)
    {
        x = q[f++];
        for(i = head[x]; i != -1; i = p[i].next)
        {
            if(p[i].flow && lev[y = p[i].v] < 0)
            {
                lev[y] = lev[x] + 1;
                if(y == e)  return true;
                q[r++] = y;
            }
        }
    }
    return false;

}

LL dinic()
{
    LL maxflow = 0, nowflow;
    int i, x = s, now, top;

    while(bfs())
    {
        top = 0;
        for(i = s; i <= e; i++) cur[i] = head[i];

        while(1)
        {
            if(x == e)
            {
                nowflow =  INF;
                for(i = 0 ; i < top; i++)
                {
                    if(p[sk[i]].flow < nowflow)
                    {
                        nowflow = p[sk[i]].flow;
                        now = i;
                    }
                }

                maxflow += nowflow;
                for(i = 0; i < top; i++)
                {
                    p[sk[i]].flow -= nowflow;
                    p[sk[i]^1].flow += nowflow;
                }

                top = now;
                x = p[sk[top]].u;
            }

            for(i = cur[x]; i != -1; i = p[i].next)
            {
                if(p[i].flow && lev[p[i].v] == lev[x] + 1) break;
            }

            cur[x] = i;
            if(i != -1)
            {
                sk[top++] = i;
                x = p[i].v;
            }
            else
            {
                if(!top)    break;
                lev[x] = -1;
                x = p[sk[--top]].u;
            }
        }
    }
    return maxflow;
}

 int dfs(int x)
 {
     vis[x] = 1;
     int y, i, ct = 1;
     for(i = head[x]; i != -1; i = p[i].next)
     {
         y = p[i].v;
         if(!vis[y] && p[i].flow > 0)
         {
             ct += dfs(y);
         }
     }
     return ct;
 }
int main(void)
{
    LL sum = 0, maxfl;
    memset(head, -1, sizeof(head));
    int n, m, i, j, tem, a, b, num;
    scanf("%d%d", &n, &m);
    s = 0;  e = n + 1;
    no = 0;
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &tem);
        if(tem > 0)
        {
            sum += tem;
            add(s, i, tem);
            add(i, s, 0);
        }
        else
        {
            add(i, e, -tem);
            add(e, i, 0);
        }
    }
    while(m--)
    {
        scanf("%d%d", &a, &b);
        add(a, b, INF);
        add(b, a, 0);
    }

    memset(vis, 0, sizeof(vis));

    maxfl = dinic();
    //printf("~~");
    num = dfs(s);
    printf("%d %I64d\n", num - 1, sum - maxfl);

    return 0;
}
