#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 10004
#define M 10004

int head[N], dfn[N], in[N];

struct point{
	int u, v, next;
	point(){};
	point(int x, int y, int z): u(x), v(y), next(z){};
}p[M];
int QX, QY, no, n, m;

void init(){
	memset(head, -1, sizeof(head));
	memset(dfn, -1, sizeof(dfn));
	memset(in, 0, sizeof(in));
	no = 0;
}

void add(int x, int y){
	p[no] = point(x, y, head[x]);	head[x] = no++;
}


int find(int x){
	if(x == dfn[x]) return x;
	return dfn[x] = find(dfn[x]);
}
void tarjan(int x, int fa){
	int i, y;
	dfn[x] = x;
//	printf("%d\n",x);
	if(x == QX && dfn[QY] != -1){
		printf("%d\n", find(QY));
		return;
	}
	else if(x == QY && dfn[QX] != -1){
		printf("%d\n", find(QX));
		return;
	}
	for(i = head[x]; i != -1; i = p[i].next){
		y = p[i].v;
		if(dfn[y] == -1) tarjan(y, x);
	}
	dfn[x] = fa;
}


int main(){
	int i, TC, x, y;
	scanf("%d",  &TC);
	while(TC--){
		scanf("%d", &n);
		m = n - 1;
		init();
		while(m--){
			scanf("%d%d", &x, &y);
			add(x, y);
			in[y] ++;
		}
		scanf("%d%d", &QX, &QY);
		for(i = 1; i <=n ;i++){
			if(in[i]) continue;
			tarjan(i, i);
					break;
		}
		//printf("%d\n", ans);
	}
}


