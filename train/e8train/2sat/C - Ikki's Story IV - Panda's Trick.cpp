#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 1005
#define M 1000005
#define LL __int64
#define INF 0x3f7f7f7f
int head[N], low[N], kt[N], dfn[N], v[N], st[N];
int top = 0, no = 0, num = 0, loc = 0, n, m;

struct point
{
    int now, next;
    point(){};
    point(int x, int y):now(x), next(y){};
}p[M];
struct record
{
    int x,  y;
}r[N];

void add(int x, int y)
{
    p[no] = point(y, head[x]);  head[x] = no++;
    p[no] = point(x, head[y]);  head[y] = no++;
}

void tarjan(int x)
{
    dfn[x] = low[x] = ++loc;
    int i, y;
    v[x] = 1;   st[top++] = x;
    for(i = head[x]; i != -1; i = p[i].next)
    {
        y = p[i].now;
        if(dfn[y] == -1)
        {
            tarjan(y);  low[x] = min(low[x], low[y]);
        }
        else if(v[y])
            low[x] = min(low[x], dfn[y]);
    }
    if(low[x] == dfn[x])
    {
        num++;
        do
        {
            v[st[top--]] = 0;
            kt[st[top]] = num;
        }while(st[top] != x);
    }
}

bool judge()
{
    int i;
    for(i = 0; i < m; i++)
    {
       // printf("%d %d\n", kt[i*2], kt[i*2+1]);
        if(kt[i * 2] == kt[i * 2 + 1])  return false;
    }
    return true;
}

bool cro(int i, int j)
{
    if(r[i].x <= r[j].y && r[i].x >= r[j].x && r[i].y >= r[j].y)    return true;
    if(r[i].y <= r[j].y && r[i].y >= r[j].x && r[i].x <= r[j].x)    return true;
    return false;
}
void out()
{
    int i, j;
        for(i = 0; i < m; i++)
    {
        printf("%d\n", i);
        for(j = head[i]; j != -1; j = p[j].next)
        {
            printf("~%d   ", p[j].now);
        }
        printf("\n");
    }
}

void init()
{
    memset(head, -1, sizeof(head)); no = 0;
    memset(dfn, -1, sizeof(dfn));   num = 0;    loc = top = 0;
    memset(v, 0, sizeof(v));
}
int main(void)
{
    int i, j,  x, y;
    scanf("%d%d", &n, &m);
    init();
    for(i = 0; i < m; i++)
    {
        scanf("%d%d", &r[i].x, &r[i].y);
        if(r[i].x > r[i].y) swap(r[i].x, r[i].y);
    }
   // out();
   for(i = 0; i < m; i++)
   {
       for(j = i + 1; j < m; j++)
       {
           if(cro(i, j))
           {
                add(i * 2, j * 2 + 1);
                add(i * 2 + 1, j * 2);
                add(j * 2, i * 2 + 1);
                add(j * 2 + 1, i * 2);
           }
       }
   }
   m <<= 1;
    for(i = 0; i < m; i++)
    {
        if(dfn[i] == -1)    tarjan(i);
    }
    m >>= 1;
    if(judge()) printf("panda is telling the truth...\n");
    else printf("the evil panda is lying again\n");
    return 0;
}
