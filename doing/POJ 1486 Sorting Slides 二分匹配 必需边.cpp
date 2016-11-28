#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 1004
#define INF 0x3f7f7f7f
int f[MAX][MAX], match[MAX], n, v[MAX], st[MAX];
struct ppt
{
    int xi, xa, yi, ya;
}p[MAX];

void init()
{
    //memset(match, -1, sizeof(match));
    memset(f, 0, sizeof(f));
}

bool dfs(int x)
{
    int i;
    for(i = 1; i <= n; i++)
    {
        if(f[x][i] && !v[i])
        {
            v[i] = 1;
            if(match[i] == -1 || dfs(match[i]))
            {
                match[i] = x;
                return true;
            }
        }
    }
    return false;
}
int gao()
{
    int i, ans = 0;
    memset(match, -1, sizeof(match));
    for(i =1; i <= n; i++)
    {
        memset(v, 0, sizeof(v));
        ans += dfs(i);
    }
    return ans;
}
int main(void)
{
    int i, j, ans, x, y, TC = 1;
    bool flag;
    while(scanf("%d", &n) && n)
    {
        init(); flag = false;   ans = 0;
        for(i = 1; i <= n; i++)
        {
            scanf("%d%d%d%d", &p[i].xi, &p[i].xa, &p[i].yi, &p[i].ya);
        }
        for(i = 1; i <= n; i++)
        {
            scanf("%d%d", &x, &y);
            for(j = 1; j <= n; j++)
            {
                if(p[j].xi < x && p[j].xa > x && p[j].yi < y && p[j].ya > y)
                    f[i][j] = 1;
               // printf("%d   ", f[i][j]);
            }
           // printf("\n");
        }
        ans = gao();

        printf("Heap %d\n", TC++);
        if(ans == n)
        {
            for(i = 1; i <= n; i++) st[i] = match[i];
            for(i = 1; i <= n; i++)
            {
                f[st[i]][i] = 0;

                if(gao() == n)  continue;
                else
                {
                    if(flag)    printf(" ");
                    printf("(%c,%d)", 'A' + i - 1, st[i]);
                    flag = true;
                }
                f[st[i]][i] = 1;
            }
        }
        if(!flag)    printf("none");
        printf("\n\n");
    }
    return 0;
}
