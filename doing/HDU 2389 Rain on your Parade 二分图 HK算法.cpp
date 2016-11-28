#include <stdio.h>
#include <queue>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

#define eps 1e-6
const int MAXN = 3005;
const int INF = 1 << 30;

int f[MAXN][MAXN], cx[MAXN], cy[MAXN], nx, ny;
int dx[MAXN], dy[MAXN], dis;
bool v[MAXN];

struct point
{
    double x, y, v;
}p[MAXN];

struct unb
{
    double x, y;
}u[MAXN];

double dist(point a, unb b)
{
    double x = a.x - b.x;
    double y = a.y - b.y;
    return sqrt(x * x + y * y);
}

int find()
{
    int t, i;
    queue<int>Q;
    dis = INF;
    memset(dx, -1, sizeof(dx));
    memset(dy, -1, sizeof(dy));
    for(i = 1; i <= nx; i++)
    {
        if(cx[i] == -1)
        {
            Q.push(i);
            dx[i] =0;
        }
    }
    while(!Q.empty())
    {
        t = Q.front();
        Q.pop();
        if(dx[t] > dis) break;
        for( i = 1; i <= ny; i++)
        {
            if(f[t][i] && dy[i] == -1)
            {
                dy[i] = dx[t] + 1;
                if(cy[i] == -1) dis = dy[i];
                else
                {
                    dx[cy[i]] = dy[i] + 1;
                    Q.push(cy[i]);
                }
            }
        }
    }
    return dis != INF;
}

int dfs(int x)
{
    int i;
    for(i = 1; i <= ny; i++)
    {
        if(!v[i] && f[x][i] && dy[i] == dx[x] + 1)
        {
            v[i] = 1;
            if(cy[i] != -1 && dy[i] == dis) continue;
            if(cy[i] == -1 || dfs(cy[i]))
            {
                cy[i] = x;
                cx[x] = i;
                return 1;
            }
        }
    }
    return 0;
}
int main(void)
{
    int tc, ctc = 0, limit, ng, nu, ans, i, j;
    scanf("%d", &tc);
    while(tc--)
    {
        ctc++;
        scanf("%d%d", &limit, &ng);
        for(i = 1; i <= ng; i++)
            scanf("%lf%lf%lf", &p[i].x, &p[i].y, &p[i].v);
        scanf("%d", &nu);
        for(i = 1; i <= nu; i++)
            scanf("%lf%lf", &u[i].x, &u[i].y);
        nx = ng;    ny = nu;
        memset(f, 0, sizeof(f));
        for(i = 1; i <= ng; i++)        //如果可以抵达的话 就连上
        {
            for(j = 1; j <= nu; j++)
            {
                if(dist(p[i], u[j] )/ p[i].v - limit < eps)
                    f[i][j] = 1;
            }
        }

        ans = 0;
        memset(cx, -1, sizeof(cx));
        memset(cy, -1, sizeof(cy));
        while(find())
        {
            memset(v, 0, sizeof(v));
            for(i = 1; i <= nx; i++)
                if(cx[i] == -1 && dfs(i))   ans++;
        }

        printf("Scenario #%d:\n%d\n\n", ctc, ans);
    }
    return 0;
}
