#include <bits/stdc++.h>
using namespace std;
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define N 30004
#define M 60006
#define INF 0x3f3f3f3f
int head[N], size[N],top[N], w[N], son[N], intr[N], fa[N], deep[N];
int no, id;
int ans[N<<2], sum[M<<2];
struct point{
	int u, v, next;
	point(){};
	point(int x, int y, int z): u(x), v(y), next(z){};
}p[M];
void init(){
	memset(head, -1, sizeof(head));
	no = 0;	id = 0;
}

void add(int x, int y){
	p[no] = point(x, y, head[x]);	head[x] = no++;
	p[no] = point(y, x, head[y]);	head[y] = no++;
}

void dfs(int x){
	size[x] = 1;
	int i, y, temp = 0, loc = -1;
	for(i = head[x]; i != -1; i = p[i].next){
		y = p[i].v;
		if(y == fa[x]) continue;
		fa[y] =x;	deep[y] = deep[x] + 1;
		dfs(y);
		size[x] += size[y];
		if(size[y] > temp){
			loc = y;
			temp = size[y];
		}
	}
	son[x] = loc;
}
void dfs(int x, int tp){
	top[x] = tp;	intr[x]  = ++id;
	if(son[x] == -1) return ;
	dfs(son[x], tp);
	int i, y;
	for(i = head[x]; i != -1; i = p[i].next){
		y = p[i].v;
		if(y == fa[x] || y == son[x]) continue;
		dfs(y, y);
	}
}

void pushup(int x){
	sum[x] = sum[x<<1] + sum[x<<1|1];
	ans[x] = max(ans[x<<1], ans[x<<1|1]);
}

void build(int l, int r, int rt){
	if(l == r) {
		sum[rt] = ans[rt] = w[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(lson);	build(rson);
	pushup(rt);
}


void modify(int p, int val, int l, int r, int rt){
	if(l == r){
		ans[rt] = sum[rt] =  val;
		return;
	}
	int mid = (l + r) >> 1;
	if(p <= mid) modify(p, val, lson);
	else modify(p, val, rson);
	pushup(rt);
}

int quiremax(int L, int R, int l, int r, int rt){
	if(L <= l && R >= r){
		return ans[rt];
	}
	int mid = (l + r) >> 1, temp = -INF;
	if(L <= mid) temp = quiremax(L, R, lson);
	if(R > mid) temp = max(temp, quiremax(L, R, rson));
	return temp;

}

int quiresum(int L, int R, int l, int r, int rt){
	if(L <= l && R >= r){
		return sum[rt];
	}
	int mid = (l + r ) >> 1, temp  = 0;
	if(L <= mid) temp = quiresum(L, R, lson);
	if(R > mid) temp += quiresum(L, R, rson);
	return temp;
}

int findmax(int x, int y)
{
	int fx = top[x], fy = top[y];
	int temp = -INF;
	while(fx != fy){
		if(deep[fx] < deep[fy]) {
			swap(x, y);
			swap(fx, fy);
		}
		temp = max(temp, quiremax(intr[fx], intr[x], 1, id, 1));
		x = fa[fx];	fx = top[x];
	}
	if(deep[x] > deep[y]) swap(x, y);
	temp = max(temp, quiremax(intr[x], intr[y], 1 ,id, 1));

	return temp;
}

int findsum(int x, int y)
{
	int fx = top[x], fy = top[y];
	int temp = 0;
	while(fx != fy){
		if(deep[fx] < deep[fy]) {
			swap(x, y);
			swap(fx, fy);
		}
		temp += quiresum(intr[fx], intr[x], 1, id, 1);
		x = fa[fx];	fx = top[x];
	}
	if(deep[x] > deep[y]) swap(x, y);

	temp += quiresum(intr[x], intr[y], 1, id, 1);
	return temp;
}

int main(void){
	int n, Q, i, x, y;
	char op[10];
	while(scanf("%d", &n) != EOF){
		init();
		for(i = 1; i < n; i++){
			scanf("%d%d", &x, &y);
			add(x, y);
		}
		dfs(1);
		dfs(1, 1);
		for(i = 1; i <= n; i++){
			scanf("%d", &x);
			w[intr[i]] = x;
		}
		build(1, n, 1);

		scanf("%d", &Q);
		while(Q--){
			scanf("%s%d%d", op, &x, &y);

			if(op[0] == 'C'){
				modify(intr[x], y, 1, n, 1);
			}
			else {
				if(op[1] == 'M'){
					printf("%d\n", findmax(x, y));
				}
				else printf("%d\n", findsum(x, y));
			}
		}
	}
	return 0;
}

