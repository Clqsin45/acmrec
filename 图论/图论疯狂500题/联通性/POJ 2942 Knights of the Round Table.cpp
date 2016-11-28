#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 1004
#define M 2000004

int head[N], dfn[N], low[N], st[M], col[N];
bool vis[M], f[N][N], mark[N], odd[N];
int num, id, top, no, n;
struct point{
	int u, v, next;
	point(){};
	point(int x, int y, int z):u(x), v(y), next(z){};
}p[M];

void init(){
	memset(vis, false, sizeof(vis));
	memset(head, -1, sizeof(head));
	memset(dfn, -1, sizeof(dfn));
	memset(odd, false, sizeof(odd));
	memset(f, false, sizeof(f));
	no = num = id = top = 0;
}

inline void add(int x, int y){
	p[no] = point(x, y , head[x]);	head[x] = no++;
}


bool find(int x){
	int i, y;
	for(i = head[x]; i != -1; i = p[i].next){
		y = p[i].v;
		if(mark[y]){
			if(col[y] == -1){
				col[y] = col[x] ^ 1;
				return find(y);
			}
			else if(col[y] == col[x]) return true;
		}
	}
	return false;
}
void color(int x){
	int i;
//	printf("!!!%d\n", x);
	memset(mark, false, sizeof(mark));
	do{

		i = st[--top];
//		printf("%d %d\n", p[i].u, p[i].v);
		mark[p[i].u] = 1;
		mark[p[i].v] = 1;
	}while(p[i].u != x);

	memset(col, -1, sizeof(col));
	col[x] = 0;
	if(find(x)){
		for(i = 1; i <=n ; i++){
			if(mark[i]) odd[i] = 1;
		}
	}
}
void tarjan( int x){
	int cnt = 0;
//	printf("%d\n", x);
//	printf("tttt%d \n", x);
	low[x] = dfn[x] = ++num;

	int i, y;

	for(i = head[x]; i != -1; i = p[i].next){
		if(vis[i])	continue;
		y = p[i].v;
		vis[i] = vis[i^1] = true;

		st[top++] = i;

		if(dfn[y] == -1)	{
			tarjan(y);
			low[x] = min(low[x], low[y]);
		//	printf("%d %d %d %d\n", x, y,dfn[x], low[y]);
			if(low[y] >= dfn[x]){
			//	printf("!!!!!%d\n", x);
			color(x);
			}
		}
		else low[x] = min(low[x], dfn[y]);
	}
}
void build(void){
	int i, j;
	for(i = 1; i <= n; i++){
		for(j = i + 1; j <= n; j++){
			if(f[i][j])	continue;
			add(i, j);	add(j, i);
		}

	}
	return;
}
int main(void){

	int i, x, y, m, ans;
	while(scanf("%d%d", &n, &m) &&(n || m)){
		init();		ans = 0;
		for(i = 0; i < m; i++){
			scanf("%d%d", &x, &y);
			f[x][y] = f[y][x] = true;
		}

		build();

		for(i = 1; i <= n; i++){
			if(dfn[i] == -1)	tarjan(i);
		}

		for(i = 1; i <= n; i++)
			ans += odd[i];
		printf("%d\n", n - ans);

	}
	return 0;
}


