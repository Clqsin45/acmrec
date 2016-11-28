#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAXN 10004
struct point
{
    int now, next;
}p[MAXN * 4];
int head[MAXN], v[MAXN], ct[MAXN], n, sum, out[MAXN], no = 0;

void add(int x, int y)
{
    p[++no].next = head[x]; head[x] = no;
    p[no].now = y;         return;
}

int findmax(int x, int y)
{
    return x > y ? x : y;
}
void dfs(int x)
{
    int i, st = -1, y;
    v[x] = 1;
    ct[x] = 1;
    for(i = head[x]; i != -1; i = p[i].next)
    {
        y = p[i].now;
        if(v[y])    continue;
        dfs(y);
        ct[x] += ct[y];
        st = findmax(st, ct[y]);
    }
    st= findmax(st, n - ct[x]);  //除了x和他的子树 他的父亲所连得
    if(st <= n / 2)
    {
        out[++sum] = x;
    }
}


int main(void)
{
    int i, st1, st2;
    scanf("%d", &n);
    memset(head, -1, sizeof(head));
    memset(v, 0, sizeof(0));
    memset(ct, 0, sizeof(ct));
    for(i = 1; i < n ; i++)
    {
        scanf("%d%d",&st1, &st2);
        add(st1, st2);
        add(st2, st1);
    }
    sum = 0;
    dfs(1);
    if(sum == 0)
    {
        printf("NONE\n");
        return 0;
    }
    sort(out + 1, out + sum +1);
    for(i = 1; i <= sum; i++)   printf("%d\n", out[i]);
    printf("\n");
    return 0;
}
