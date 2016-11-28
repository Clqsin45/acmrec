#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 10004
#define M
#define LL __int64
#define INF 0x3f7f7f7f

int head[N], in[N], v[N], f[N];
int loc, n, ans, no, a, b;
struct point
{
    int now, next;
    point(){};
    point(int x, int y) : now(x), next(y) {};
}p[N];

void add(int x, int y)
{
    p[no] = point(y, head[x]);
    head[x] = no++;
}

void init()
{
    memset(head, -1, sizeof(head));memset(v, 0, sizeof(v));
    memset(in, 0, sizeof(in));
    for(int i = 1; i <= n; i++) f[i] = i;
    loc = no = 0;
}

int find(int x)
{
    if (x == f[x])  return x;
    return f[x] = find(f[x]);
}

void tarjan(int x)
{
    int i, y;
    v[x] = 1;
    for(i = head[x]; i != -1; i = p[i].next)
    {
        y = p[i].now;
        if(!v[y])
        {
            //printf("~~~~%d %d\n", x, y);
            tarjan(y);  f[y] = x;
        }
    }
    if(x == a && v[b])
    {
        ans = find(b);  return;
    }
    else if(x == b && v[a])
    {
        ans = find(a);  return;
    }
}
int main(void)
{
    int TC, i, x, y, m;
    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%d", &n);
        init();
        m = n - 1;
        while(m--)
        {
            scanf("%d%d", &x, &y);
            add(x, y);  in[y] = 1;
        }
        scanf("%d%d", &a, &b);
        if(a == b)
        {
            printf("%d\n", a);  continue;
        }
        for(i = 1; i <= n; i++)
        {
            if(in[i] == 0)
            {
                tarjan(i);  break;
            }
        }
//        for(i = 1; i <= n; i++)
//            printf("%d %d\n", i, f[i]);
        printf("%d\n", ans);
    }
    return 0;
}
