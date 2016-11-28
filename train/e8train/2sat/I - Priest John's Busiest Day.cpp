#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N  2004
#define M 4116016
#define LL __int64
#define INF 0x3f7f7f7f
struct point
{
    int now, next;
    point() {};
    point(int x, int y):now(x), next(y){};
}p[M];
struct plan
{
    int s, e;
}pt[N];
int col[N], head[N], ans[N], no, n, ct;

void add(int x, int y)
{
    p[no] = point(y, head[x]);  head[x] = no++;
}

bool judge(int a, int b, int c, int d)
{
    if(c >= a && c < b) return true;
    if(a >= c && a < d) return true;
//    if(c > a && c < b && )    return true;
//    if(d > a && d < b &&)    return true;
//    if(a > c && a < d &&)    return true;
//    if(b > c && b < d && )    return true;
    return false ;
}


bool dfs(int x)
{
    if(col[x] == 1) return true;
    if(col[x] == 2) return false;
    col[x] = 1;col[x ^ 1] = 2;
    ans[++ct] = x;
    int i, y;
    for(i = head[x] ; i != -1; i = p[i].next)
    {
        y = p[i].now;
        if(!dfs(y)) return false;
    }
    return true;

}

bool solve()
{
    int i, j;
    memset(col, 0, sizeof(col));
    for(i = 0; i < n; i++)
    {
        if(col[i])  continue;
        ct = 0;
        if(!dfs(i))
        {
            for(j = 1; j <= ct; j++)
                col[ans[j]] = col[ans[j] ^ 1] = 0;
            if(!dfs(i ^ 1)) return false;
        }
    }
    return true;
}
int main(void)
{
    int a, b, c, d, e, i, j, x, y;
    scanf("%d", &n);
    memset(head, -1, sizeof(head));
    for(i = 0; i < n; i++)
    {
        scanf("%d:%d %d:%d%d", &a, &b, &c, &d, &e);
        x = a * 60 + b;   y = c * 60 + d;
        pt[i << 1].s = x;   pt[i << 1].e = x + e;
        pt[i << 1 | 1].s = y - e;   pt[i << 1 | 1].e = y;
    }
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == j)  continue;
            for(a = 0; a <= 1; a++)
            {
                for(b = 0 ;b <= 1; b ++)
                {
                    x = i * 2 + a;  y = j * 2 + b;
                    if(judge(pt[x].s, pt[x].e, pt[y].s, pt[y].e))
                    {
                        add(x, y ^ 1);  add(y, x ^ 1);
                    }
                }
            }
        }
    }

    n <<= 1;
    if(solve())
    {
        printf("YES\n");
        for(i = 0 ; i< n; i++)
        {
            x = pt[i].s; y = pt[i].e;
            if(col[i] == 1) printf("%.2d:%.2d %.2d:%.2d\n", x / 60, x % 60, y / 60, y % 60);
        }
    }
    else printf("NO\n");
    return 0;
}
