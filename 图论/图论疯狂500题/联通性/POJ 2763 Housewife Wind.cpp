#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 200004
#define M 400010

int head[N], HQ[N], dfn[N],w[N], dis[N], ans[N], num[N], last[N];
int deep[N], c[N];
bool vis[N];

struct point{
	int u, v, next;
	point(){};
	point(int x, int y, int z): u(x), v(y), next(z){};
}p[M], Q[M];

int no, id;
void init(){
	memset(head, -1, sizeof(head));
	memset(HQ, -1, sizeof(HQ));
	memset(dfn, -1, sizeof(dfn));

	memset(vis, false, sizeof(vis));
	no = id = 0;
}

void add(int x, int y){
	p[no] = point(x, y, head[x]) ;	head[x] = no++;
	p[no] = point(y, x, head[y]);	head[y] = no++;
}

void add(int x, int y, bool vv){
	Q[no] = point(x, y, HQ[x]);	HQ[x] = no++;
	Q[no] = point(y, x, HQ[y]);	HQ[y] = no++;
}

int find(int x){
	if(x == dfn[x]) return x;
	return dfn[x] = find(dfn[x]);
}
void tarjan(int x, int fa){
	dfn[x] = x;	num[x] = ++id;

	int i, y;
	for(i = HQ[x]; i != -1; i = Q[i].next){
		if(vis[i/2])	continue;
		y = Q[i].v;
		if(dfn[y] != -1){
			vis[i>>1] = true;
			ans[i>>1] =	find(y);
		}

	}

	for(i = head[x]; i != -1; i = p[i].next){
		y = p[i].v;
		if(dfn[y] == -1){
			dis[y] = dis[x] + w[i/2];
			deep[y] = deep[x] + 1;
			tarjan(y, x);
		}
	}
	last[x] = id;

	dfn[x] = fa;
}
int lowbit(int x){
	return x & (-x);
}

void modify(int x, int k){
	for(; x <= id; x+= lowbit(x)){
	 	c[x] += k;
	}
}
int getsum(int x){
	int sum = 0;
	for(; x > 0; x -= lowbit(x))
		sum += c[x];
	return sum;
}

int main(void){
	int n, s, q;
	int i, x, y, op, u, v;

	while(scanf("%d%d%d", &n, &q, &s) != EOF){
		init();

		for(i = 1; i < n; i++){
			scanf("%d%d%d", &x, &y, &w[i-1]);
			add(x, y);
		}
		no = 0;
		while(q--){
			scanf("%d", &op);
			if(op){
				scanf("%d%d", &x, &y);
				Q[no] = point(x, y, -2);	no++;
				Q[no] = point(x,y, -2);	no++;

			}

			else {
				scanf("%d", &x);
				add(s, x, 1);
				s = x;
			}
		}
			deep[1] = dis[1] = 0;
		tarjan(1, 1);
		memset(c, 0, sizeof(c));

		for(i = 0; i < no; i+= 2){
			if(Q[i].next == -2){
				x = Q[i].u;
				x--;	x <<= 1;
				u = deep[p[x].u] > deep[p[x].v] ? p[x].u : p[x].v;
				v = last[u];
			//	printf("deg %d %d\n",num[ u], v);
				y = Q[i].v - w[x>>1];
				modify(num[u], y);
				modify(v + 1, -y);
				w[x>>1] = Q[i].v;
			}
			else {
				x = Q[i].u;	y =Q[i].v;
			//	for(int j = 1; j <= n; j++){
			//		printf("!deg  %d %d\n", j, getsum(j));
			//	}
				printf("%d\n", dis[x] + dis[y] - 2 * dis[ans[i/2]]
					+ getsum(num[x])   + getsum(num[y])- 2 *getsum(num[ans[i/2]]) );
			//	printf("!!!debug %d  %d %d\n",y, num[y], getsum(num[y]));
			}
		}
	}
	return 0;
}


