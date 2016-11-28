#include <stdio.h>
#include <string.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 505
#define INF 0x7f7f7f7

struct work
{
    int time;
    int a, b, c, d;
}w[MAX];

struct point
{
    int now, next;
}p[MAX * MAX];

int head[MAX], v[MAX], match[MAX], no;

inline bool cal(int x, int y)
{
    if(abs(w[y].a - w[x].c) + abs(w[y].b - w[x].d) +
       abs(w[x].a - w[x].c) + abs(w[x].b - w[x].d) < w[y].time - w[x].time)
        return true;
    return false;
}

inline void add(int x, int y)
{
    p[++no].next = head[x];
    head[x] = no;
    p[no].now = y;
    return ;
}

int dfs(int x)
{
    for(int i = head[x]; i != -1; i = p[i].next)
    {
        int y = p[i].now;
        if(v[y])    continue;
        v[y] = 1;
        if(match[y] == -1 || dfs(match[y]))
        {
            match[y] = x;
            return 1;
        }
    }
    return 0;
}

int main(void)
{
    int TC, n, th, tm, ans;
    int i, j;
    cin>>TC;
    while(TC--)
    {
        cin>>n;

        memset(match, -1, sizeof(match));
        memset(head, -1, sizeof(head));
        no = ans = 0;
        for(i = 1; i <= n; i++)
        {
            scanf("%d:%d %d%d%d%d", &th,
                   &tm, &w[i].a, &w[i].b, &w[i].c, &w[i].d);
            w[i].time = th * 60 + tm;
        }
        for(i = 1; i <= n; i++)
        {
            for(j = i + 1; j <= n; j++)
            {
                if(cal(i, j))   add(i, j);
            }
        }

        for(i = 1; i <= n; i++)
        {
            memset(v, 0, sizeof(v));
            ans += dfs(i);
        }
        printf("%d\n", n - ans);
    }
    return 0;
}
