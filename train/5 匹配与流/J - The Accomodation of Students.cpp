#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

#define MAX 222
#define INF 0x3f7f7f7f
int head[MAX], col[MAX], match[MAX], n, no;
bool v[MAX];

struct point
{
    int now, next;
}p[MAX * MAX];
queue<int>q;

void add(int x, int y)
{
    p[no].now = y;  p[no].next = head[x];   head[x] = no++;
}

void init()
{
    memset(head, -1, sizeof(head));
    memset(match, -1, sizeof(match));
    no = 0;
}

bool color(int x)
{
    int i, y;
    memset(col, -1, sizeof(col));

    col[x] = 1; q.push(x);
    while(!q.empty())
    {
        x = q.front();  q.pop();
        for(i = head[x]; i != -1; i = p[i].next)
        {
            y = p[i].now;
            if(col[y] == -1)
            {
                col[y] = 1 - col[x];    q.push(y);
            }
            else if(col[y] == col[x])
            {
                while(!q.empty())    q.pop();
                return true;
            }
        }
    }
    return false;
}

bool dfs(int x)
{
    int i, y;
    for(i = head[x]; i != -1; i = p[i].next)
    {
        y = p[i].now;
        if(!v[y])
        {
            v[y] = true;
            if(match[y] == -1 || dfs(match[y]))
            {
                match[y] = x;
                return true;
            }
        }
    }
    return false;
}
int main(void)
{
    int m, i, a, b, sum, flag;

    while(scanf("%d%d", &n, &m) != EOF)
    {
        init();

        sum = flag = 0;

        while(m--)
        {
            scanf("%d%d", &a, &b);
            add(a, b);  add(b ,a);
        }
        for(i = 1; i <= n; i++)
        {
            if(color(i))
            {
                flag = 1;   break;
            }
        }

        if(flag)   { printf("No\n"); continue;}

        for(i = 1; i <= n; i++)
        {
            memset(v, false, sizeof(v));
            sum += dfs(i);
        }
        printf("%d\n", sum / 2);
    }
    return 0;
}
