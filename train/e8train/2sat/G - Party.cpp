#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 2004
#define M 1000005
#define LL __int64
#define INF 0x3f7f7f7f
struct point
{
    int now, next;
    point(){};
    point(int x, int y): now(x), next(y){};
}p[M];
int head[N], dfn[N], low[N], kt[N], v[N], st[N];
int no, num, top, loc;
void init()
{
    memset(head, -1, sizeof(head)); memset(dfn, -1, sizeof(dfn));
    memset(v, 0 , sizeof(v));
    no = num =  top = loc = 0;
}

void add(int x, int y)
{
    p[no] = point(y, head[x]);  head[x] = no++;
}

void tarjan(int x)
{
    int i, y;
    dfn[x] = low[x] = ++loc;
    v[x] = 1;   st[top++] = x;
    for(i = head[x]; i != -1; i = p[i].next)
    {
        y = p[i].now;
        if(dfn[y] == -1)
        {
            tarjan(y);  low[x] = min(low[x], low[y]);
        }
        else if(v[y])
        {
            low[x] = min(low[x], dfn[y]);
        }
    }
    if(low[x] == dfn[x])
    {
        num++;
        do
        {
            v[st[--top]] = 0;
            kt[st[top]] = num;
        }while(st[top] != x);
    }
}
int main(void)
{
    int n, m, i, x, y;
    int a, b, c, d;
    bool flag = true;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        init(); flag = true;
        while(m--)
        {
            scanf("%d%d%d%d", &a, &b, &c, &d);
            x = a * 2 + c;  y = b * 2 + d;
            add(x, y ^ 1);  add(y, x ^ 1);
        }
        for(i = 0; i < 2 * n; i++)
        {
            if(dfn[i] == -1)    tarjan(i);
        }

        for(i = 0; i < n; i++)
        {
            if(kt[i * 2] == kt[i * 2 + 1])  {flag = false;break;}
        }
        if(flag)    printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
