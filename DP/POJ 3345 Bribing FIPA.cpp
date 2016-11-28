#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INF 0x3f3f3f3f
char chst[202], name[204][102];
int v[204], no, head[202], n, m, f[202][202], flag[202], t;

struct point
{
    int now;    int next;
}line[1002];

void add(int x, int y)
{
    line[++no].next = head[x];  head[x] = no;
    line[no].now = y; return;
}

int ask(char *s)
{
    int i;
    for(i = 1; i <= t; i++)
        if(strcmp(s, name[i]) == 0) return i;
    return -1;
}

int min(int x, int y)
{
    return x < y ? x : y ;
}

int find(int x)
{
    int i, j, k, ct = 0, y;
    if(x)   ct = 1;
    for(i = head[x]; i != -1; i = line[i].next)
    {
        y = line[i].now;
        ct += find(y);
    }
    for(i = head[x]; i != -1; i = line[i].next)
    {
        y = line[i].now;
        for(j = ct; j >= 0; j--)
        {
            for(k = 0; k <= j; k++)
            {
                f[x][j]=min(f[x][j-k]+f[y][k],f[x][j]);
            }
        }
    }

     if(x)
        f[x][ct]=min(f[x][ct],v[x]);
    return ct;
}

int main(void)
{
    char st, num[42];
    int i,j, sign,temp, tex, ans;
    while(scanf("%s",num))
    {
        if(strcmp(num, "#") == 0)   break;
        memset(head, -1, sizeof(head));
        memset(flag, 0, sizeof(flag));
        t = 0;  no = 0;
        scanf("%d", &m);    n = atoi(num);

        for(j = 1; j <= n; j++)
        {
            scanf("%s%d",chst, &tex);
            temp = ask(chst);
            if(temp == -1)
            {
                strcpy(name[++t], chst);
                temp = t;
            }
            v[temp] = tex;
            while(scanf("%c", &st) && st != '\n')
            {
                scanf("%s", chst);
                tex = ask(chst);
                if(tex == -1)
                {
                    strcpy(name[++t], chst);
                    tex = t;
                }
                add(temp, t);
                flag[t] = 1;
            }
        }
        for(i = 0; i <= n; i ++)
        {
            for(j = 1; j <= n; j++)
            {
                if(!flag[j])    add(0, j);
                f[i][j] = INF;
            }
            f[i][0] = 0;
        }
        ans = INF;
        find(0);
        for(i = m; i <= n; i++)
        {
            ans = min(f[0][i],ans);
        }
        printf("%d\n", ans);
    }
    return 0;
}
