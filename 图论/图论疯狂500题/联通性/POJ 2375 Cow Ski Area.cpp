#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

#define N 250005
#define M 2000005
#define LL long long
#define INF 0x3f3f3f3f
int head[N], dfn[N], low[N], belong[N], out[N],in[N], st[N];
int gox[4] = {0, 0, -1, 1}, goy[4] = {1, -1, 0, 0};
int f[505][505];
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
	int x, y, n, m, i,j,k, ctin, ctout,all;
	while(scanf("%d%d", &m, &n ) != EOF){
		init();
		ctin = ctout = 0;
		all = n * m;
		for(i = 1; i <= n; i++){
			for(j = 1; j <= m; j++){
				scanf("%d", &f[i][j]);
			}
		}
		for(i = 1; i <= n; i++){
		//	cout<<"!!!"<<endl;
			for(j = 1; j <= m; j++){
						//	cout<<i<<j<<endl;
//cin>>x;
				for(k = 0; k < 4; k++){

					x = i + gox[k];	y = j +goy[k];
					if(x < 1 || x > n || y < 1 || y > m) continue;
					if(f[i][j] >= f[x][y]) add((i-1)*m+j, (x-1)*m+y);
				}
			}
		}

		for(i = 1; i <= all; i++){
			if(dfn[i] == -1) tarjan(i);
		}
		if(id == 1) {
			printf("0\n");
			continue;
		}
		for(i = 0; i < no; i++){
			x = belong[p[i].u];	y = belong[p[i].v];
			if(x == y) continue;
			out[x] ++;	in[y] ++;
		}
		for(i = 1; i <= id; i ++){
			if(in[i] == 0) ctin ++;
			if(out[i] == 0) ctout++;
		}
		printf("%d\n", max(ctin, ctout));

	}
	return 0;
}
