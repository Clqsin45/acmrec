#include <stdio.h>
#include <string.h>
//±ß¿ª´ó
struct point
{
    int now;  int next;
}p[1000004];
int dfn[102], low[102], s[102], v[102], head[102], pos[102];
int top, n, add, ct, no , inroad[102], outroad[102];

int min(int x, int y)
{
    return x < y ? x: y;
}
void tarjan(int x)
{
    int i, j;
    dfn[x] = low[x] = ++no;
    v[x] = 1;
    s[top++] = x;
    for(i = head[x]; i != -1; i = p[i].next)
    {
        j = p[i].now;
        if(dfn[j] == 0)
        {
            tarjan(j);
            low[x] = min(low[x], low[j]);
        }
        else if(v[j])
        {
            low[x] = min(low[x] , dfn[j]);
        }
    }
    if(low[x] == dfn[x])
    {
        ct++;
        do
        {
            v[s[--top]] = 0;
            pos[s[top]] = ct;
        } while(s[top]!=x);
    }
}
int main(void)
{
    int st, i, j, ansin = 0, ansout = 0;
    scanf("%d", &n);
    add = 0;    no = 0;     top = 0;    ct = 0;
    memset(s, 0, sizeof(s));
    for(i = 1; i <= n; i++)
    {
        dfn[i] = 0; v[i] = 0;   head[i] = -1;
        inroad[i] = 0;  outroad[i] = 0;
        while(scanf("%d", &st) && st)
        {
            p[++add].next = head[i];
            head[i] = add;
            p[add].now = st;
        }
    }
    for(i = 1; i <= n; i++)
    {
        if(dfn[i] == 0) tarjan(i);
    }
    for(i = 1; i <= n; i++)
    {
        for(j = head[i]; j != -1; j = p[j].next)
        {
            if(pos[i] != pos[p[j].now])
            {
                outroad[pos[i]]++;
                inroad[pos[p[j].now]]++;
            }
        }
    }
    for(i = 1; i <= ct; i++)
    {
        if(!inroad[i])  ansin++;
        if(!outroad[i]) ansout++;
    }
    if(ct == 1) printf("1\n0\n");
    else printf("%d\n%d\n", ansin, ansout>ansin?ansout:ansin);
    return 0;
}
