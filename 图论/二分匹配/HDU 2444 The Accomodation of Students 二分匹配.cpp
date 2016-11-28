/**************************
给出一堆人和认识的关系 问能不能把人分成两组，每组内互不认识
染色+二分匹配
**************************/

#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
#define MAX 222

int match[MAX], col[MAX], v[MAX], head[MAX], n, no;
struct point
{
    int now, next;
}p[MAX * MAX];
queue<int>Q;

void add(int x, int y)
{
    p[++no].next = head[x];
    head[x] = no;   p[no].now = y;
}
int color(int t)
{
    int x, i, y;
    memset(col, -1, sizeof(col));

    col[t] = 1; Q.push(t);

    while(!Q.empty())
    {
        x = Q.front();
        Q.pop();

        for(i = head[x]; i != -1; i = p[i].next)
        {
            y = p[i].now;
            if(col[y] == -1)
            {
                col[y] = 1 - col[x];    Q.push(y);
            }
            else if(col[y] == col[x])
            {
                while(!Q.empty())   Q.pop();
                return 1;
            }
        }
    }
    return 0;
}

int dfs(int x)
{
    int i, y;
    for(i = head[x]; i != -1; i = p[i].next)
    {
        y = p[i].now;
        if(v[y])    continue;
        v[y] = 1;
        if(!match[y] || dfs(match[y]))
        {
            match[y] = x;
            return 1;
        }
    }
    return 0;
}

int main(void)
{
    int m, i, a, b, sum, flag;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        memset(head, -1, sizeof(head));
        no = sum = flag = 0;
        while(m--)
        {
            scanf("%d%d", &a, &b);
            add(a, b);
            add(b, a);
        }
        for(i = 1; i <= n; i++)
        {
            if(color(i))
            {
                flag = 1;
                break;
            }
        }
        if(flag)
        {
            printf("No\n");
            continue;
        }

        memset(match, 0, sizeof(match));
        for(i = 1; i <= n; i++)
        {
            memset(v, 0, sizeof(v));
            sum += dfs(i);
        }
        printf("%d\n", sum / 2);

    }
    return 0;
}
