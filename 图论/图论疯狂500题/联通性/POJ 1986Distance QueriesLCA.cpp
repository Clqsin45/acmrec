#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 80004
#define M 20004

int head[N], HQ[N], dfn[N], ans[M], dis[N];
bool vis[M];
int no;
struct point{
	int u, v, next, w;
	point(){};
	point(int x, int y, int z): u(x), v(y), next(z){};
	point(int x, int y, int z, int ww): u(x), v(y), next(z),w(ww) {};
}p[N], Q[M];

void init(){
	memset(head, -1, sizeof(head));
	memset(HQ, -1, sizeof(HQ));
	memset(dfn, -1, sizeof(dfn));
	memset(vis, false, sizeof(vis));
	no = 0;
}

void add(int x, int y, int w ){
	p[no] = point(x, y, head[x], w);	head[x] = no++;
	p[no] = point(y, x, head[y], w);	head[y] = no++;
}
void add(int x, int y){
	Q[no] = point(x, y, HQ[x]);	HQ[x] = no++;
	Q[no] = point(y, x, HQ[y]);	HQ[y] = no++;
}
int find(int x){
	if(x == dfn[x]) return x;
	return dfn[x] = find(dfn[x]);
}
void tarjan(int x, int fa){
	int i,  y;
	dfn[x] = x;

	for(i = head[x]; i != -1; i = p[i].next){
		if(dfn[y = p[i].v] == -1){
			dis[y] = dis[x] + p[i].w;
			tarjan(y, x);
		}
	}
	for(i = HQ[x]; i != -1; i = Q[i].next){
		if(vis[i/2]) continue;
		if(dfn[y = Q[i].v] != -1){
			ans[i/2] =dis[x] + dis[y] - 2 * dis[find(y)];
			vis[i/2] = true;
		}
	}

	dfn[x] = fa;
}

int main(void){
	int n, m, x, y, z, i;
	char cc[10];
	int Q;
	while(scanf("%d%d", &n, &m) != EOF){
		init();
		while(m--){
			scanf("%d%d%d%s", &x, &y, &z, cc);
			add(x, y, z);
		}

		scanf("%d", &Q);	no = 0;
		for(i = 1; i <= Q; i++){

			scanf("%d%d", &x, &y);
			add(x, y);
		}

		for(i = 1; i<= n; i++){
			if(dfn[i] == -1) {
				dis[i] = 0;
				tarjan(i, i);
			}
		}
		for(i = 0; i <Q; i++){
			printf("%d\n", ans[i]);
		}

	}
	return 0;
}
