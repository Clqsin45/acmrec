#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

#define MAX 202
#define INF 0x7f7f7f7f

struct point
{
    int u, v, next, lim;
}p[MAX * MAX];

int head[MAX], deep[MAX], v[MAX], cur[MAX], no, n;
int stack[MAX * MAX], q[MAX * 1000];
void init(void)
{
    no = 0;
    memset(head, -1, sizeof(head));
}
void add(int x, int y, int z)
{
    p[no].u = x;    p[no].v = y;
    p[no].lim = z;  p[no].next = head[x];
    head[x] = no++; return;
}

bool bfs(int s, int e)
{
    int i,  x, f = 0, r = 0, y;
    memset(deep, -1, sizeof(deep));

    deep[s] = 0;
    q[r++] = s;
    while(f < r)
    {
        x = q[f++];
        for(i = head[x]; i != -1; i = p[i].next)
        {
            if(p[i].lim > 0 && deep[y = p[i].v] == -1)
            {
                deep[y] = deep[x] + 1;
                if(y == e)  return true;
                q[r++] = y;
             }
        }
    }
    return false;
}

int dinic(int s, int e)
{
    int top = 0, maxflow = 0, nowflow, i;
    int x = s, loc;
    while(bfs(s, e))
    {
        top = 0;
        for(i = 1; i <= n; i++) cur[i] = head[i];
        while(true)
        {
            if(x == e)
            {
                nowflow = INF;
                for(i = 0; i < top; i++)
                {
                    if(p[stack[i]].lim < nowflow)
                    {
                        nowflow = p[stack[i]].lim;
                        loc = i;
                    }
                }
                maxflow += nowflow;
                for(i = 0; i < top; i++)
                {
                    p[stack[i]].lim   -= nowflow;
                    p[stack[i]^1].lim += nowflow;
                }
                top = loc;
                x = p[stack[top]].u;
            }

            for(i = cur[x]; i != -1; i = p[i].next)
            {
                if(p[i].lim && deep[p[i].v] == deep[x] + 1) break;
            }

            cur[x] = i;

            if(i != -1)
            {
                stack[top++] = i;
                x = p[i].v;
            }
            else
            {
                if(!top)    break;
                deep[x] = -1;
                x = p[stack[--top]].u;
            }
        }
    }
    return maxflow;

}

int main(void)
{
    int m, ans, st1, st2, stt;
    while(scanf("%d%d", &m, &n) != EOF)
    {
        init();
        while(m--)
        {
            scanf("%d%d%d", &st1, &st2, &stt);
            add(st1, st2, stt);
            add(st2, st1, 0);
        }
        ans = dinic(1, n);
        printf("%d\n", ans);
    }
    return 0;
}
