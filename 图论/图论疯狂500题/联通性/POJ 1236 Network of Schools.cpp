#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <iostream>
using namespace std;

#define N 104
#define M 20004
#define LL long long
#define INF 0x3f3f3f3f
int head[N], dfn[N], low[N], belong[N], in[N], out[N],  st[N];
int num, no, id, top;
bool vis[N];
struct point{
	int u, v, next;
	point(){};
	point(int x, int y, int z): u(x), v(y), next(z){};
}p[M];

void add(int x, int y){
	p[no] = point(x, y, head[x]);	head[x] = no++;
//	p[no] = point(y, x, head[y]);	head[y] = no++;
}

void init(){
	memset(head, -1, sizeof(head));
	memset(vis, false, sizeof(vis));
	memset(in, 0, sizeof(in));
	memset(out, 0, sizeof(out));
	memset(dfn, -1, sizeof(dfn));
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
		}while(y != x);
	}
	return ;
}
int main(void){
	int i, x, y, n, ans, ctin, ctout;
	while(scanf("%d", &n) != EOF){
		init();
		for(i = 1; i <= n; i++){
			while(scanf("%d", &x) && x){
				add(i, x);
			}
		}

		for(i = 1; i <= n; i++){
			if(dfn[i] == -1) tarjan(i);
		}
		if(id == 1){
			printf("1\n0\n");
			continue;
		}
		for(i = 0; i < no; i++){
			x = belong[p[i].u];	y = belong[p[i].v];
			if(x == y) continue;
			in[y] ++;	out[x] ++;
		}

		for(i = 1, ctin = 0, ctout = 0; i <= id; i++){
			if(in[i] == 0) ctin ++;
			if(out[i] == 0) ctout++;
		}
		printf("%d\n%d\n", ctin, max(ctin, ctout));
	}
	return 0;
}
