#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 1004
#define M 1000004

int head[N], dfn[N], low[N], st[M];
bool bridge[M], vis[M];
int num, top, no;
struct point{
	int u, v, next;
	point(){};
	point(int x, int y, int z):u(x), v(y), next(z){};
}p[M];
void init(){
	memset(bridge, false, sizeof(bridge));
	memset(dfn, -1,sizeof(dfn));
	memset(head, -1, sizeof(head));
	memset(vis,false, sizeof(vis));
	no = num = top = 0;
}
void add(int x, int  y){

	p[no] = point(x, y, head[x]);
	head[x] = no++;

	p[no] = point(y, x, head[y]);
	head[y] = no++;
}

void tarjan(int x, int fa){
	low[x] = dfn[x] = ++num;
	int i, y;
	for(i = head[x]; i != -1; i = p[i].next){
		y = p[i].v;
		if(y == fa) continue;
		if(dfn[y] == -1){
			tarjan(y, x);
			low[x] = min(low[x], low[y]);
			if(dfn[x] < low[y])	bridge[i] = true;
		}
		else low[x] = min(low[x], dfn[y]);
	}


}

void dfs(int x){
	dfn[x] = 1;
	int i, y;
	for(i = head[x]; i != -1; i = p[i].next){
		y = p[i].v;
		if(vis[i/2]) continue;
		vis[i/2] = true;
		printf("%d %d\n", x,y);
		if(bridge[i] || bridge[i^1]) printf("%d %d\n",y, x);
		if(dfn[y]) continue;
		dfs(y);
	}
}

int main(void){
	int i, x, y, n, m;
	int tc = 0;
	while(scanf("%d%d", &n, &m)  &&(n || m)){
		init();
		while(m--){
			scanf("%d%d", &x,&y);
			add(x, y);
		}

		tarjan(1, -1);
		printf("%d\n\n", ++tc);
		memset(dfn, 0, sizeof(dfn));
		for(i = 1; i <= n; i++){
			if(dfn[i]) continue;
			dfs(i);
		}
		printf("#\n");

	}
	return 0;
}

