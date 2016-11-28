#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 10004
#define M 20010
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1

int son[N], size[N], top[N], intr[N], deep[N], head[N], fa[N];
int ext[M<<2], num[M<<2];
char op[10];

struct point{
	int u, v, next, w;
	point(){};
	point(int x, int y, int z, int ww): u(x), v(y), next(z), w(ww){};
}p[M];

struct record{
	int x, y, z;
	record(){};
	record(int xx, int yy, int zz): x(xx), y(yy), z(zz){};
}rec[M];

int no, id;

void init(){
	memset(head, -1, sizeof(head));
	memset(ext, 0, sizeof(ext));
	no = id = 0;
}

void add(int x, int y , int z){
	p[no] = point(x, y, head[x], z);	head[x] = no++;
	p[no] = point(y, x, head[y], z);	head[y] = no++;
}


void dfs(int x){
	int i, y, temp = 0, lc = -1;
	size[x] = 1;
	for(i = head[x]; i != -1; i = p[i].next){
		y = p[i].v;
		if(y == fa[x]) continue;
		fa[y] = x;	deep[y] = deep[x] + 1;
		dfs(y);
		size[x] += size[y];
		if(temp < size[y]){
			temp = size[y];
			lc = y;
		}
	}
	son[x] = lc;
}


void gao(int x, int tp){
	intr[x] = ++id;	top[x] = tp;
	if(son[x] != -1)	gao(son[x], tp);

	int i, y;
	for(i = head[x]; i != -1; i = p[i].next){
		y = p[i].v;
		if(y != son[x] && y != fa[x])
			gao(y, y);
	}
}

void pushup(int x){
	ext[x] = max(ext[x<<1], ext[x<<1|1]);
}
void build(int l, int r, int rt){
	if(l == r){
		ext[rt] = num[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(lson);	build(rson);
	pushup(rt);
}

void modify(int p, int val, int l, int r, int rt){
	if(l == r){
	//	numl] = val;
		ext[rt] = val;
		return;
	}

	int mid = (l + r) >> 1;
	if(p <= mid) modify(p, val, lson);
	else modify(p, val, rson);
	pushup(rt);
}


int quire(int L, int R, int l, int r, int rt){
//	printf("%d %d %d %d %d\n", L, R, l, r, rt);
	if(L <= l && r <= R) return ext[rt];
	int ans= 0 ;
	int mid = (l + r) >> 1;
	if(L <= mid) ans = quire(L, R, lson);
	if( R > mid) ans = max(ans, quire(L, R, rson));
	return ans;
}

int find(int x, int  y){
	int fx = top[x], fy = top[y];
	int ans = 0;//	printf("%d %d %d\n",fx ,fy, ans);

	while(fx != fy){
		if(deep[fx] < deep[fy]){
			swap(fx, fy);	swap(x, y);
		}
		ans = max(ans, quire(intr[fx], intr[x], 1, id, 1));
			x = fa[fx];	fx = top[x];
	}
	if(x == y) return ans;
	if(deep[x] > deep[y]) swap(x, y);
//	printf("%d %d\n", intr[son[x]], intr[y]);
	ans = max(ans, quire(intr[son[x]], intr[y],1, id, 1));
	return ans;
}
int main(){
	int TC, i, n, x, y, z;
	scanf("%d", &TC);
	while(TC--){
		scanf("%d", &n);
		init();
		for(i = 1; i < n; i++){
			scanf("%d%d%d", &x, &y, &z);
			rec[i] = record(x, y, z);
			add(x, y, z);
		}
		fa[1] = -1;	deep[1] = 0;
		dfs(1);
		gao(1, 1);
		for(i = 1; i < n; i++){
			if(deep[rec[i].x] > deep[rec[i].y]) swap(rec[i].x, rec[i].y);
			num[intr[rec[i].y]] = rec[i].z;
		}
		build(1, id, 1);

		while(scanf("%s", op) && op[0] != 'D'){
			scanf("%d%d", &x, &y);
			if(op[0] == 'Q'){
				printf("%d\n", find(x, y));
			}
			else {
				modify(intr[rec[x].y], y, 1, id, 1);
			}
		}
	}
	return 0;
}

