#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
//向可行的每天都流
#define N 1104
#define M 540004
#define LL __int64
#define INF 0x3f7f7f7f

struct point
{
    int u, v, next, flow;
    point(){};
    point(int x, int y, int z, int w): u(x), v(y), next(z), flow(w){};
}p[M];
int head[N], cur[N], d[N], st[M], s, e, no;
void add(int x,int y, int z)
{
    p[no] = point(x, y, head[x], z);    head[x] = no++;
}
void init()
{
    memset(head, -1, sizeof(head));
    no = 0;
}

bool bfs()
{
    int i, x, y;
    memset(d, -1, sizeof(d));
    queue<int>q;
    d[s] = 0;   q.push(s);
    while(!q.empty())
    {
        x = q.front();  q.pop();
        //printf("%d\n", x);
        for(i = head[x]; i!= -1; i = p[i].next)
        {
            //printf("%d\n", i);  system("pause");
            if(p[i].flow && d[y = p[i].v] < 0)
            {
                d[y] = d[x] + 1;
                if(y == e)  return true;
                q.push(y);
            }
        }
    }
    return false;
}

int dinic()
{
    int i, nowflow, maxflow = 0, top, x = s, loc;
    while(bfs())
    {
        //printf("%d\n", maxflow);
        top = 0;
        for(i = s; i <= e; i++) cur[i] = head[i];
        while(true)
        {
            if(x== e)
            {
                nowflow = INF;
                for(i = 0; i < top; i++)
                {
                    if(nowflow > p[st[i]].flow)
                    {
                        nowflow = p[st[i]].flow;
                        loc = i;
                    }
                }
                for(i = 0; i < top; i++)
                {
                    p[st[i]].flow -= nowflow;
                    p[st[i] ^ 1].flow += nowflow;
                }
                maxflow += nowflow;
                top = loc;  x = p[st[top]].u;
            }
            for(i = cur[x]; i!= -1; i = p[i].next)
            {
                if(p[i].flow && d[p[i].v] == d[x] + 1)  break;
            }
            cur[x] = i;
            if(i != -1)
            {
                st[top++] = i;  x = p[i].v;
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
    int TC, tc, x, y, p, sup, i, j, te, n, m;
    scanf("%d", &TC);
    for(tc = 1; tc <= TC; tc++)
    {
        init();
        //if(tc > 1)  printf("\n");
        scanf("%d%d", &n, &m);
        s = 0;  te = 0;     sup = 0;
        for(i = 1; i <= n; i++)
        {
            scanf("%d%d%d", &p, &x, &y);
            add(s, i, p);   add(i, s, 0);
            sup += p;   te = max(te, y);
            for(j = x; j <= y; j++)
            {
                add(i, j + n, 1);   add(j + n, i, 0);
            }
        }
        e = n + te + 1;
        for(i = 1; i <= te; i++)
        {
            add(i + n, e, m);  add(e, i + n, 0);
        }
        //printf("orz\n");
        if(dinic() == sup)  printf("Case %d: Yes\n\n", tc);
        else printf("Case %d: No\n\n", tc);

    }
    return 0;
}
