#include <stdio.h>
#include <string.h>
#define MAX 10010

int head[MAX], no, ans = 0, f[MAX];
struct point
{
    int now, cost, next;
}p[MAX << 1];


inline int findmax(int x, int y)
{
    return x > y ? x : y;
}

void add(int x, int y, int z)
{
    p[++no].next = head[x];
    head[x] = no;
    p[no].now = y;
    p[no].cost = z;
    return;
}

void dfs(int x, int fa)
{
    int i, y, ct, zwai = 0;
    f[x] = 0;
    for(i = head[x]; i != -1; i = p[i].next)
    {
        y = p[i].now;
        if(y == fa) continue;
        ct = p[i].cost;
        dfs(y, x);
        if(f[x] <= f[y] + ct)
        {
            zwai = f[x];
            f[x] = f[y] + ct;
        }
        else if(zwai < f[y] + ct)
        {
            zwai = f[y] + ct;
        }
    }
    ans = findmax(ans, f[x] + zwai);
}

int main(void)
{
    int st1, st2, stt, n = 0;
    memset(head, -1, sizeof(head));
    while(scanf("%d%d%d", &st1, &st2, &stt) != EOF)
    {
        n++;
        add(st1, st2, stt);
        add(st2, st1, stt);
    }
    dfs(1, 1);
    //ans = dfs(far, far);
    printf("%d\n", ans);
    return 0;
}
