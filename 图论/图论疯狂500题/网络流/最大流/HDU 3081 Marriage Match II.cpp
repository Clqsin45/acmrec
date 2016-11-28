#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 105
#define T 211
#define M 100005
#define LL __int64
#define INF 0x3f7f7f7f

int f[N], head[T], d[T], st[M], cur[T], n, s, e, no, ct;
int v[N][N];
struct point
{
    int u, v, flow, next;
    point(){};
    point(int x,int y, int z, int w):u(x), v(y), flow(z), next(w){};
}p[M];

struct record
{
    int x, y;
    record(){};
    record(int a, int b):x(a), y(b){};
}r[M];

void init()
{
    int i;
   // memset(head, -1, sizeof(head));
    for(i = 1; i <= n; i++) f[i] = i;
    memset(v, 0, sizeof(v));
    ct = 0;
}

void add(int x, int y, int z)
{
    p[no] = point(x, y, z, head[x]);    head[x] = no++;
}

int find(int x)
{
    if(x== f[x])    return x;
    return f[x] = find(f[x]);
}
void merge(int x, int y)
{
    int fx = find(x),    fy = find(y);
    if(fx == fy)  return ;
    f[fx] = fy;
}

void build(int mid)
{
    int i, j;
    memset(head, -1, sizeof(head)); no = 0;
    for(i = 1; i <= n; i++)
    {
        add(s, i, mid); add(i, s, 0);
        add(i + n, e, mid); add(e, i + n, 0);
    }
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(v[i][j])
            {
                add(i, j + n, 1);   add(j + n, i, 0);
            }
        }
    }
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

void modify()
{
    int i, j;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= ct; j++)
        {
            if(find(i) == find(r[j].x))
            {
                v[i][r[j].y] = 1;
            }
        }
    }
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
    int TC, i, x, y, j,  m, k, low, mid, high, ans;
    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%d%d%d", &n, &m, &k);
        s = ans = 0;  e = (n * 2) + 1;
        init();
        while(m--)
        {
            scanf("%d%d", &x, &y);
            r[++ct] = record(x, y);
        }
        while(k--)
        {
            scanf("%d%d", &x, &y);
            merge(x, y);
        }
        low = 0;    high = n;
        for(i = 1; i <= n; i++) f[i] = find(i); //记得压一压。。

        modify();   //处理出一个关系图T T
        while(low <= high)
        {
            mid = (low + high) >> 1;
            build(mid);
            //printf("%d\n", mid);
            if(dinic() == mid * n)
            {
                ans = mid;  low = mid + 1;
            }
            else high = mid - 1;
        }
        printf("%d\n", ans);

    }
    return 0;
}
