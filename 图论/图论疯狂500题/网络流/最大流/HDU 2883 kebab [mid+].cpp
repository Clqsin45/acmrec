#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

#define T 202
#define N 711
#define M 240004
#define LL __int64
#define INF 0x3f7f7f7f

int index[T << 1], head[N], d[N], st[M], cur[N], s, e, no, n, m;
struct point
{
    int u, v, flow, next;
    point() {};
    point(int x, int y, int w, int z):u(x), v(y), next(w), flow(z){};
}p[M];
struct person
{
    int x, y;
    person(){};
    person(int a, int b): x(a), y(b){};
}per[T], dat[T << 1];

void init()
{
    memset(head, -1 , sizeof(head));    no = 0;
}
void add(int x, int y, int z)
{
    p[no] = point(x, y, head[x], z);    head[x] = no++;
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
    int x = s, i, top, y, nowflow, maxflow = 0, loc;
    while(bfs())
    {
        for(i = s; i <= e; i++) cur[i] = head[i];
        top = 0;
        //printf("%d\n", maxflow);
        while(true)
        {
            if(x == e)
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
    //printf("%d\n", maxflow);
    return maxflow;
}
int main(void)
{
    int i, j, x, y, sum, id, t;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        sum = id = 0;
        init();
        s = 0;
        for(i = 1; i <= n; i++)
        {
            scanf("%d%d%d%d",  &per[i].x, &x, &per[i].y, &y);
            add(s, i, x * y);   add(i, s, 0);
            index[++id] = per[i].x; index[++id] = per[i].y;
            sum += x * y;
        }
        sort(index + 1, index + id + 1);
        e = n + id + 1;
        for(i = 1; i < id; i++)
        {
            dat[i] = person(index[i], index[i + 1]);
            //printf("%d %d %d\n", i, dat[i].x, dat[i].y);
            t = index[i + 1] - index[i];
            add(i + n, e,  t * m);  add(e, i + n, 0);
        }
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j < id; j ++)
            {
                if(per[i].x <= dat[j].x && per[i].y >= dat[j].y)
                {
                    //printf("%d %d\n", i, j);
                    add(i, j + n, INF); add(j + n, i, 0);
                }
            }
        }
        if(sum == dinic())  printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
