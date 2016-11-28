#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

#define N 3008
#define M 65000
#define LL __int64
#define INF 0x3f7f7f7f
struct point{
    int u, v, flow, cost, next;
}p[M];
int head[N], pre[N], vis[N], d[N], s, e, maxflow, n, mincost, no;
void add(int x, int y, int z, int ct)
{
    p[no].u = x;    p[no].v = y;    p[no].cost = ct;
    p[no].flow = z;
    p[no].next = head[x];   head[x] = no++;
        p[no].u = y;    p[no].v = x;    p[no].cost = -ct;
    p[no].flow = 0;
    p[no].next = head[y];   head[y] = no++; return;
}
void init(){
    memset(head, -1, sizeof(head));
    no = 0;
}
bool spfa()
{
    queue<int>q;
    int x, y, now, i;
    for(i = s; i <= e; i++)
    {
        d[i] = INF; vis[i] = 0;   pre[i] = -1;
    }
    q.push(s);  d[s] = 0;   vis[s] = 1;
    while(!q.empty())
    {
        x = q.front();  q.pop();
        //printf("%d\n", x);
        vis[x] = 0;
        for(i = head[x]; i != -1; i = p[i].next)
        {
            y = p[i].v;
            //printf("%d  %d  %d\n", y, d[y], p[i].flow);
            if(p[i].flow && d[y] > d[x] + p[i].cost)
            {
                d[y] = d[x] + p[i].cost;
                //printf("%d\n", d[y]);
                pre[y] = i;
                if(!vis[y])
                {
                    q.push(y);
                    vis[y] = 1;
                }
            }
        }
    }
    return (d[e] != INF);


}

void mcmf()
{
    int  i, minflow;
    maxflow = mincost = 0;
    while(spfa())
    {
        minflow = INF + 1;
        for(i = pre[e]; i != -1; i = pre[p[i].u])
        {
            if(p[i].flow < minflow)
                minflow = p[i].flow;
        }
        for(i = pre[e]; i != -1; i = pre[p[i].u])
        {
            p[i].flow -= minflow;
            p[i ^ 1].flow += minflow;
        }
        maxflow += minflow;
        mincost += d[e] * minflow;
       // printf("%d\n", mincost);
    }
    return;
}

inline int scan_d() {
	char c;
	int ret=0;
	while((c=getchar())<'0'||c>'9');
	while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();
	return ret;
}

int main(void)
{
    int tc, TC, m, x, y, z, i;
    scanf("%d", &TC);
    for(tc = 1; tc <= TC; tc++){
        scanf("%d%d", &n, &m);
        init();
        s = 0;  e = 2 * n + 1;
        while(m--){
            //scanf("%d%d%d", &x, &y, &z);
            x = scan_d();   y = scan_d();   z = scan_d();
            add(x, y + n, 1, z);
            add(y, x + n, 1, z);
        }
        for(i = 1; i <= n; i++){
            add(s, i , 1, 0);
            add(n + i, e, 1, 0);
        }
        mcmf();
        printf("Case %d: ", tc);
        if(maxflow != n){
            printf("NO\n");
        }else printf("%d\n", mincost);

    }
    return 0;
}
