#include <stdio.h>
#include <string.h>
#define N 1000004
struct point
{
    int now; int next;
}p[5 * N];
struct direct
{
    int s;  int e;
}d[N];
int a[N], v[N], head[N], mark[N], n, no;

void add(int x, int y)
{
    p[++no].next = head[x]; head[x] = no;
    p[no].now = y;
}

int lowbit(int x)
{
    return x & (-x);
}

void modify(int x, int k)
{
    for(; x <= no; x += lowbit(x))
        a[x]+=k;
    return;
}

int getsum(int x)
{
    int sum = 0;
    for(; x > 0; x -= lowbit(x))
        sum += a[x];
    return sum;
}

void dfs(int x)
{
    int i;
    d[x].s = ++no;  mark[x] = 1;
    for(i = head[x]; i != -1; i = p[i].next)
    {
        if(!mark[p[i].now]) dfs(p[i].now);
    }
    d[x].e = ++no;

}
int main(void)
{
    int m, i, st1, st2, st;
    char op[3];

    memset(a, 0, sizeof(a));
    memset(v, 0, sizeof(v));
    memset(mark, 0, sizeof(mark));
    memset(head, -1, sizeof(head));
    scanf("%d", &n);
    no = 0;
    for(i = 1; i < n; i++)
    {
        scanf("%d%d", &st1, &st2);
        add(st1, st2);
        add(st2, st1);
    }
    no = 0;     dfs(1);
    for(i = 1; i <= n; i++)
    {
        v[i] = 1;
        modify(d[i].s, 1);
    }

    scanf("%d", &m);
    for(i = 1; i <= m; i++)
    {
        scanf("%s%d", op, &st);
        if(op[0] == 'Q')
            printf("%d\n",getsum(d[st].e) - getsum(d[st].s - 1));
        else
        {
            if(v[st])
            {
                v[st] = 0;
                modify(d[st].s, -1);
            }
            else
            {
                v[st] = 1;
                modify(d[st].s, 1);
            }
        }
    }
    return 0;
}
