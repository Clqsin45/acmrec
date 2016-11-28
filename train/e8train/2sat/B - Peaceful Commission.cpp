#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 17004
#define M 40004
#define LL __int64
#define INF 0x3f7f7f7f

int ct, n, no;
int col[N], head[N], ans[N];
struct point
{
    int now, next;
    point(){};
    point(int x, int y):now(x), next(y){};
}p[M];

void init()
{
    memset(head, -1, sizeof(head)); memset(col, 0, sizeof(col));
    no = 0;
}

bool dfs(int x)
{
    int i, y;
    if(col[x] == 2) return false;
    else if(col[x] == 1)    return true;
    col[x] = 1; col[x^1] = 2;
    ans[++ct] = x;
    for(i = head[x]; i != -1; i = p[i].next)
    {
        y = p[i].now;
        if(!dfs(y)) return false;
    }
    return true;
}
void add(int x, int y)
{
    p[no] = point(y, head[x]);  head[x] = no++;
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
            {
                col[ans[j]] = col[ans[j] ^ 1] = 0;
            }
            if(!dfs(i ^ 1)) return false;
        }
    }
    return true;
}
int main(void)
{
    int i, x, y, m;
    while(scanf("%d %d", &n, &m) != EOF)
    {
        n <<= 1;
        init();
        while(m--)
        {
            scanf("%d%d", &x, &y);  x--;    y--;
            add(x, y ^ 1);  add(y, x ^ 1);
        }

        if(solve())
        {
            for(i = 0; i < n; i++)
                if(col[i] == 1) printf("%d\n",i + 1);
        }
        else printf("NIE\n");

    }
    return 0;
}
