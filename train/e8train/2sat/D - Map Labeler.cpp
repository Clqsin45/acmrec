#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
using namespace std;

#define N 224
#define M 160005

#define LL __int64
#define INF 0x3f7f7f7f
#define far 100000
struct point{
    int now, next;
    point(){};
    point(int x, int y):now(x), next(y){};
}p[M];
struct record
{
    int x, y;
}r[N];
int head[N], dfn[N], low[N], v[N], kt[N], st[N];
int n, top, loc, num, no;

void init()
{
    memset(head, -1, sizeof(head)); memset(v, 0, sizeof(v));
    memset(dfn, -1, sizeof(dfn));   top = loc = num = no = 0;
}

void add(int x, int y)
{
    p[no] = point(y, head[x]);  head[x] = no++;
}

void build(int mid)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(abs(r[i].x - r[j].x) >= mid)  continue;
            if(r[i].y > r[j].y)
            {
                if(r[i].y - r[j].y < mid)
                {
                    add(i * 2 + 1, i * 2);
                    add(j * 2, j * 2 + 1);
                }
                else if(r[i].y - r[j].y < 2 * mid)
                {
                    add(i * 2 + 1, j * 2 + 1);
                    add(j * 2, i * 2);
                }
            }
            else if(r[i].y == r[j].y)
            {
                add(i * 2, j * 2 + 1);      add(j * 2 + 1, i * 2);
                add(i * 2 + 1, j * 2);      add(j * 2, i * 2 + 1);
            }
            else
            {
                if(r[j].y - r[i].y < mid)
                {
                    add(j * 2 + 1, j * 2);
                    add(i * 2, i * 2 + 1);
                }

                else if(r[j].y - r[i].y < 2 * mid)
                {
                    add(i * 2, j * 2);
                    add(j * 2 + 1, i * 2 + 1);
                }
            }
        }
    }
}

void tarjan(int x)
{
    int i, y;
    low[x] = dfn[x] = ++loc;
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
        num ++;
        do
        {
            v[st[--top]] = 0;
            kt[st[top]] = num;
        }while(st[top] != x);
    }
}
bool judge(int mid)
{
    int i, j;
    init();
    build(mid);
    n <<= 1;

    for(i = 0; i < n; i++)
    {
        if(dfn[i] == -1)  tarjan(i);
    }
    n >>= 1;
    for(i = 0; i < n; i++)
    {

        if(kt[i * 2] == kt[i * 2 + 1] ) return false;
    }
    return true;
}
int main(void)
{
    int TC,  x, y, i, low, high, mid, ans;
    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            scanf("%d%d", &r[i].x, &r[i].y);
        low = 0;    high = far; ans = 0;

        while(low <= high)
        {
            mid = (low + high) >> 1;
            if(judge(mid))
            {
                ans = mid;  low = mid + 1;
            }
            else high = mid - 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
