#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 100005
#define INF 0x3f7f7f7f
struct point
{
    int t, c[5];
}p[MAX];
int ans[MAX], n, flag = 1, k = 1, v[MAX] = {0};

bool dfs(int x, int fa, int deep)
{
    int i, y, j, ft = 0;
    if(deep==n)
    {
        return true;
    }
    for(i = 0; i < 4; i++)
    {
        y = p[x].c[i];  ft = 0;
        if(v[y])    continue;
        for(j = 0; j < 4; j++)
        {
            if(p[y].c[j] == fa)
            {
                ft ++;
            }
            if(p[y].c[j] == x)
            {
                ft++;
            }
        }
        if(ft != 2 && fa != 0) continue;
        v[y] = 1;
        if(dfs(y, x, deep + 1))
        {
            ans[deep + 1] = y;
            printf("%d %d %d\n",x,fa, y);
            return true;
        }
        else v[y] = 0;
    }
   // if(deep == n)   return true;
    return false;

}
int main(void)
{
    int i, tot,  x, y, j;
    scanf("%d", &n);
    tot = n << 1;
    for(i = 1; i <= n; i++)
        p[i].t= 0;
    for(i = 1; i <= tot; i++)
    {
        scanf("%d%d", &x, &y);
        if(!flag)   continue;
        if(p[x].t <= 3)    p[x].c[p[x].t++] = y;
        if(p[y].t <= 3)    p[y].c[p[y].t++] = x;
        else flag = 0;
    }
    v[1] = 1;
    if(flag == 0)
    {
        printf("-1\n");
        return 0;
    }
    if(dfs(1, 0, 1))
    {
        flag = 1;
    }
    else flag = 0;
    ans[1] = 1;

    if(!flag)   printf("-1\n");
    else
    {
        for(i = 1; i <= n; i++)
        {
            printf("%d%c", ans[i], i == n ? '\n' : ' ');
        }
    }
    return 0;
}



/***********
6
1 2
3 1
4 1
5 1
2 3
4 2
2 5
4 3
3 6
5 4
4 6
5 6

************/
