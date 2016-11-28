#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 2004
#define M 4000006

int head[N], dfn[N], low[N];
int num, top, no;
bool bridge[M/2], vis[M/2];
struct point{
	int u, v, next;
	bool app;
	point(){};
	point(int x, int y, int z, bool ap):u(x), v(y), next(z), app(ap){};
}p[M];

void init(){
	memset(head, -1, sizeof(head));
	memset(dfn, -1, sizeof(dfn));
	memset(vis, false, sizeof(vis));
	memset(bridge, false, sizeof(bridge));
	num = no =  num = 0;
}

void add(int x, int y, bool ap){
	p[no] = point(x, y, head[x], ap);	head[x] = no++;
}

void tarjan(int x, int fa){
	int i, y;
	dfn[x] = low[x] = ++num;

	for(i = head[x]; i != -1; i = p[i].next){
		y = p[i].v;
		if(fa == y) continue;

		if(dfn[y] == -1){
			tarjan(y, x);
			low[x] = min(low[x], low[y]);
			if(low[y] > dfn[x]){
				bridge[i/2] = true;
			}
		}
		else low[x]= min(low[x], dfn[y]);
	}
}

void dfs(int x){
	int i, y;
	dfn[x] = true;
	for(i = head[x]; i != -1; i = p[i].next){
		if(vis[i/2]) continue;
		vis[i/2]  = true;
		y = p[i].v;
		if(bridge[i/2]) {
			printf("%d %d %d\n", x, y, 2);
		}
		else if(p[i].app){
			if(p[i^1].app)printf("%d %d %d\n", x, y, 1);
			dfs(y);
		}
	}
}



inline int scan() {
   char c;// int sgn;
   int ret = 0;
   while((c<'0'||c>'9')) c=getchar();
   while(c>='0'&&c<='9'){
       ret=ret*10+(c-'0');
       c = getchar();
   }

   return ret;
}
int main(void){
	int n, m, i, x, y, tp;
	while(scanf("%d%d",&n, &mV) != EOF){
		init();
		for(i = 1; i <= m; i++){
			x = scan();	y = scan();	tp = scan();
	//		scanf("%d%d%d", &x, &y, &tp);
			add(x, y, 1);	add(y, x, tp == 2);
		}
		for(i = 1; i <= n; i++){

			if(dfn[i] == -1) tarjan(i, -1);
		}
		memset(dfn, 0, sizeof(dfn));
		for(i = 1; i <= n; i++){
			if(dfn[i]) continue;
			dfs(i);
		}
	}
	return 0;
}
