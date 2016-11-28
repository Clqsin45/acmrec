#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX_T 150
#define MAX_L 25500
#define INF 0x7f7f7f7f

struct line
{
    int now, limit, next, from;
}p[MAX_L];

int head[MAX_T], deep[MAX_T], n, no;
int st[MAX_T], cur[MAX_T], q[MAX_T * 1000];

void add(int x, int y, int z)
{
    p[no].from = x; p[no].now = y;
    p[no].limit = z;    p[no].next = head[x];
    head[x] = no++;
    p[no].from = y; p[no].now = x;
    p[no].limit = 0;    p[no].next = head[y];
    head[y] = no++;
}

void change(int top, int k)
{
    int i;

}

int bfs(int s, int e)
{
    int i, fr, re, x, y;
    fr = re = 0;
    memset(deep, -1, sizeof(deep));

    q[re++] = s;
    deep[s] = 0;

    while(fr < re)
    {
        x = q[fr++];
        for(i = head[x]; i != -1; i = p[i].next)
        {
            y = p[i].now;
            if(p[i].limit > 0 && deep[y] == -1)
            {
                deep[y] = deep[x] + 1;
                q[re++] = y;
                if(y == e)    return 1;
            }
        }
    }
   // cout<<"!!!"<<endl;
    return 0;
}

int dinic(int s, int e)
{
    int maxflow = 0, top, x = s, i;
    while(bfs(s, e))
    {
        top = 0;
        for (i = 0; i < MAX_T; ++i) cur[i] = head[i];
        while(1)
        {
            if(x == e)
            {
                int min = INF, loc;
                for(i = 0; i < top; i++)
                {
                    if(min > p[st[i]].limit)
                    {
                        min = p[st[i]].limit;
                        loc = i;
                    }
                }
                for(i = 0; i < top; i++)
                {
                    p[st[i]].limit -= min;
                    p[st[i] ^ 1].limit += min;
                }
                maxflow += min;
                top = loc;
                x = p[st[top]].from;
            }

            for(i = cur[x]; i != -1; i = p[i].next)
                if(p[i].limit > 0 && deep[x]+1 == deep[p[i].now])  break;
            cur[x] = i;
            if(cur[x] != -1)
            {
                st[top++] = cur[x];
                x = p[cur[x]].now;
            }
            else
            {
                if(top == 0)    break;
                deep[x] = -1;
                x = p[st[--top]].from;
            }
        }

    }
    return maxflow;
}

int main(void)
{
    int n, pow, con, m, sour, sink;
    int st1, st2, stt, ans;
    char ch;
    while(scanf("%d%d%d%d", &n, &pow, &con, &m) != EOF)
    {
        memset(head, -1, sizeof(head));
        sour = n;   sink = n + 1;   no = 0;
        while(m--)
        {
            while(ch = getchar())   if(ch == '(')   break;
            scanf("%d,%d)%d", &st1, &st2, &stt);

            add(st1, st2, stt);
        }
        while(pow--)
        {
            while(ch = getchar())   if(ch == '(')   break;
            scanf("%d)%d", &st2, &stt);

            add(sour, st2, stt);
        }
        while(con--)
        {
            while(ch = getchar())   if(ch == '(')   break;
            scanf("%d)%d", &st1, &stt);
            //printf("%d %d\n", st1, stt);
            add(st1, sink, stt);
        }
        ans = dinic(sour, sink);
        cout<<ans<<endl;
    }
    return 0;
}
