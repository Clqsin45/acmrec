#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 155
#define M 44444
#define LL __int64
#define INF 0x3f7f7f7f

int map[N][N], w[N], root, ht[N], head[N], pre[N],d[N], s, e, no, sum;
bool vis[N], isleaf[N];
struct TREE{
    int u, v, w, next;
    TREE(){};
    TREE(int x, int y, int z, int t):u(x), v(y), next(z), w(t){};
}tree[N];
struct point{
    int u, v, flow, next, cost;
    point(){};
    point(int x, int y, int z, int w, int c):u(x), v(y), next(z), flow(w), cost(c){};
}p[M];

void add(int x, int y, int w, int c){
    p[no] = point(x, y, head[x], w, c); head[x] = no++;
    p[no] = point(y, x, head[y], 0, -c);    head[y] = no++;
}
void addtree(int num, int x, int y, int z){
    tree[num] = TREE(x, y, ht[x], z); ht[x] = num;
}

void init(){
    memset(vis, false, sizeof(vis));
    memset(ht, -1, sizeof(ht));
    memset(head, -1, sizeof(head));
	memset(isleaf, false, sizeof(isleaf));
	no = sum = 0;
}
bool spfa(){
    int i, x, y;
    queue<int>q;
    memset(d, 0x3f, sizeof(d));
    memset(vis, false, sizeof(vis));
    memset(pre, -1, sizeof(pre));

    d[s] = 0;   vis[s] = true;  q.push(s);

    while(!q.empty()){
        x = q.front();  q.pop();    vis[x] = false;
        for(i = head[x]; i != -1; i = p[i].next){
            y = p[i].v;
            if(p[i].flow && d[y] > d[x] + p[i].cost){
                d[y] = d[x] + p[i].cost;
                pre[y] = i;
                if(vis[y])  continue;
                vis[y] = true;  q.push(y);
            }
        }
    }
    return d[e] != d[e + 1];
}
void mcmf(){
    int mincost = 0, maxflow = 0, minflow, i;
    while(spfa()){
        minflow =INF;
        for(i = pre[e]; i != -1; i = pre[p[i].u])
            minflow = min(minflow, p[i].flow);
        for(i = pre[e]; i != -1; i = pre[p[i].u]){
            p[i].flow -= minflow;
            p[i ^ 1].flow += minflow;
        }
        mincost += d[e] * minflow;
		maxflow += minflow;
    }
	//printf("!!!%d\n", maxflow);
	if(maxflow < sum)	printf("-1\n");
	else printf("%d\n", mincost);
	return;

}

int main(void)
{
    freopen("in", "r", stdin);
	int TC, tc, i, j, x, y, z, n, m, l,val;
    scanf("%d", &TC);
    for(tc = 1; tc <= TC; tc++){
        scanf("%d", &n);
        init();
        for(i = 1; i < n; i++){
            scanf("%d%d%d", &x, &y, &w[i]);
            map[x][y] = i;  pre[x] = i;
            addtree(i, y, x, w[i]);
        }
        s = 0;  e = n + 2;
        root = 1;
        pre[root] = n;
		w[n] = 0;
	    addtree(n, n + 1, 1, 0);

		for(i = 1; i <= n; i++){
			val = w[i];   x = tree[i].v;
		//	printf("check:%d\n", ht[x]);
			for(j = ht[x]; j != -1; j = tree[j].next){
				y = tree[j].v;
				val -= tree[j].w;
				//printf("check:%d %d\n", i, j);
				add(i, j, INF, 0);
			}
			if(val > 0){
				sum += val;
				add(s, i, val, 0);
			}
			else {
				add(i, e, -val, 0);
			}
		}

		scanf("%d", &m);

        while(m--){
            scanf("%d%d%d%d", &x, &y, &l, &z);
            add(pre[x], pre[y], l, z);
        }


		printf("Case #%d: ", tc);
		mcmf();
    }
    return 0;
}
