#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include <queue>
using namespace std;
#define M 200005
#define N 404
#define INF 0x3f3f3f3f

struct point
{
    int u, v, flow, next;
}p[M];
int head[N], cur[N], d[N],  st[M], s, e, no = 0;

void add(int x, int y, int z)
{
    p[no].u = x;    p[no].v = y;
    p[no].flow = z; p[no].next = head[x];   head[x] = no++;
    p[no].u = y;    p[no].v = x;
    p[no].flow = 0; p[no].next = head[y];   head[y] = no++;
}
bool bfs()
{
    int i, x, y;
    queue<int>q;
    memset(d, -1, sizeof(d));
    q.push(s);  d[s] = 0;
    while(!q.empty())
    {
        x = q.front();  q.pop();
       // printf("%d\n", x);
        for(i = head[x]; i != -1; i = p[i].next)
        {
            y = p[i].v;
            if(p[i].flow && d[y] < 0)
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
    int top, i, nowflow, maxflow = 0, x = s, loc;
    while(bfs())
    {
        for(i = 0; i <= e; i++) cur[i] = head[i];
        top = 0;
        //printf("!!!\n");
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
                for(i = 0 ; i < top; i++)
                {
                    p[st[i]].flow -= nowflow;
                    p[st[i]^1].flow += nowflow;
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
int main()
{
    //freopen("in.txt", "r", stdin);
    int n, f, d, i, j, fi, di, temp;
    scanf("%d%d%d", &n, &f, &d);
    s = 0;  e = 2 * n + f + d + 1;
    memset(head, -1, sizeof(head));
    for(i = 1; i <= f; i++)
    {
        add(s, i, 1);
    }

    for(i = 1; i <= d; i++)
    {
        add(i + n * 2 + f, e, 1);
    }
    for(i = 1; i <= n; i++)
    {
        add(i + f, i + f + n, 1);
        scanf("%d%d", &fi, &di);
        while(fi--)
        {
            scanf("%d", &temp);
            add(temp, f + i, 1);
        }
        while(di--)
        {
            scanf("%d", &temp);
            add(f + n + i, f + 2 * n + temp, 1);
        }
    }
    printf("%d\n", dinic());
	return 0;
}
