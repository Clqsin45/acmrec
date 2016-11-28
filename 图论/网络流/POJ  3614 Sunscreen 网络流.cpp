#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include <queue>
using namespace std;
#define N 3604
#define M 4100004
#define INF 0x3f3f3f3f
struct point
{
    int u, v, flow, next;
}p[M];
struct cow
{
    int high, low;
}co[2504];
int head[N] = {-1}, cur[N], d[N], st[M], ct[1004] = {0}, s, e, no = 0;
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
    int c, l, i, j, st1, st2, u = 0, tot = 0;
    scanf("%d%d", &c,  &l);
    s = 0;
    for(i = 1; i <= c; i++)
    {
        scanf("%d%d", &co[i].low, &co[i].high);
        add(s, i, 1);
    }
    for(i = 1; i <= l; i++)
    {
        scanf("%d%d", &st1, &st2);
        if(ct[st1] == 0)    tot++;
        ct[st1] += st2;
    }
    e = c + tot + 1;
    for(i = 1; i <= 1000; i++)
    {
        if(ct[i] == 0)  continue;
        u++;
        for(j = 1; j <= c; j++)
        {
            if(i >= co[j].low && i <= co[j].high)
            {
                add(j, u + c, 1);
            }
        }
        add(u + c, e, ct[i]);
    }
    //printf("!!!\n");
    printf("%d\n", dinic());
	return 0;
}
