#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 44444
#define INF 0x3f7f7f7f
struct point
{
    int u, v, flow, next;
}p[MAX * 10];
int head[MAX], q[MAX * 10], d[MAX], st[MAX], cur[MAX], s, e, no, n, m;

void add(int x, int  y, int z)
{
    p[no].u = x;    p[no].v = y;    p[no].flow = z;
    p[no].next = head[x];   head[x] = no++;
    p[no].u = y;    p[no].v = x;    p[no].flow = 0;
    p[no].next = head[y];   head[y] = no++;
}

void build(int x, int y)
{
    if(x != 1)
        add((x - 1) * m + y, (x - 2) * m + y, 1);
    if(x != n)
        add((x - 1) * m + y, x * m + y, 1);

    if(y != 1)
        add((x - 1) * m + y, (x - 1) * m + y - 1, 1);
    if(y != m)
        add((x - 1) * m + y, (x - 1) * m + y + 1, 1);
}


bool bfs()
{
    int x, y, i, f, r;
    f = r = 0;
    memset(d, -1, sizeof(d));

    d[s] = 0;   q[r++] = s;
    while(f < r)
    {
        x = q[f++];
        for(i = head[x]; i != -1; i = p[i].next)
        {
            if(p[i].flow > 0 && d[y = p[i].v] < 0)
            {
                d[y] = d[x] + 1;
                if(y == e)  return true;
                q[r++] = y;
            }
        }
    }
    return false;
}
int dinic()
{
    int i, x = s, nowflow, maxflow = 0, y, top, loc;
    while(bfs())
    {
        top = 0;
        for(i = s; i <= e; i++)
            cur[i] = head[i];
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
                maxflow += nowflow;
                for(i = 0; i < top; i++)
                {
                    p[st[i]].flow -= nowflow;
                    p[st[i] ^ 1].flow += nowflow;
                }
                top = loc;
                x = p[st[top]].u;
            }
            for(i = cur[x]; i != -1; i = p[i].next)
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
    int i, j, x, ans, TC = 1;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        memset(head, -1, sizeof(head));
        no = 0;
        s = 0;  e = n * m + 1;

        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= m; j++)
            {
                scanf("%d", &x);
                if(x == 1)
                {
                    add(s, (i - 1) * m + j, INF);
                }
                if(x == 2)
                {
                    add((i - 1) * m + j, e, INF);
                }
                build(i, j);
            }
        }
        ans = dinic();
        printf("Case %d:\n", TC++);
        printf("%d\n", ans);
    }
    return 0;
}
