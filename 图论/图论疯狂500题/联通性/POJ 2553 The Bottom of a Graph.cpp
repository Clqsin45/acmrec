#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

#define N 5005
#define M 250005
#define LL long long
#define INF 0x3f3f3f3f
int head[N], dfn[N], low[N], belong[N],  out[N],  st[N];
int num, no, id, top;
bool vis[N];
struct point{
	int u, v, next;
	point(){};
	point(int x, int y, int z): u(x), v(y), next(z){};
}p[M];
vector<int>f[N], v;
void add(int x, int y){
	p[no] = point(x, y, head[x]);	head[x] = no++;
//	p[no] = point(y, x, head[y]);	head[y] = no++;
}

void init(){
	memset(head, -1, sizeof(head));
	memset(vis, false, sizeof(vis));
//	memset(in, 0, sizeof(in));
	memset(out, 0, sizeof(out));
	memset(dfn, -1, sizeof(dfn));
	fill(f, f + N - 1, vector<int>() );
	v.clear();
	no = num = top = id = 0;
}
void tarjan(int x){
	dfn[x] = low[x] = ++num;
	vis[x] = true;	st[top++] = x;
	int i, y;
	for(i = head[x]; i != -1; i = p[i].next){
		y = p[i].v;
		if(dfn[y] == -1){
			tarjan(y);
			low[x] = min(low[x], low[y]);
		}
		else if(vis[y]){
			low[x] = min(low[x], dfn[y]);
		}
	}
	if(low[x] == dfn[x]){
		id++;
		do{
			y = st[--top];
			vis[y] = false;
			belong[y] = id;
			f[id].push_back(y);
		}while(y != x);
	}
	return ;
}

int main(void){
	int x, y, n, m, i,j, ans;
	while(scanf("%d", &n) && n){
		init();
		scanf("%d", &m);
		for(i = 0; i < m; i++){
			scanf("%d%d", &x, &y);
			add(x, y);
		}
	//	printf("!!!\n");
		for(i = 1; i <= n; i++){
			if(dfn[i] == -1) tarjan(i);
		}
		if(id == 1){
			for(i = 1; i <= n; i++){
				printf("%d%c", i, i == n ? '\n' : ' ');
			}
			continue;
		}
		for(i = 0; i < m; i++){
			x = belong[p[i].u];	y = belong[p[i].v];
			if(x == y) continue;
			out[x] ++;
		}
		for(i = 1; i <= id; i++){
			if(out[i] == 0){
				m = f[i].size();
				for(j = 0; j < m; j++){
					v.push_back(f[i][j]);
				}
			}
		}
		n = v.size();
		sort(v.begin(), v.end());
	//	printf("!!!%d\n", n);
		for(i = 0; i < n; i++){
			printf("%d%c", v[i], i == n - 1 ? '\n' : ' ');
		}
	}
	return 0;
}
