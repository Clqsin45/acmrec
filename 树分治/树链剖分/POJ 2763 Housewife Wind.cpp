#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 100005
#define M 200005
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1

int head[N], son[N], deep[N], size[N];
int fa[N], top[N], intr[N], sum[N << 2], num[N];

int no, id;

struct point{
	int u, v, next, w;
	point(){};
	point(int x, int y, int z, int ww): u(x), v(y), next(z), w(ww){};
}p[M];

struct record{
	int u, v, w;
	record(){};
	record(int x, int y, int z): u(x), v(y), w(z){};
}rec[M];

void init(){
	memset(head, -1, sizeof(head));
	memset(sum, 0, sizeof(sum));
	no = id = 0;
}

void add(int x, int y, int z){
	p[no] = point(x, y, head[x], z);	head[x] = no++;
	p[no] = point(y, x, head[y], z);	head[y] = no++;
}


void dfs(int x){
	int i, y, temp = 0, lc = -1;
	size[x] = 1;

	for(i = head[x]; i != -1; i = p[i].next){
		y = p[i].v;
		if(y == fa[x]) continue;
		deep[y] = deep[x] + 1;	fa[y] = x;
		dfs(y);
		size[x] += size[y];
		if(size[y] > temp){
			temp = size[y];
			lc = y;
		}
	}
	son[x] = lc;
}

void dfs(int x, int tp){
	intr[x] =++id;	top[x] = tp;
	if(son[x] != -1) dfs(son[x], tp);
	int i, y;
	for(i = head[x]; i != -1; i = p[i].next){
		y = p[i].v;
		if(y == fa[x] || y == son[x]) continue;
		dfs(y, y);
	}
}

void pushup(int x){
	sum[x] = sum[x<<1]+sum[x<<1|1];
}

void build(int l, int r, int rt){
	sum[rt] = 0;
	if(l == r) {
		sum[rt] = num[l];
		return;
	}

	int mid = (l + r) >> 1;
	build(lson);	build(rson);
	pushup(rt);
}

void modify(int pos, int val, int l, int r, int rt){
	if(l == r){
		sum[rt] = val;
		return;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid) modify(pos, val, lson);
	else modify(pos, val, rson);
	pushup(rt);
}

int quire(int L, int R, int l, int r, int rt){
	//printf("%d %d %d %d\n", L , R, l, r);
	if(L <= l && R >= r){
	//	printf("!!!%d\n", sum[rt]);
		return sum[rt];
	}
	int temp = 0, mid = (l + r) >> 1;
	if(L <= mid) temp = quire(L, R, lson);
	if(R > mid) temp += quire(L, R, rson);
	return temp;
}

int find(int x, int y){
	int fx = top[x], fy = top[y];
	int temp = 0;
//	printf("%d %d\n", fx, fy);

	while(fx != fy){
	//	printf("%d %d\n", fx, fy);

		if(deep[fx] < deep[fy]){
			swap(fx, fy);	swap(x,y);
		}
		temp += quire(intr[fx], intr[x], 1, id, 1);
		x = fa[fx];	fx = top[x];
	//	printf("%d %d\n", fx, fy);
	}
	if(x == y) return temp;
	if(deep[x] > deep[y]) swap(x,y);
//	printf("%d %d\n", intr[son[x]], intr[y]);
	temp += quire(intr[son[x]], intr[y], 1, id, 1);
	return temp;
}



int main(void){
	int n, m, i, x, y, z, op;
	int q, s;
	while(scanf("%d%d%d", &n, &q, &s) != EOF){
		init();

		for(i = 1; i < n; i++){
			scanf("%d%d%d", &x, &y, &z);
			add(x,y,z);
			rec[i] = record(x, y, z);
		}

		deep[1] = 0;	fa[1] = -1;
		num[1] = 0;
		dfs(1);
		dfs(1, 1);

		for(i = 1; i < n; i++){
			if(deep[rec[i].u] > deep[rec[i].v] ) swap(rec[i].u, rec[i].v);
			num[intr[rec[i].v]] = rec[i].w;
		}
		build(1, n, 1);

		while(q--){
			scanf("%d", &op);
			if(op){
				scanf("%d%d", &x, &y);
				modify(intr[rec[x].v], y, 1, n, 1);
			}
			else {
				scanf("%d", &x);
				printf("%d\n", find(s, x));
				s = x;
			}
		}
	}
	return 0;
}

