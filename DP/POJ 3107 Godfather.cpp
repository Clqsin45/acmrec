#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
#define  MAXN  50005

int head[MAXN], ct[MAXN], n, no = 0;
int  v[MAXN], ans[MAXN], mini, sum;
struct point
{
    int next; int now;
}p[MAXN * 4];

void add(int x, int y)
{
    p[++no].next = head[x]; head[x] = no;
    p[no].now = y;  return;
}

int findmax(int x , int y)
{
    return x > y ? x : y;
}

void dfs(int x)
{
    int i, j, y, st = -1;
    v[x] = 1;    ct[x] = 1;
    for(i = head[x]; i != -1; i = p[i].next)
    {
        y = p[i].now;
        if(v[y])    continue;
        dfs(y);
        ct[x] += ct[y];
        st = findmax(st, ct[y]);
    }
    st = findmax(st, n - ct[x]);
    if(st < mini )
    {
        sum = 1;
        ans[sum] = x;
        mini = st;
    }
    else if(st == mini)
    {
        sum++;
        ans[sum] = x;
    }
}
int main(void)
{
    int i, st1, st2;
    scanf("%d", &n);
    memset(head, -1, sizeof(head));
    memset(v, 0, sizeof(v));
    memset(ct, 0, sizeof(ct));
    for(i = 1; i < n ; i++)
    {
        scanf("%d%d", &st1, &st2);
        add(st1, st2);
        add(st2, st1);
    }
    sum = 0;
    mini = 0x3f3f3f3f;
    dfs(1);

    sort(ans + 1, ans + sum + 1);
    printf("%d", ans[1]);
    for(i = 2 ; i <= sum ;i++)
        printf(" %d", ans[i]);
    printf("\n");
    return 0;
}
