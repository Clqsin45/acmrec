#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 5005
#define M 20004
#define LL __int64
#define INF 0x3f7f7f7f
int v[N], head[N], st[N], kt[N], dfn[N], low[N], out[N], no, loc = 0, num = 0,  top = 0;
struct point
{
    int now, next;
}p[M];

void init()
{
    memset(head, -1, sizeof(head));
    memset(v, 0, sizeof(v));
    memset(dfn, -1, sizeof(dfn));
    memset(out, 0, sizeof(out));

    no = 0;
}

void add(int x, int y)
{
    p[no].now = y;  p[no].next = head[x];   head[x] = no++;
}

void tarjan(int x, int fa)
{
    int i, y;
    dfn[x] = low[x] = ++loc;
    v[x] = 1;   st[top++] = x;
    for(i = head[x]; i != -1; i = p[i].next)
    {
        y = p[i].now;
        if(y == fa) continue;
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

        ++num;
        //printf("%d  %d\n", x, num);
        do
        {
            v[st[--top]] = 0;
            kt[st[top]] = num;
        }
        while(st[top] != x);
    }
}
bool check(int x, int y)
{
    int i;
    for(i = head[x]; i != -1; i = p[i].next)
    {
        if(y == p[i].now)   return true;
    }
    return false;
}
int main(void)
{
    int n, m, i, j, x, y, ans = 0;
    init();
    scanf("%d%d", &n, &m);
    while(m--)
    {
        scanf("%d%d", &x, &y);
        if(check(x, y)) continue;
        add(x, y);  add(y, x);
    }

    for(i = 1; i <= n; i++)
    {
        if(dfn[i] == -1)
            tarjan(i, -1);
    }
    for(i = 1; i <= n; i++)
    {
        for(j = head[i]; j != -1; j = p[j].next)
        {
            y = p[j].now;
            if(kt[i] == kt[y])    continue;
            out[kt[i]]++;
        }
    }

    for(i = 1; i <= num; i++)
    {
        if(out[i] == 1)   ans ++;
    }
    printf("%d\n", (ans + 1) >> 1);


    return 0;
}
