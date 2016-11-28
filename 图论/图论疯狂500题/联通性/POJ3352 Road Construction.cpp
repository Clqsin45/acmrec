#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 5005
#define M 20004

int head[N], dfn[N], low[N], st[N], belong[N], deg[N];
bool vis[N];
int num, id, top, no;
struct point{
	int u, v, next;
	point(){};
	point(int x, int y, int z):u(x), v(y), next(z){};
}p[M];

void init(){
	memset(vis, false, sizeof(vis));
	memset(head, -1, sizeof(head));
	memset(dfn, -1, sizeof(dfn));
	memset(deg, 0, sizeof(deg));
	no = num = id = top = 0;
}

inline void add(int x, int y){
	p[no] = point(x, y , head[x]);	head[x] = no++;
	p[no] = point(y, x, head[y]);	head[y] = no++;
}

bool have(int x, int y){
	int i;
	for(i = head[x]; i != -1; i = p[i].next){
		if(y == p[i].v) return true;
	}
	return false;
}

void tarjan(int x, int fa){
//	printf("%d\n", x);
	dfn[x] = low[x] = ++num;
	st[top++] = x;
	int i, y;
	for(i = head[x]; i != -1; i = p[i].next){
		y = p[i].v;
		if(y == fa) continue;
			if(dfn[y] == -1){
			tarjan(y, x);
			low[x] = min(low[x], low[y]);
		}else low[x] = min(low[x], dfn[y]);
	}
	if(low[x] == dfn[x]){
		id++;
		do{
			y = st[--top];
			belong[y] = id;
		}while(y != x);
	}
	return;

}
int main(void){
	int n, m, i, ans, x,y;
	while(scanf("%d%d", &n, &m) != EOF){
		init(); 	ans = 0;
		for(i = 0; i < m; i++){
			scanf("%d%d", &x, &y);
			if(have(x, y))	continue;
			add(x, y);
		}
		tarjan(1, -1);
	//		printf("!!!\n");

		for(i = 0; i < no; i++){
			x = belong[p[i].u];	y = belong[p[i].v];
			if(x == y)	continue;
			deg[x] ++;
		}
		for(i = 1; i <= id; i++){

			if(deg[i] == 1)	ans ++;
		}
		printf("%d\n", (ans + 1) >> 1);
	}
	return 0;
}


