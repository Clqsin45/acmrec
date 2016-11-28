#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 104
#define M
#define LL __int64
#define INF 0x3f7f7f7f

int f[N][N], dfn[N], low[N], kt[N], ct[N], in[N], out[N], v[N], st[N];
int num = 0, loc = 0, top = 0, n;
void init()
{
    memset(f, 0, sizeof(f));    memset(dfn, -1, sizeof(dfn));
    memset(ct, 0, sizeof(ct));  memset(v, 0, sizeof(v));
    memset(in, 0, sizeof(in));  memset(out, 0, sizeof(out));
}

void tarjan(int x)
{
    int i;
    dfn[x] = low[x] = ++loc;
    v[x] = 1;   st[top++] = x;
    for(i = 1; i <= n; i++)
    {
        if(i == x || !f[x][i] )  continue;
        if(dfn[i] == -1)
        {
            tarjan(i);
            low[x] = min(low[x], low[i]);
        }
        else if(v[i])
        {
            low[x] = min(low[x], dfn[i]);
        }
    }
    if(low[x] == dfn[x])
    {
        num++;
        do
        {
            v[st[--top]] = 0;
            kt[st[top]] = num;
        }while(st[top] != x);
    }
}
int main(void)
{
    int  i, j, x, y, ain = 0, aout = 0;
    init();
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        while(scanf("%d", &y) && y)
            f[i][y] = 1;
    }
    for(i = 1; i <= n; i++)
    {
        if(dfn[i] == -1)     tarjan(i);
    }
    if(num == 1)
    {
        printf("1\n0\n");
        return 0;
    }
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(kt[i] == kt[j] || !f[i][j])  continue;
            out[kt[i]] ++;  in[kt[j]] ++;
            //printf("%d %d\n", kt[i], kt[j]);
        }
    }
    for(i = 1; i <= num; i++)
    {
        if(out[i] == 0) aout++;
        if(in[i] == 0)  ain ++;
    }
    printf("%d\n%d\n", ain, max(aout, ain));

    return 0;
}
