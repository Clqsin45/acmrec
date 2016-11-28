#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

#define N 1004
#define M 40000
#define LL __int64
#define INF 0x3f7f7f7f

struct point{
    int u, v, flow, next, cost;
    point(){};
    point(int x, int y, int z, int w, int c):u(x), v(y), next(z), flow(w), cost(c){};
}p[M];
int d[N], head[N], pre[N], vis[N], f[N], n, m, no, s, e;

void add(int x, int y, int w, int c){
    p[no] = point(x, y, head[x], w, c);
	head[x] = no++;
    p[no] = point(y, x, head[y], 0, -c);    head[y] = no++;
}

void init(){
	memset(head, -1, sizeof(head));
	no = 0;
}


bool spfa(){
    queue<int>q;
    int i, x, y;
    memset(d, 0x3f, sizeof(d));
    memset(vis, 0, sizeof(vis));
    memset(pre, -1, sizeof(pre));
	d[s] = 0;
    q.push(s);  vis[s] = true;
    while(!q.empty()){

		x = q.front();  q.pop();;
		for(i = head[x]; i != -1; i = p[i].next){
            y = p[i].v;
			if(p[i].flow && d[y] > d[x] + p[i].cost){
                d[y] = d[x] + p[i].cost;
                pre[y] = i;
                if(vis[y])    continue;
                vis[y] = true;
                q.push(y);
            }
        }
		vis[x] = 0;
    }
    return d[e] != d[e + 1];
}
int mcmf(){
    int i, minflow, maxlow = 0, maxcost = 0;

    while(spfa()){
        minflow = INF;
        for(i = pre[e]; i != -1; i = pre[p[i].u]){
			minflow = min(minflow, p[i].flow);
        }
        for(i = pre[e]; i != -1; i = pre[p[i].u]){
            p[i].flow -= minflow;
            p[i^1].flow += minflow;
        }
        maxcost += d[e] * minflow;
    }
    return maxcost;
}
int main(void)
{
    int i, j, x, y, z;
    scanf("%d%d", &n, &m);
    init();
    for(i = 1; i <= n; i++){
        scanf("%d", &f[i]);
    }
    f[0] = f[n + 1] = 0;
    s = 0;  e = n + 1;
    while(m--){
        scanf("%d%d%d", &x, &y, &z);
        add(x, y + 1, INF, z);
    }
    for(i = 1; i <= n + 1; i ++){
        x = f[i] - f[i - 1];
        if(x >= 0)  {
            add(s, i, x, 0);
        }
        else add(i, e, -x, 0);
        if(i > 1)   add(i, i - 1, INF, 0);
    }
    //printf("!!!!!!\n");
    printf("%d\n", mcmf());

    return 0;
}
