#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
#define T 104
#define N 40005
#define M 1000002
#define LL __int64
#define INF 0x3f7f7f7f

struct point
{
    int u, v, flow, next;
}p[M];
struct rec
{
    int x, y, val;
    rec() {};
    rec(int a, int b, int z):x(a), y(b), val(z){};
}r[N], c[N];    //存A B
int head[N], cur[N], st[M], d[N], map[T][T], n, m, s, e, no, white, blx, bly ;
//white = 白格的数量， blx表示black x方向数量， 同理
void add(int x, int y, int z)
{
    p[no].u = x;    p[no].v = y;    p[no].flow = z; p[no].next=  head[x];   head[x] = no++;
}
void scan()
{
    int i, j, temp;
    char ch[10];
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            scanf("%s", ch);
            if(ch[0] == '.')    //如果是.的话，白格无疑
            {
                white ++;
                map[i][j] = white;  //用map给白格编号（顺便可以确认该格是否是白格）
                continue;
            }
            if(ch[0] != 'X')    //ch[0] 是数字是 是B类型的
            {
                bly ++; temp = (ch[0])*100+ch[1]*10+ch[2]-5328; //和
                //printf("%d\n", temp);
                c[bly] = rec(i, j, temp);   //存下
            }
            if(ch[4] != 'X')   //ch[4] 是数字是 是B类型的
            {
                blx ++; temp = ch[4]*100+ch[5]*10+ch[6]-5328;
                r[blx] = rec(i, j, temp);
            }
        }
    }
    s = 0;  e = white + blx + bly + 1;
    //源点0，汇点A+B+C+1
}

void build()
{
    int i, j, x, y, ct, temp = blx, t2 = blx + white;
    for(i = 1; i <= blx; i++)   //对于每一个A类型的点
    {
        ct = 0;
        x = r[i].x;   y = r[i].y;   //获取其坐标
        for(j = y + 1; map[x][j]; j++)  //统计其所统计白格的数量，并向它统计的每一个白格连边
        {
            ct ++;
            add(i, map[x][j] + temp, 8); add(map[x][j] + temp, i, 0);
        }

        add(s, i, r[i].val - ct);   //源点向它连容量是统计值-白格数
        add(i, s, 0);
    }
    for(i = 1; i <= bly; i++)   //同理
    {
        ct = 0;
        x = c[i].x; y = c[i].y;
        for(j = x + 1; map[j][y]; j++)
        {
            ct++;
            add(map[j][y] + temp, i + t2, 8);   add(i + t2, map[j][y] + temp, 0);
        }
        add(i + t2, e, c[i].val - ct);
        add(e, i + t2, 0);
    }

}

void init()
{
    white = blx = bly = 0;
    memset(head, -1, sizeof(head));
    memset(map, 0, sizeof(map));
    no = 0;
}

bool bfs()
{
    int i, x, y;
    memset(d, -1, sizeof(d));
    queue<int>q;
    q.push(s);  d[s] = 0;
    while(!q.empty())
    {
        x = q.front();  q.pop();
        for(i = head[x]; i != -1; i = p[i].next)
        {
            if(p[i].flow && d[y = p[i].v] < 0)
            {
                d[y] = d[x] + 1;
                if(y == e)  return true;
                q.push(y);
            }
        }
    }
    return false;
}

int dinic()
{
    int nowflow, maxflow = 0, i, top, x = s, y, loc;
    while(bfs())
    {

        for(i = s; i <= e; i++) cur[i] = head[i];
        top = 0;//printf("%d\n", x);
        while(true)
        {
            if(x == e)
            {
                nowflow = INF;
                for(i = 0; i < top; i++)
                {
                    if(nowflow > p[st[i]].flow)
                    {
                        nowflow = p[st[i]].flow;
                        loc = i;
                    }
                }
                for(i = 0; i <  top; i++)
                {
                    p[st[i]].flow -= nowflow;
                    p[st[i] ^ 1].flow += nowflow;
                }
                maxflow += nowflow;
                top = loc;  x = p[st[top]].u;
            }
            for(i = cur[x]; i != -1; i = p[i].next)
            {
                if(p[i].flow && d[p[i].v] == d[x] + 1)  break;
            }
            cur[x] = i;
            if(i != -1)
            {
                st[top++] = i;  x = p[i].v;
            }
            else
            {
                if(!top)    break;
                d[x] = -1;
                x = p[st[--top]].u;
            }
        }
    }
   // printf("%d\n", maxflow);
}

int cal(int x, int y)
{
    int i, j, temp = map[x][y] + blx, ans = 0;

    for(i = head[temp]; i != -1; i = p[i].next)
    {
        y = p[i].v;
        if(y <= blx)    return  p[i].flow + 1;  //找到是A
    }
    //return ans;
}

int main(void)
{
    int  i, j;

    while(scanf("%d%d", &n, &m) != EOF)
    {
        init();

        scan();

        build();
        //1--blx 横着的格子 blx + 1 -- blx + white 白格  blx+white + 1--blx+white+bly 竖着的格子
//printf("~~~~~~~\n");
        dinic();

        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= m; j++)
            {
                if(map[i][j])
                {
                    printf("%d%c", cal(i, j), j == m? '\n' : ' ');
                }
                else printf("_%c", j == m ? '\n' : ' ');
            }
        }
    }
    return 0;
}
