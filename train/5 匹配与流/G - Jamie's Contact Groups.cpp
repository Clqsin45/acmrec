#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

#define MAX 2002
#define MN 1114000
#define INF 0x3f7f7f7f

struct point
{
    int u, v, flow, next;
}p[MN];

int head[MAX], d[MAX], st[MAX], cur[MAX], s, e, no, ncpoint, n, m;

void add(int x, int y, int z)
{
    p[no].u = x;    p[no].v  = y;   p[no].flow = z;
    p[no].next = head[x];   head[x] = no++;  return ;
}

bool bfs()
{
    int x, y, i;
    queue<int>q;
    memset(d, -1, sizeof(d));
    d[s] = 0;   q.push(s);
    while(!q.empty())
    {
        x = q.front();  q.pop();

        for(i = head[x]; i != -1; i = p[i].next)
        {
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
void build(int limit)
{
    int i;

    for(i = 0; i < no; i += 2)
    {
        if(p[i].u <= n)
        {
            p[i].flow = 1;
            p[i + 1].flow = 0;
        }
        else
        {
            p[i].flow = limit;
            p[i + 1].flow = 0;
        }
    }
}
int main(void)
{
    int i, j, s, temp, low, high, mid, ans = 0;
    char name[20], ch;
    while(scanf("%d%d",&n, &m) && (n || m))
    {
        memset(head, -1, sizeof(head));
        s = 0;  e = m + n + 1;
        no = 0;
        for(i = 1; i <= n; i++)
        {
            add(s, i, 1);
            add(i, s, 0);
            scanf("%s", name);
            while(1)
            {
                scanf("%d", &temp);
                add(i, n + temp + 1, 1);
                add(n + temp + 1, i, 0);
                if((ch = getchar()) == '\n')    break;
            }
        }
        low = 0;    high = n;
        for(i = n + 1; i <= m + n; i++)
        {
            add(i, e, 1);   add(e, i, 0);
        }

        while(low <= high)
        {
            mid = (low + high) >> 1;
          //  printf("!!%d  ", mid);
            build(mid);
            temp = dinic();
            //printf("%d\n", temp);
            if(temp == n)
            {
                ans = mid;  high = mid - 1;
                //printf("%d\n", ans);
            }
            else low = mid + 1;
        }
        printf("%d\n", ans);

    }
    return 0;
}
