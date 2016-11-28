#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 200004
#define LL long long
int dp[N], HQ[N], head[N], dfn[N], ans[N];
bool vis[N];
int no;
struct point{
	int u, v, next;
	point(){};
	point(int x, int y, int z): u(x),  v(y), next(z){};
}p[N], Q[N];
LL ct;
void init(){
	memset(head, -1, sizeof(head));
	memset(HQ, -1, sizeof(HQ));
	memset(vis, false, sizeof(vis));
	memset(dfn, -1, sizeof(dfn));
	memset(dp, 0, sizeof(dp));
	no = 0;	ct = 0LL;
}

void add(int x, int y){
	p[no] = point(x, y, head[x]);	head[x] = no++;
	p[no] = point(y, x, head[y]);	head[y] = no++;
}
void add(int x, int y, bool PPP){
	Q[no] = point(x, y, HQ[x]);	HQ[x] = no++;
	Q[no] = point(y, x, HQ[y]);	HQ[y] = no++;
}

int find(int x){
	if(x == dfn[x]) return x;
	return dfn[x] = find(dfn[x]);
}

void tarjan(int x, int fa){
	dfn[x] = x;
	int i, y;

	for(i = head[x]; i != -1; i = p[i].next){
		if(dfn[y = p[i].v] == -1){
			tarjan(y, x);
		}
	}
	for(i = HQ[x]; i != -1; i = Q[i].next){
		if(vis[i>>1] ) continue;
		if(dfn[y = Q[i].v] != -1){
			ans[i>>1] = find(y);
			vis[i>>1] = true;
		}
	}
	dfn[x] = fa;
}
void dfs(int x){
	vis[x] = true;
	int i, y;
	for(i = head[x]; i != -1; i = p[i].next){
		y = p[i].v;
		if(vis[y]) continue;
		dfs(y);
		dp[x] += dp[y];
	}
}
int main(void){
	int i, n, m, x, y;
	while(scanf("%d%d", &n, &m) != EOF){
		init();
		for(i = 1; i < n; i++){
			scanf("%d%d", &x, &y);
			add(x, y);
		}
		no = 0;
		for(i = 0; i < m; i++){
			scanf("%d%d", &x, &y);
			add(x, y, 1);
		}
		tarjan(1, 1);

		for(i = 0; i < m; i++){
			dp[Q[i<<1].u] ++;	dp[Q[i<<1].v] ++;

			dp[ans[i]] -= 2;
		}

		memset(vis, false, sizeof(vis));
		dfs(1);
		for(i = 2; i <= n; i++){
			if(dp[i] == 0)	ct += m;
			else if(dp[i] == 1) ct ++;
		}
		printf("%lld\n", ct);
	}
	return 0;
}
