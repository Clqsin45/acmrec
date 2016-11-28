#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define MAX 80003
struct point
{
    int now, next;
}p[MAX * 2];
int v[MAX], fa[MAX], head[MAX], val[MAX], euler[MAX * 2], dph[MAX * 2], pos[MAX],f[MAX * 2][20];
int ans, cnt = 0, record[MAX], n, no = 0;

void add(int x, int y)
{
    p[++no].next = head[x];  head[x] = no;
    p[no].now = y;  return;
}

void dp(void)
{
    int i, j, k;
    for(i = 1; i <= cnt; i++)   f[i][0] = i;
    k = (int)((log((double)cnt))/log(2.0));
    for(i = 1; i <= k; i++)
    {
        for(j = 1; j + (1 << (i - 1))<= cnt; j++)
        {
            if(dph[f[j][i-1]] < dph[f[j+(1<<(i-1)) ][i-1]]) f[j][i] = f[j][i-1];
            else f[j][i] = f[j+(1<<(i-1))][i-1];
        }
    }
}

void geteuler(int x, int deep)
{
    int y, i;
    if(v[x])    return;
    v[x] = 1;   dph[cnt] = deep;    euler[cnt] = x;
    pos[x] = cnt;   cnt ++;
    for(i = head[x]; i != -1; i = p[i].next)
    {
        y = p[i].now;
        if(!v[y])
        {
            geteuler(y, deep + 1);
            dph[cnt] = deep;    euler[cnt] = x;
            cnt++;
        }
    }
}

void dfs(int x)
{
    int i, y;
    if(v[x])    return;
    v[x] = 1;
    for(i = head[x]; i != -1; i = p[i].next)
    {
        y = p[i].now;
        if(!v[y])
        {
            fa[y] = x;
            dfs(y);
        }
    }
}

int rmq(int start, int end)
{
    int k = (int)(log((double)end - start + 1) / log(2.0));
    if(k < 0)   return 0;

    if(dph[f[start][k]] < dph[f[end-(1<<k)+1][k]])  return f[start][k];
    else return f[end-(1<<k)+1][k];
}
int lca(int x, int y)
{
    if(pos[x] < pos[y])
        return euler[rmq(pos[x], pos[y])];
    else
        return euler[rmq(pos[y], pos[x])];
}

int getkth(int st, int x, int y, int k)
{
    cnt = 0;    record[++cnt] = val[x];
    while(x != st)
    {
        x = fa[x];
        record[++cnt] = val[x];
    }
    if(y != st)
        record[++cnt] = val[y];
    while(y != st)
    {
        y = fa[y];
        if(y == st) break;
        record[++cnt] = val[y];
    }
    if(cnt < k) return 0;
    sort(record + 1, record + cnt + 1);
    ans = record[1 - k + cnt];
    return 1;
}
int main(void)
{
    int i, st1, st2, op, st, m, j;
    scanf("%d%d", &n, &m);
    memset(head, -1, sizeof(head));
    memset(v, 0, sizeof(v));
    cnt = 0;    no = 0;
    for(i = 1; i <= n; i++) scanf("%d", &val[i]);
    for(i = 1; i < n; i++)
    {
        scanf("%d%d", &st1, &st2);
        add(st1, st2);
        add(st2, st1);
    }
    fa[1] = 1;
    geteuler(1, 0);
    dp();
    memset(v, 0, sizeof(v));
    dfs(1);

    for(i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &op, &st1, &st2);
        if(op)
        {
            st = lca(st1, st2);
            if(getkth(st, st1, st2, op))
                printf("%d\n", ans);
            else printf("invalid request!\n");
        }
        else val[st1] = st2;
    }

    return 0;
}
