#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MD 204
#define MT  80008
#define INF 0x3f7f7f7f


struct point
{
    int u, v, next, lim;
}p[MT];
struct store
{
    int u, v,lim;
}s[MT];

int hp[MD], st[MT], q[MT << 3];
int d[MD], c[MD], n, t, no, edge;

void addp(int x, int y, int z)
{
    p[no].u = x;    p[no].v = y;    p[no].lim = z;
    p[no].next = hp[x]; hp[x] = no++;
}

void build(int mid)
{
    int i, j, x;
    memset(hp, -1, sizeof(hp));
    no = 0;

    addp(0, 1, t);  addp(1, 0, 0);
    for(i = 1; i <= edge; i++)
    {
        if(s[i].lim <= mid)
        {
            addp(s[i].u, s[i].v, 1);
            addp(s[i].v, s[i].u, 1);
        }
    }
}

bool bfs()
{
    int i, f, x, y, r;
    f = r = 0;
    memset(d, -1, sizeof(d));
    d[0] = 0;   q[r++] = 0;
    while(f < r)
    {
        x = q[f++];//printf("%d\n", x);
        for(i = hp[x]; i != -1; i = p[i].next)
        {
            if(p[i].lim && d[y = p[i].v] == -1)
            {
                d[y] = d[x] + 1;
                if(y == n)  return true;
                q[r++] = y;
            }
        }
    }
    return false;
}

int dinic()
{
    int maxflow = 0, nowflow, i, top, loc, x, y;
    x = 0;
    while(bfs())
    {
        top = 0;
        for(i = 0; i <= n; i++) c[i] = hp[i];

        while(true)
        {
            if(x == n)
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
                }
                top = loc;
                x = p[st[top]].u;
            }
            for(i = c[x]; i != -1; i = p[i].next)
                if(p[i].lim > 0 && d[p[i].v] == d[x] + 1)   break;
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
    int i, j, st1, st2, stt, m = 0, l = INF;
    int high, low, mid, ans = 0;
    scanf("%d%d%d", &n, &edge, &t);
    no = 0;
    for(i = 1; i <= edge; i++)
    {
        scanf("%d%d%d", &s[i].u, &s[i].v, &s[i].lim);
        m = max(m, s[i].lim);
        l = min(s[i].lim, l);
    }
    high = m;   low = 0;

    while(low <= high)
    {
        mid = (low + high) >> 1;
        build(mid);//printf("!!\n");
        stt = 0;
        while(bfs())
        {
            stt += dinic();

        }
        //printf("~~%d\n", stt);
        if(stt == t)
        {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    printf("%d\n", ans);
    return 0;
}
