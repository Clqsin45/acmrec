#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 60014
#define M 100004
#define LL __int64
#define INF 0x3f7f7f7f

int head[N], col[N], ans[N];
int no, ct, n;
struct point
{
    int now, next;
    point(){};
    point(int x, int y):now(x) , next(y) {};
}p[M];

void add(int x, int y)
{
    p[no] = point(y, head[x]);  head[x] = no++;
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
    if(col[x] == 1) return true;
    if(col[x] == 2) return false;
    col[x] = 1; col[x ^ 1] = 2;
    ans[++ct] = x;
    for(i = head[x] ; i != -1; i = p[i].next)
    {
        y = p[i].now;
        if(!dfs(y)) return false;
    }
    return true;
}
bool solve()
{
    int i, j, y;
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
    int TC, tc,  i, m, x, y, tp, ot;
    scanf("%d", &TC);
    for(tc = 1; tc <= TC; tc++)
    {
        scanf("%d%d", &n, &m);
        init();
        for(i = 0; i < n; i++)
        {
            scanf("%d", &ot);
            add(i * 6 + (((ot - 1) * 2) | 1),  (i * 6 + (ot % 3 * 2)));
            add(i * 6 + ((ot % 3 * 2) | 1),  (i * 6 + (ot - 1) * 2));
            add(i * 6, i * 6 + 3);
            add(i * 6, i * 6 + 5);
            add(i * 6 + 2, i * 6 + 1);
            add(i * 6 + 2, i * 6 + 5);
            add(i * 6 + 4, i * 6 + 3);
            add(i * 6 + 4, i * 6 + 1);
        }

        while(m--)
        {
            scanf("%d%d%d", &x, &y, &tp);
            x --;   y--;
            if(tp == 0)
            {
                add(x * 6, y * 6);  add(y * 6, x * 6);
                add(x * 6 + 2, y * 6 + 2);  add(y * 6 + 2, x * 6 + 2);
                add(x * 6 + 4, y * 6 + 4);  add(y * 6 + 4, x * 6 + 4);
            }
            else
            {
                add(x * 6, y * 6 + 1);  add(y * 6, x * 6 + 1);
                add(x * 6 + 2, y * 6 + 3);  add(y * 6 + 2, x * 6 + 3);
                add(x * 6 + 4, y * 6 + 5);  add(y * 6 + 4, x * 6 + 5);
            }
        }
        printf("Case #%d: ", tc);
        n = n * 6;
        if(solve())
        {
            printf("yes\n");
        }
        else printf("no\n");
    }

    return 0;
}
