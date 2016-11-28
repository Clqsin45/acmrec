#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 1004
#define M 2100000
#define LL __int64
#define INF 8000000
int col[N], ans[N],d[N], head[N];
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
int n, ct, sx1, sy1, sx2, sy2, ds, m, k, no;

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

bool dfs(int x)
{
    int i, y;
    if(col[x] == 1) return true;
    if(col[x] == 2) return false;
    col[x] = 1;col[x ^ 1] = 2;
    ans[++ct] = x;
    for(i = head[x]; i != -1; i = p[i].next)
    {
        y = p[i].now;
        if(!dfs(y))     return false;
    }
    return true;
}

bool solve()
{
    memset(col, 0, sizeof(col));
    int i, j, k;
    for(i = 0; i < n; i++)
    {
        if(col[i])  continue;
        ct = 0;
        if(!dfs(i))
        {
            for(j = 1; j <= ct; j++)
                col[ans[j]] = col[ans[j] ^ 1] = 0;
            if(!dfs(i ^ 1) )    return false;
        }
    }
    return true;
}
int main(void)
{
    int x, y, i, high, low, mid, ans;
    int temp;
    int a, b;
    while(scanf("%d%d%d", &n, &m, &k) != EOF)
    {
        scanf("%d%d%d%d", &sx1, &sy1, &sx2, &sy2);
        high = INF, low = 0;    ans = -1;
        for(i = 0; i < n; i++)
        {
            scanf("%d%d", &a, &b);
            x = abs(a - sx1) + abs(b - sy1);
            y = abs(a - sx2) + abs(b - sy2);
//            high = max(high, x);    high = max(high, y);
//            low = min(low, x);  low = min(low, y);
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
        high =high * 2 + ds;    low <<= 1;
        while(low <= high)
        {
            mid = (low + high) >> 1;
            build(mid);
            //printf("%d\n", mid);
            if(solve())
            {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        printf("%d\n", ans);
    }


    return 0;
}
