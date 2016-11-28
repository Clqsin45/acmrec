#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 1004
#define M 2100000
#define LL __int64
#define INF 0x3f7f7f7f
int dfn[N], low[N], v[N], st[N], kt[N] ,d[N], head[N];
struct point
{
    int now, next;
    point(){};
    point(int x,int y):now(x), next(y){};
}p[M];
struct rec
{
    int x, y;
}r[N << 1];
int n, sx1, sy1, sx2, sy2, ds, m, k, no, loc;
int top, num;
void add(int x, int y)
{
    p[no] = point(y, head[x]);  head[x] = no++;
}
void build(int mid)
{
    memset(head, -1, sizeof(head));
    no = 0;
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(i == j || ((i ^ 1) == j) || (j ^ 1) == i || (i ^ 1) == (j ^ 1))  continue;
            if((i & 1) == (j & 1))
            {
                if(d[i] + d[j] > mid)   {add(i, j ^ 1); add(j, i ^ 1);}
            }
            else
            {
                if(d[i] + d[j] + ds > mid) { add(i, j ^ 1); add(j, i ^ 1);}
            }
        }
    }
    for(i = 1; i <= m; i++)
    {
        add(r[i].x << 1, r[i].y << 1 | 1);  add(r[i].y << 1, r[i].x << 1 | 1);
        add(r[i].x << 1 | 1, r[i].y << 1);  add(r[i].y << 1 | 1, r[i].x << 1);
    }
    for(; i <= m + k; i++)
    {
        add(r[i].x << 1, r[i].y << 1);    add(r[i].x << 1 | 1, r[i].y << 1 | 1);
        add(r[i].y << 1, r[i].x << 1);    add(r[i].y << 1 | 1, r[i].x << 1 | 1);
    }
}

void init()
{
    memset(dfn, -1, sizeof(dfn));   memset(v, 0, sizeof(v));
    num = top = loc = 0;
}

void tarjan(int x)
{
    int i, y;
    low[x] = ++loc; dfn[x] = loc;
    v[x] = 1;   st[top++] = x;
    for(i = head[x]; i != -1; i = p[i].next)
    {
        y = p[i].now;
        if(dfn[y] == -1)
        {
            tarjan(y);  low[x] = min(low[x], low[y]);
        }
        else if(v[y])
            low[x] = min(low[x], dfn[y]);
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

bool solve()
{
    init();
    int i, j, k;
    for(i = 0; i < n; i++)
        if(dfn[i] == -1)    tarjan(i);

    for(i = 0; i < n; i += 2)
    {
        if(kt[i] == kt[i ^ 1])  return false;
    }
    return true;
}
int main(void)
{
    int x, y, i, high, lows, mid, ans;
    int temp;
    int a, b;
    while(scanf("%d%d%d", &n, &m, &k) != EOF)
    {
        scanf("%d%d%d%d", &sx1, &sy1, &sx2, &sy2);
        high = 0, lows = INF;    ans = -1;
        for(i = 0; i < n; i++)
        {
            scanf("%d%d", &a, &b);
            x = abs(a - sx1) + abs(b - sy1);
            y = abs(a - sx2) + abs(b - sy2);
            high = max(high, x);    high = max(high, y);
            lows = min(lows, x);  lows = min(lows, y);
            d[i*2] = x; d[i * 2 + 1] = y;
        }
        n <<= 1;
        for(i = 1; i <= m; i++)
        {
            scanf("%d%d", &r[i].x, &r[i].y);
            r[i].x --; r[i].y --;
        }

        for(; i <= m + k; i++)
        {
            scanf("%d%d", &r[i].x, &r[i].y);
            r[i].x --;  r[i].y --;
        }


        ds = (abs(sx1 - sx2) + abs(sy1 - sy2));
    // printf("%d\n", ds);
        high =high * 2 + ds;
         lows <<= 1;
        while(lows <= high)
        {
            mid = (lows + high) >> 1;
            build(mid);
            //printf("%d\n", mid);
            if(solve())
            {
                ans = mid;
                high = mid - 1;
            }
            else lows = mid + 1;
        }
        printf("%d\n", ans);
    }


    return 0;
}
