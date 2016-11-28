/*************************************************************
文物 必须位放保镖 起码要多少个
多试几个方法
**************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define MAX 2502

int head[MAX], v[MAX], match[MAX], n, m, r, c, no;
int goy[14] = {0, -2, -1, 1, 2, 2, 1, -1, -2, 0, 1, 0, -1};
int gox[14] = {0, -1, -2, -2, -1, 1, 2, 2, 1, -1, 0, 1, 0};
int map[55][55], num[55][55];



struct point
{
    int now, next;
}p[MAX * 14];
void add(int x, int y)
{
    p[++no].next = head[x];
    head[x] = no;
    p[no].now = y;
    return;
}

int inmap(int x, int y)
{
    return x >= 1 && x <= r && y >= 1 && y <= c;
}

int dfs(int x)
{
    int i, y;
    for(i = head[x]; i != -1; i = p[i].next)
    {
        y = p[i].now;
        if(v[y]) continue;
        v[y] = 1;
        if(match[y] == -1 || dfs(match[y]))
        {
            match[y] = x;
            return 1;
        }
    }
    return 0;
}
int main(void)
{
    int i, j, temp, CAT = 0, ans, x, y, k;
    while(scanf("%d%d", &r, &c) && (c || r))
    {
        CAT ++;
        n = m = 0;  ans = no = 0;
        memset(match, -1, sizeof(match));
        memset(head, -1, sizeof(head));
        for(i = 1; i <= r; i++)
        {
            for(j = 1; j <= c; j++)
            {
                scanf("%d", &map[i][j]);
                if(map[i][j] == -1)   continue;
                if((i + j) & 1)
                    num[i][j] = ++n;
                else num[i][j] = ++m;
            }
        }

        for(i = 1; i <= r; i++)
        {
            for(j = 1; j <= c; j++)
            {
                if(map[i][j] == -1) continue;
                temp = map[i][j];
                for(k = 1; temp >= 1; k++, temp >>= 1)
                {
                    if(temp & 1)
                    {
                        x = i + gox[k];     y = j + goy[k];
                        if(!inmap(x, y))    continue;
                        if(map[x][y] == -1) continue;
                        if((i + j) & 1)
                            add(num[i][j], num[x][y]);
                        else add(num[x][y], num[i][j]);
                    }

                }
            }
        }

        for(i = 1; i <= n; i++)
        {
            memset(v, 0, sizeof(v));
            ans += dfs(i);
        }
        printf("%d. %d\n", CAT, ans);

    }
    return 0;
}
