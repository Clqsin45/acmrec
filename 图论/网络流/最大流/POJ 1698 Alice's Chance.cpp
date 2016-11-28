#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MT 30000
#define MD 400
#define INF 0x7f7f7f7f

struct point
{
    int u, v, next, lim;
}p[MT];
int head[MD], d[MD], s, e, no;
int st[MT], q[MT * 100], c[MD];

void init()
{
    memset(head, -1, sizeof(head));
    no = 0; s = 0;
}
void add(int x, int y, int z)
{
    p[no].u = x;    p[no].v = y;
    p[no].lim = z;  p[no].next = head[x];
    head[x] = no++; return;
}
bool bfs(void)
{
    int i, loc, m, f, r, x, y;
    memset(d, -1, sizeof(d));
    f = r = 0;
    d[s] = 0;   q[r++] = s;
    while(f < r)
    {
        x = q[f++];    // printf("%d\n", x);
        for(i = head[x]; i != -1; i = p[i].next)
        {
            //printf("%d\n", y);
            if(p[i].lim > 0 && d[y = p[i].v] == -1)
            {
                d[y] = d[x] + 1;
                if(y == e)  return true;
                q[r++] = y;
            }
        }
    }
    return false;
}

int dinic(void)
{
    int x = s, y, nowflow, maxflow = 0, i, j, top, loc;
    while(bfs())
    {
        top = 0;    //printf("%d\n" , maxflow);
        for(i = 0; i <= e; i++)  c[i] = head[i];
        while(true)
        {
            if(x == e)
            {
                nowflow = INF;
                for(i = 0; i < top; i++)
                {
                    if(p[st[i]].lim < nowflow)
                    {
                        loc = i;    nowflow = p[st[i]].lim;
                    }
                }
                maxflow += nowflow;
                for(i = 0; i < top; i++)
                {
                    p[st[i]].lim -= nowflow;
                    p[st[i]^1].lim += nowflow;
                    //printf("%d   %d   %d\n", p[st[i]].u, p[st[i]].v, nowflow);
                }

                top = loc;
                x = p[st[top]].u;
            }

            for(i = c[x]; i != -1; i = p[i].next)
            {
                if(p[i].lim && d[p[i].v] == d[x] + 1)   break;
            }
            c[x] = i;
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
    int T, n, i, j, k, sum, ans, m, x, y;
    int w[10];
    scanf("%d", &T);
    while(T--)
    {
        init();     ans = 0;    m = 0;
        scanf("%d", &n);
        s = 0;
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= 7; j++)     scanf("%d", &w[j]);
            scanf("%d%d", &x, &y);
            add(0, i, x);   add(i, 0, 0);
            m = max(m, y);  ans += x;
            for(j = 1; j <= y; j++)
            {
                for(k = 1; k <= 7; k++)
                {
                    if(!w[k])   continue;
                    //printf("%d %d\n",i, n + 7 * (j - 1) + k);
                    add(i, n + 7 * (j - 1) + k, 1);
                    add(n + 7 * (j - 1) + k, i, 0);
                }
            }
        }
        e =  n + m * 7 + 1;
        for(j = n + 1; j <= n + m * 7; j++)
        {
            //printf("%d\n", j);
            add(j, e, 1);   add(e, j, 0);
        }
        m = dinic();    //printf("%d\n", m);
        if(ans == m)  printf("YES\n");
        else printf("NO\n");

    }
    return 0;
}
