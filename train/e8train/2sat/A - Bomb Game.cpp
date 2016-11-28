#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

#define N 202
#define M
#define LL __int64
#define INF 0x3f7f7f7f
#define far 100000
//800000000

#define eps 1e-8
int f[N][N], dfn[N], low[N], v[N], st[N], kt[N];
int n, top, loc, num, m;
struct point
{
    int x, y;
    double dis(const point &I)const
    {
        return sqrt((x-I.x)*(x-I.x)+(y-I.y)*(y-I.y));
    }
}p[N];

void init()
{
    memset(dfn, -1, sizeof(dfn));   memset(v, 0, sizeof(v));
    top = num = loc = 0;    memset(f, 0, sizeof(f));
}

void tarjan(int x)
{
    int i;
    low[x] = ++loc;dfn[x] = loc;
    v[x] = 1;   st[top++] = x;
    for(i = 0; i < m; i++)
    {
        if(!f[x][i])    continue;
        if(dfn[i] == -1 )
        {
            tarjan(i);  low[x] = min(low[x], low[i]);
        }
        else if(v[i])
            low[x] = min(low[x], dfn[i]);
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

bool check(double mid)
{
    int i, j;
    //printf("%f\n", mid);
    init();
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < m; j++)
        {
            if((i^1) == j || i == j)    continue;
            //printf("%d %d %d  %f %d\n", i, j, j^1, p[i].dis(p[j]) / 2, p[i].dis(p[j]) / 2 < mid + eps);
            if((p[i].dis(p[j]) / 2)<= mid)f[i][j ^ 1] = 1;
            //else f[i][j] = 1;
        }
    }


    for(i = 0; i < m; i++)
    {
        if(dfn[i] == -1)    tarjan(i);
    }

    for(i = 0; i < n; i++)
    {
        if(kt[2 * i] == kt[i * 2 + 1])  return false;
    }
    return true;

}
int main(void)
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int i;
    double low, high, mid, ans;
    while(scanf("%d", &n) !=  EOF)
    {
        m = 2 * n;
        for(i = 0; i < n; i++)
        {
            scanf("%d%d%d%d", &p[i*2].x, &p[i*2].y, &p[i*2+1].x, &p[i*2+1].y);
        }
        low = 0;    high = far;
        while(high - low > eps)
        {
           // printf("%f %f\n", low, high);
            mid = (low + high) / 2;
            //system("pause");
            if(check(mid))
            {
                ans = mid;  low = mid;
            }
            else high = mid;
        }
        printf("%.2f\n", ans);
    }
    return 0;
}
