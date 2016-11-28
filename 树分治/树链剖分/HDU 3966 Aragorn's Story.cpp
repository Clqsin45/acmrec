/************************
树链剖分+线段树区间修改
2014.10.19
要扩栈
*************************/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 500005
#define M 1000005
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1

int head[N], num[N << 2], lazy[N << 2];
int dir[N], top[N], deep[N],size[N], son[N], fa[N], intr[N], w[N];
bool vis[N];
int no, id;

struct point{
	int u, v, next;
	point(){};
	point(int x, int  y, int z): u(x), v(y), next(z){};
}p[M];

void init(void){
	memset(head, -1, sizeof(head));
	no = 0, id = 0;
}

void add(int x, int y){
	p[no] = point(x, y, head[x]);	head[x] = no++;
	p[no] = point(y,x,head[y]);	head[y] = no++;
}

void dfs(int x){
	int i, y, temp = 0, lc = -1;
	size[x] = 1;

	for(i = head[x]; i != -1; i = p[i].next){
		y = p[i].v;
		if(y == fa[x]) continue;
		deep[y] = deep[x] + 1;
		fa[y] = x;
		dfs(y);

		size[x] += size[y];
		if(size[y] > temp){
			temp = size[y];	lc = y;
		}
	}
	son[x] = lc;
}

void dfs(int x, int tp){
	top[x] = tp;	intr[x] = ++id;	dir[id] = x;
	if(son[x] != -1) dfs(son[x], tp);
	int i, y;
	for(i = head[x]; i != -1; i = p[i].next){
		y = p[i].v;
		if(y == fa[x] || y == son[x]) continue;
		dfs(y, y);
	}
}

void pushdown(int x){
	if(lazy[x]){
		lazy[x<<1] += lazy[x];
		lazy[x<<1|1] += lazy[x];
		num[x<<1] += lazy[x];
		num[x<<1|1] += lazy[x];
		lazy[x] = 0;
	}
}

void build(int l, int r, int rt){
	lazy[rt] = 0;

	if(l == r) {
		num[rt] = w[dir[l]];
	//	printf("%d\n", l);
		return;
	}

	int mid = (l + r) >> 1;
	build(lson);
	build(rson);
}
void modify(int L, int R, int val, int l, int r, int rt){
	if( L <= l && R >= r){
		lazy[rt] += val;
		num[rt] += val;
		return;
	}

	pushdown(rt);

	int mid = (l + r) >> 1;
	if(L <= mid) modify(L, R, val, lson);
	if(R > mid) modify(L, R, val, rson);
}

int quire(int pos, int l, int r, int rt){
	if(l == r){
		//printf("%d\n", pos);
		return num[rt];
	}
	pushdown(rt);

	int mid = (l + r) >> 1;
	if(pos <= mid) return quire(pos, lson);
	else return quire(pos, rson);
}


void updata(int x, int y, int val){
	int fx = top[x], fy = top[y];
//	printf("%d %d\n", fx, fy);
	while(fx != fy){
		if(deep[fx] < deep[fy]){
			swap(x, y);	swap(fx, fy);
		}
		modify(intr[fx], intr[x], val, 1, id, 1);
		x = fa[fx];	fx = top[x];

	}

	if(deep[x] > deep[y]) swap(x, y);


	modify(intr[x], intr[y], val, 1, id, 1);
}


int main(void){
	int x, y,n, m, P, z, i;
	char op[10];

	while(scanf("%d%d%d", &n, &m, &P) != EOF){
		init();
		for(i = 1; i <= n; i++){
			scanf("%d", &w[i]);
		}
		while(m--){
			scanf("%d%d", &x, &y);
			add(x, y);
		}
		fa[1]= -1;	deep[1] = 0;
		dfs(1);
		dfs(1, 1);
		build(1, n, 1);
		while(P--){
			scanf("%s", op);
			if(op[0] == 'Q'){
				scanf("%d", &x);
				printf("%d\n",quire(intr[x], 1, n, 1));
			}
			else {
				scanf("%d%d%d", &x, &y, &z);
				updata(x, y, z * (op[0] == 'I' ?  1 : -1));
			}
		}
	}
	return 0;
}


