#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 64
#define M 40004
#define LL __int64
#define INF 0x3f7f7f7f

struct point
{
    int now, next;
    point() {};
    point(int x, int y):now(x), next(y) {};
}p[M];
int head[N], col[N], ans[N];
int n, ct, no;

void add(int x, int y)
{
    p[no] = point(y, head[x]);    head[x] = no++;
}

void init()
{
    memset(head, -1, sizeof(head));
    memset(col, 0, sizeof(col));
    no = 0;
}
bool dfs(int x)
{
    int i, y;
    if(col[x] == 2) return false;
    if(col[x] == 1) return true;
    col[x] = 1; col[x ^ 1] = 2;
    ans[++ct] = x;
    for(i = head[x]; i != -1; i = p[i].next)
    {
        y =p[i].now;
        if(!dfs(y)) return false;
    }
    return true;
}

bool solve()
{
    int i, j, temp;
    for(i = 0; i < n; i++)
    {
        //printf("%d\n", i);
        if(col[i])  continue;
        ct = 0;
        if(!dfs(i))
        {
            //printf("orz\n");
            for(j = 0; j <= ct; j++)
                col[ans[j]] = col[ans[j]^1] = 0;
            if(!dfs(i ^ 1)) return false;
        }
    }
    return true;
}
int main(void)
{
    int i, x, y, m, j;
    char a, b;
    while(scanf("%d%d", &n, &m) && (n || m))
    {
        init();
        n <<= 1;
        add(0, 1);
        while(m--)
        {
            scanf("%d%c%d%c", &x, &a, &y, &b);
           // printf("%d %d %d %d\n",x * 2 + (a == 'h'),  (y * 2 + (b == 'h'))^1,y * 2 + (b == 'h'),(x * 2 + (a == 'h'))^1);
            add(x * 2 + (a == 'h'), (y * 2 + (b == 'h'))^1);
            add(y * 2 + (b == 'h'), (x * 2 + (a == 'h'))^1);
        }


        if(solve())
        {
            //printf("!!");
            for(i = 2; i < n; i++)
            {
                if(col[i] == 1) continue;
                printf("%d%c%c", i >> 1, i & 1 ? 'h' : 'w', i < n - 2 ?' ' : '\n');
            }

        }
        else printf("bad luck\n");
    }
    return 0;
}
