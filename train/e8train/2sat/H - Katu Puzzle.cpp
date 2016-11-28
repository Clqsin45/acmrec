#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 2004
#define M 4000004
#define LL __int64
#define INF 0x3f7f7f7f
struct point
{
    int now, next;
    point() {};
    point(int x, int y):now(x),next(y){};
}p[M];
int col[N], head[N], ans[N], no;
int n, m, ct;
bool dfs(int x)
{
    int i, y;
    if(col[x] == 1) return true;
    if(col[x] == 2) return false;
    col[x] = 1;  col[x ^ 1] = 2;
    ans[++ct] = x;
    for(i = head[x]; i != -1; i = p[i].next)
    {
        y = p[i].now;
        if(!dfs(y)) return false;
    }
    return true;
}
bool solve()
{
    int i, j;
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

void add(int x, int y)
{
    p[no] = point(y, head[x]);  head[x] = no++;
}
int main(void)
{
    int i, x, y, z;
    char c[10];
    scanf("%d%d", &n, &m);  n <<= 1;
    memset(col, -1, sizeof(col));
    memset(head, -1, sizeof(head));
    no = 0;
    while(m--)
    {
        scanf("%d%d%d%s", &x, &y, &z, c);
        if(c[0] == 'A')
        {
            if(z == 1)
            {
                add(x * 2, x * 2 + 1);  add(y * 2, y * 2 + 1);
            }
            else
            {
                add(x * 2 + 1, y * 2);  add(y * 2 + 1, x * 2);
            }
        }
        else if(c[0] == 'O')
        {
            if(z == 1)
            {
                add(x * 2, y * 2 + 1);  add(y * 2, x * 2 + 1);
            }
            else
            {
                add(x * 2 + 1, x * 2);  add(y * 2 + 1, y << 1);
            }
        }
        else  if(c[0] == 'X')
        {
            if(z == 1)
            {
                add(x << 1, y * 2 + 1);  add(y << 1, x * 2 + 1);
                add(x << 1 | 1, y << 1);    add(y << 1 | 1, x << 1);
            }
            else
            {
                add(x << 1, y << 1);    add(y << 1, x << 1);
                add(x << 1 | 1, y << 1| 1); add(y << 1 | 1, x << 1 | 1);
            }
        }

    }
    if(solve())
        {
            printf("YES\n");
        }
        else printf("NO\n");
    return 0;
}
