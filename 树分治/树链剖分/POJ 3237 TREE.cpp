#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define N  100004
#define M 2000010
#define INF 0x3f3f3f3f
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1

int head[N], top[N], fa[N], size[N],son[N], ans[N], num[N];
int lazy[N], intr[N], deep[N],mmm[N], change[N];

struct point{
	int u, v, next;
	point(){};
	point(int x, int y, int z) : u(x), v(y), next(z){};
}p[M], rec[N];

int no, id;

void init(){
	memset(head, -1, sizeof(head));
	memset(lazy, -1, sizeof(lazy));
	memset(ans, 0x80, sizeof(ans));
	memset(mmm, 0x3f, sizeof(mmm));
	no = id = 0;
}

void add(int x, int y){
	p[no] = point(x, y, head[x]);	head[x] = no++;
	p[no] = point(y, x, head[y]);	head[y] = no++;
}

void dfs(int x){
	int i, y, temp = 0, lc = -1;
	size[x] = 1;
	for(i = head[x]; i != -1; i = p[i].next){
		y = p[i].v;

		if(y == fa[x])	continue;

		deep[y] = deep[x] + 1;	fa[y] = x;
		dfs(y);
		size[x]+= size[y];
		if(size[y] > temp){
			temp = size[y];	lc = y;
		}
	}
	son[x] = lc;
}

void dfs(int x, int tp){

	intr[x] = ++id;	top[x] = tp;

	if(son[x] != -1) dfs(son[x] , tp);
	int i, y;
	for(i = head[x]; i != -1; i = p[i].next){
		y = p[i].v;
		if(fa[x] == y || son[x] == y){
			continue;
		}
		dfs(y, y);
	}
}


void pushup(int x){
	ans[x] = max(ans[x<<1], ans[x<<1|1]);
	mmm[x] = min (mmm[x<<1], mmm[x<<1|1]);
}

void pushdown(int x){
	if(lazy[x] & 1){
		int tm;
		lazy[x<<1] ^= 1;
		lazy[x<<1|1] ^= 1;
		tm = ans[x<<1]; ans[x<<1] = -mmm[x<<1]; mmm[x<<1] = -tm;
		tm = ans[x<<1|1]; ans[x<<1|1] = -mmm[x<<1|1]; mmm[x<<1|1] = -tm;
		lazy[x] = 0;
	}
}

void build(int l, int r, int rt){
	lazy[rt] = 0;
	if(l == r){
		ans[rt] = mmm[rt] = num[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(lson);	build(rson);
	pushup(rt);
}




void modify(int L, int R, int l, int r, int rt){
	if(L <= l && R >= r){
		mmm[rt] = -mmm[rt];	ans[rt] = -ans[rt];
		swap(mmm[rt], ans[rt]);
		lazy[rt] ^= 1;
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(rt);
	if(L <= mid) modify(L, R,lson);
	if(R > mid)	modify(L, R,rson);
	pushup(rt);
}

void updata(int p, int val, int l, int r, int rt) {
	if(l == r){
		mmm[rt] = ans[rt] = val;
		//printf("%d %d %d\n", p, val, rt);
		return ;

	}

	pushdown(rt);
	int mid = (l + r) >> 1;
	if(p <= mid) updata(p, val, lson);
	else updata(p, val, rson);
	pushup(rt);
}


int quire(int L, int R, int l, int r, int rt){
	if(L <= l && R >= r){
		return ans[rt];

	}
	pushdown(rt);

	int temp =-INF, mid = (l + r) >> 1;
	if(L <= mid) temp = quire(L, R, lson);
	if(R > mid) temp =max(temp, quire(L, R, rson));
	return temp;
}


int find(int x, int y){
	int fx = top[x], fy = top[y];
	int temp = -INF;
	while(fx != fy){
		if(deep[fy] > deep[fx]){
			swap(fx, fy);	swap(x,y);
		}
		temp = max(temp, quire(intr[fx], intr[x], 1, id, 1));
		x = fa[fx];	fx=top[x];
	}
	if(x == y) return temp;
	if(deep[x] > deep[y]) swap(x, y);
	temp = max(temp, quire(intr[son[x]], intr[y], 1, id, 1));

	return temp;
}


void modify(int x, int y){
	int fx = top[x], fy = top[y];

	while(fx != fy){
		if(deep[fx] < deep[fy]){
			swap(x,y);	swap(fx, fy);
		}
		modify(intr[fx], intr[x],  1, id, 1);
		x = fa[fx];	fx = top[x];
	}
	if(deep[x] > deep[y])	swap(x, y);
	modify(intr[son[x]], intr[y],1, id, 1);
}

int main(void){
	int TC, n, i, x, y, z;
	char op[10];
	scanf("%d", &TC);
	while(TC--){
		init();
		scanf("%d", &n);
		for(i = 1; i < n; i++){

			scanf("%d%d%d", &x, &y, &z);
			add(x, y);
			rec[i] = point(x, y, z);
		}
		deep[1] = 0;	fa[1] = -1;
		dfs(1);		dfs(1, 1);
		for(i = 1; i < n; i++){
			if(deep[rec[i].u] > deep[rec[i].v]) swap(rec[i].u, rec[i].v);
			num[intr[rec[i].v]] = rec[i].next;
		}

		build(1, n, 1);
		while(scanf("%s", op) && op[0] != 'D'){
			if(op[0] == 'Q'){
				scanf("%d%d", &x, &y);
				printf("%d\n", find(x, y));
			}
			else if(op[0] == 'C'){
				scanf("%d%d", &x, &y);
				updata(intr[rec[x].v], y, 1, n, 1);
			}
			else if(op[0] == 'N'){
				scanf("%d%d", &x, &y);
				modify(x, y);
			}

		}
	}
	return 0;
}



