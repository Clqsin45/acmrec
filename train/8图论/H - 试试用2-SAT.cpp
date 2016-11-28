#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 4004
#define M 4000004
#define LL __int64
#define INF 0x3f7f7f7f

struct point
{
    int now, next;
    point() {};
    point(int x, int y):now(x), next(y) {};
}p[M];
int head[N], dfn[N], low[N], kt[N], v[N], st[N];
int no, num, top, n, loc;

void init()
{
    memset(head, -1, sizeof(head)); memset(v, 0, sizeof(v));
    memset(dfn, -1, sizeof(dfn));
    top = no = num = loc = 0;
}

void add(int x, int y)
{
    p[no] = point(y, head[x]);  head[x] = no++;
    p[no] = point(x, head[y]);  head[y] = no++;
}

void tarjan(int x, int fa)
{
    int y, i;
    dfn[x] = low[x] = ++loc;
    v[x] = 1;   st[top++] = x;
    for(i = head[x]; i != -1; i = p[i].next)
    {
        y  = p[i].now;
        if(dfn[y] == -1)
        {
            tarjan(y, x);
            low[x] = min(low[x], low[y]);
        }
        else if(v[y])
        {
            low[x] = min(low[x], dfn[y]);
        }
    }
    if(low[x] == dfn[x])
    {
        num ++;
        do
        {
            v[st[--top]] = 0;
            kt[st[top]] = num;
        }while(st[top] != x);
    }
}
int main(void)
{
    int TC, i, j, x, y, m, tc;
    scanf("%d", &TC);
    bool flag;
    for(tc = 1; tc <= TC; tc++)
    {
        if(tc > 1)  printf("\n");
        scanf("%d%d", &n, &m);
        init(); flag = true;
        while(m--)
        {
            scanf("%d%d", &x, &y);
            add(x * 2, y * 2 - 1);  add(x * 2 - 1, y * 2);
        }

        for(i = 1; i <= n * 2; i++)
        {
            if(dfn[i] == -1)    tarjan(i, -1);
        }
        for(i = 1; i <= n; i++)
        {
           // printf("%d %d %d %d\n", i * 2, i * 2 - 1, kt[i * 2], kt[i * 2- 1] );
            if(kt[i * 2] == kt[i * 2 - 1])
            {
                flag = false;   break;
            }
        }
        printf("Scenario #%d:\n", tc);
        if(flag)    printf("No suspicious bugs found!\n");
        else printf("Suspicious bugs found!\n");
    }
    return 0;
}
