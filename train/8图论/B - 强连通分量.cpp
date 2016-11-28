#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 10004
#define M 50004
#define LL __int64
#define INF 0x3f7f7f7f

int head[N], kt[N], ct[N], dfn[N], low[N], out[N], v[N], st[N];
int top = 0, no = 0, loc = 0, num = 0;
struct point
{
    int now, next;
    point(){};
    point(int x, int y):now(x), next(y){};
}p[M];

void init()
{
    memset(head, -1, sizeof(head)); memset(dfn, -1, sizeof(dfn));
    memset(out, 0, sizeof(out));    memset(ct, 0, sizeof(ct));
    memset(v, 0, sizeof(v));
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
            ct[num] ++;
        }while(st[top] != x);
    }
}

int main(void)
{
    int n, m, x, y, i, j, ans;
    scanf("%d%d", &n, &m);
    init();
    while(m--)
    {
        scanf("%d%d", &x, &y);
        add(x, y);
    }
    for(i = 1; i <= n; i++)
    {
        if(dfn[i] == -1)    tarjan(i);
    }
    for(i = 1; i <= n; i++)
    {
        for(j = head[i]; j != -1; j = p[j].next)
        {
            y = p[j].now;
            if(kt[i] != kt[y])  out[kt[i]] ++;
        }
    }
    no = 0;
    for(i = 1; i <= num; i++)
    {
        if(out[i] == 0)
        {
            no++;   ans = ct[i];
        }
    }
    if(no == 1) printf("%d\n", ans);
    else printf("0\n");

    return 0;
}
