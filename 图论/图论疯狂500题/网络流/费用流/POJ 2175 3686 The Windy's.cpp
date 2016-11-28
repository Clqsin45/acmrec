#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

#define N 3000
#define M 444000
#define INF 0x3f3f3f3f

int head[N], pre[N], d[N], s, e, no, n, m;
bool vis[N];

struct point{
	int u, v, flow, next, cost;
	point(){};
	point(int x, int y, int z, int w, int c): u(x), v(y), next(z), flow(w), cost(c){};
}p[M];

void add(int x, int y, int z, int w){
	p[no] = point(x, y, head[x], z, w);	head[x] = no++;
	p[no] = point(y, x, head[y], 0, -w);	head[y] = no++;
}
void init(){
	memset(head, -1, sizeof(head));
	no = 0;
}

bool spfa(){
	int i, x, y;
	memset(d, 0x3f, sizeof(d));
	memset(pre, -1, sizeof(pre));
	memset(vis, false, sizeof(vis));
	queue<int>q;

	d[s] = 0;	q.push(s);	vis[s] = true;
	while(!q.empty()){
		x = q.front();	q.pop();	vis[x] = false;
		for(i = head[x]; i != -1; i = p[i].next){
			if(p[i].flow && d[y = p[i].v] > d[x] + p[i].cost){
				d[y] = d[x] + p[i].cost;
				pre[y] = i;
				if(vis[y]) continue;
				vis[y] = true;	q.push(y);
			}
		}
	//	printf("%d\n", x);
	}
	return d[e] != d[e + 1];
}

int mcmf(){

	int i, minflow, mincost = 0, maxflow = 0;
	int a, b;
	while(spfa()){
		minflow =INF;
	//	printf("~~~\n");
		for(i = pre[e]; i != -1; i = pre[p[i].u])
			minflow = min(minflow, p[i].flow);
		for(i = pre[e]; i != -1; i = pre[p[i].u]){
			p[i].flow -= minflow;
			p[i^1].flow += minflow;

		}
		mincost += minflow * d[e];
	}
	return mincost;
}
int main(){
	freopen("in", "r", stdin);
	int i, j, x, y, TC, all;
	int a, k;
	scanf("%d", &TC);
	while(TC--){
		scanf("%d%d", &n, &m);
		s = 0;
		all = n * m;
		e = n + all + 1;
		init();
		for(i = 1; i <= n; i++){
			for(j = 1; j <= m; j++){
				scanf("%d", &x);
				for(k = 1; k <= n; k++){
					a = n + (j - 1) * n + k;
					add(i, a, 1, k * x);

				}
			}
		}
		for(i = 1; i <= n; i++){
			add(s, i, 1, 0);
		}
		for(i = 1; i <= all; i++){
			add(i + n, e,  1, 0);
		}
		int ans= mcmf();
	//	printf("%d\n", ans);
		printf("%.6f\n", 1.0*ans/n);
	}
}
