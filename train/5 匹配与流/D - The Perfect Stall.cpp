#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 202
#define INF 0x3f7f7f7f

struct point
{
    int next, now;
}p[MAX * MAX];

int head[MAX], v[MAX], match[MAX], n, m, no;


void add(int x, int y)
{
    p[no].now = y;
    p[no].next = head[x];
    head[x] = no++;
}
bool dfs(int x)
{
    int i, y;
    for(i = head[x]; i != -1; i = p[i].next)
    {
        y = p[i].now;
        if(!v[y])
        {
            v[y] = 1;
            if(match[y] == -1|| dfs(match[y]))
            {
                match[y] = x;
                return true;
            }
        }
    }
    return false;
}
int main(void)
{
    int s, i, ans, t;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        no = 0; ans = 0;
        memset(head, -1, sizeof(head));
        memset(match, -1, sizeof(match));

        for(i = 1; i <= n; i++)
        {
            scanf("%d", &s);
            while(s--)
            {
                scanf("%d", &t);
                add(i, t);
            }
        }
        for(i = 1; i <= n; i++)
        {
            memset(v, 0, sizeof(v));
            ans += dfs(i);
        }

        printf("%d\n", ans);
    }
    return 0;
}
