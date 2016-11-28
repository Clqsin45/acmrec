#include <stdio.h>
#include <string.h>
//蝕。。弌。。阻、、、
struct cow
{
    int now;    int next;
}c[50004];
int v[100002], dfn[100002], low[100002], head[100002] ,s[100002],out[100002], pos[100002], posct[100002];
int ct, no, top, n;
int min(int x, int y)
{
    return x < y ? x: y;
}
void tarjan(int x)
{
    int i, j;
    dfn[x] = low[x] = ++no;
    v[x] = 1;   s[top++] = x;
    for(i = head[x]; i != -1 ; i = c[i].next)
    {
        j = c[i].now;
        if(dfn[j] == 0)
        {
            tarjan(j);
            low[x] = min(low[x], low[j]);
        }
        else if(v[j])
        {
            low[x] = min(low[x], dfn[j]);
        }
    }
    if(low[x] == dfn[x])
    {
        ct++;
        do
        {
            v[s[--top]] = 0;
            pos[s[top]] = ct;
            posct[ct] ++;
            //printf("!!!%d = %d\n", s[top], ct);
        }while(s[top] != x);
    }
}

int main(void)
{
    int m, i, st1, st2, j, ansout, r;
    scanf("%d%d", &n, &m);
    memset(s, 0, sizeof(s));
    for(i = 1; i <= n; i++)
    {
        v[i] = dfn[i] = out[i] = posct[i]= 0;
        head[i] = -1;
    }
    no = ct = top = ansout = 0;
    for(i = 1; i <= m; i++)
    {
        scanf("%d%d", &st1, &st2);
        c[i].next = head[st1];
        head[st1] = i;
        c[i].now = st2;
    }
    for(i = 1; i <= n; i++)
    {
        if(dfn[i] == 0) tarjan(i);
    }
    for(i = 1; i <= n; i++)
    {
        for(j = head[i]; j != -1; j = c[j].next)
        {
            if(pos[i] != pos[c[j].now])
            {
                out[pos[i]]++;
            }
        }
    }
    for(i = 1; i <= ct; i++)
    {
        if(!out[i])
        {
            ansout++;   r = i;
        }
    }

    if(ansout == 0)  printf("%d\n", n);
    else if(ansout > 1)  printf("0\n");
    else printf("%d\n", posct[r]);
    return 0;
}
