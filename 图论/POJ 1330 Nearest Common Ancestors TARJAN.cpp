#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10005
struct point
{
    int now, next;
}p[MAX * 2];
int head[MAX], flag[MAX], dfn[MAX], v[MAX];
int no, n, st1, st2;

void add(int x, int y)
{
    p[++no].next = head[x]; head[x] = no;
    p[no].now = y;
}

int find(int x)
{
    int root = x;
    if(root != dfn[root])    dfn[root]= find(dfn[root]);
    return dfn[root];
}
void tarjan(int x)
{
    int i, y;
    dfn[x] = x; v[x] = 1;
    for(i = head[x]; i != -1; i = p[i].next)
    {
        y = p[i].now;
        if(!v[y])
        {
            tarjan(y);      dfn[y] = x;
        }
    }

    if(x == st1 && v[st2])
    {
        no = find(st2);
        return;
    }
    else if(x == st2 && v[st1])
    {
        no = find(st1);
        return;
    }
}
int main(void)
{
    int t, i, j;
    scanf("%d", &t);
    while(t--)
    {
        no = 0;
        scanf("%d", &n);
        memset(flag, 0, sizeof(flag));
        memset(v, 0, sizeof(v));
        memset(head, -1, sizeof(head));

        for(i = 1; i < n ; i++)
        {
            scanf("%d%d", &st1, &st2);
            flag[st2] = 1;
            add(st1, st2);
        }
        scanf("%d%d", &st1, &st2);
        if(st1 == st2)
        {
            printf("%d\n", st1);
            continue;
        }
        for(i = 1; i <= n; i++)
        {
            if(flag[i] == 0)
            {
                tarjan(i);
                break;
            }
        }
        printf("%d\n", no);
    }
    return 0;
}
