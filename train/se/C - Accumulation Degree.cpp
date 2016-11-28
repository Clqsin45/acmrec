#include <stdio.h>
#include <string.h>
#define INF 0x9502F9000LL
#define ll __int64
#define MAX 200002

struct point
{
    int now, cost, next;
}p[MAX << 4];

int head[MAX], no;
ll down[MAX], up[MAX], ans;

void add(int x, int y, int z)
{
    p[++no].next = head[x]; head[x] = no;
    p[no].now = y;  p[no].cost = z;
    return;
}

ll findmin(ll x, ll y)
{
    return x < y ?  x : y;
}

ll findmax(ll x, ll y)
{
    return x > y ? x : y;
}

void dfs(int x, int fa)
{
    int i, y, flag = 0;
    ll ct;
    down[x] = 0;
    //printf("loc%d   %d\n", x, head[x]);

    for(i = head[x]; i != -1; i = p[i].next)
    {
        y = p[i].now;
        if(y == fa) continue;
        //printf("!!!to %d %d\n", x, y);
        flag = 1;
        dfs(y, x);
        ct = p[i].cost;
        //printf("down%d  %d  %d\n", x, y, down[y]);
        down[x] += findmin(ct, down[y]);
        //printf("getx%d  %d\n",x, down[x]);
    }
    if(!flag)
    {
        down[x] = INF;
        //printf("leaf%d  %d\n", x, down[x]);
    }

}

void dfsagain(int x, int fa, ll flow)
{
    int i, y, flag = 0;
    ll ct, temp, st;
    if(fa)
    {
        temp =  down[fa] - findmin(flow, down[x]) + up[fa];
        if(temp == 0) up[x] = flow;
        else up[x] = findmin(flow, temp);
    }
    for(i = head[x]; i != -1; i = p[i].next)
    {
        y = p[i].now;
        if(y == fa) continue;
        flag = 1;
        ct = p[i].cost;
        dfsagain(y, x, ct);
    }
    if(!flag)
    {
        down[x] = 0;
    }
    st = down[x] + up[x];
    //printf("%d  %d\n", x, st);
    ans = findmax(ans, st);
}
/*1
  P
   2 1
 P  P
 P  P P
*/
int main(void)
{
    int CT, i, j, st1, st2, stt, n;
    scanf("%d", &CT);
    while(CT--)
    {
        memset(head, -1, sizeof(head));
        no = ans = 0;
        scanf("%d", &n);
        for(i = 1; i < n; i++)
        {
            scanf("%d%d%d", &st1, &st2, &stt);
            add(st1, st2, stt);
            add(st2, st1, stt);
        }
        //for(i = 1; i <= n; i++) printf("head[%d] = %d\n", i, head[i]);
        dfs((1 + n) >> 1, 0);
       // for(i = 1; i <= n; i++)
          //  printf("!%d  %d\n", i, down[i]);
        up[(1 + n) >> 1] = 0;
        dfsagain((1 + n) >> 1, 0, 0);
        printf("%I64d\n", ans);
    }
    return 0;
}
