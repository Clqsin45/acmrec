#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

#define N 255
#define T 1004
#define M 100005
#define LL __int64
#define INF 0x3f7f7f7f

struct point
{
    int u, v, flow, next;
    point(){};
    point(int x,int y,int z, int w):u(x), v(y), flow(z), next(w){};
}p[M];
struct record
{
    int x, y;
    record(){};
    record(int a, int b):x(a), y(b){};
}r[M];
int head[T], d[T], cur[T],st[M], f[N], v[N][N], n, k, s, e, no;

void init()
{
    int i;
    for(i = 1; i <= n; i++) f[i] = i;   no = 0;
    memset(v, 0, sizeof(v));
}

void add(int x, int y, int z)
{
    p[no] = point(x, y, z, head[x]);    head[x] = no++;
}

int find(int x)
{
    if(x == f[x])   return x;
    return f[x] = find(f[x]);
}
void merge(int x, int y)
{
    x = find(x);    y = find(y);
    if(x == y)  return;
    f[x] = y;
}

void build(int mid)
{
    int i, j;
    memset(head, -1, sizeof(head)); no = 0;
    for(i = 1; i <= n; i++)
    {
        add(s, i, mid); add(i, s, 0);
        add(i + 2 * n, e, mid); add(e, i + 2 * n, 0);
        add(i, i + n, k);   add(i + n, i, 0);   //²ð£¡
    }
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(v[i][j])
            {
                add(i, j + 2 * n, 1);   add(j + 2 * n, i, 0);
            }
            else
            {
                add(i + n, j + 2 * n, 1);   add(j + 2 * n, i + n, 0);
            }
        }
    }
}

bool bfs()
{
    int i, x, y;
    memset(d, -1, sizeof(d));
    queue<int>q;
    q.push(s);  d[s] = 0;
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
    int x = s, loc, top, i, nowflow, maxflow = 0;
    //printf("!!!\n");
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
                maxflow += nowflow; top = loc;
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
    int ct, ans, low, high, mid, i, j, x, y, TC, m, l;
    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%d%d%d%d", &n, &m, &k, &l);
        init(); ct = 0;
        while(m--)
        {
            scanf("%d%d", &x,  &y);
            r[++ct] = record(x, y);
        }
        while(l--)
        {
            scanf("%d%d", &x, &y);
            merge(x, y);
        }
        for(i = 1; i <= n; i++) f[i] = find(i);
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= ct; j++)
            {
                if(f[i] == f[r[j].x])   v[i][r[j].y] = 1;
            }
        }

        low = ans = 0;    high = n;
        s = 0;  e = 3 * n + 1;
        while(low <= high)
        {
            mid = (low + high) >> 1;
            build(mid);
            if(dinic() == mid * n)
            {
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
