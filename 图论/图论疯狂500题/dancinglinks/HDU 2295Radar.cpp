#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define N 55
#define T 3003
#define INF 0x3f3f3f3f
int dis[N][N];
int K;
struct DLX{
	int l[T], r[T], u[T], d[T];

	int cnt[N], col[T], row[T], head[N];
	bool vis[N];
	int n, id;
	void init(int nt){
		int i;
		this->n = nt;

		for(i = 0; i <= n; i++){
			u[i] = d[i] = i;
			l[i] = i -1;	r[i] = i + 1;
		}
		l[0] = n;	r[n] = 0;
		id = n + 1;
		memset(cnt, 0, sizeof(cnt));
		memset(head, -1, sizeof(head));
	}

	void add(int x, int y){
		u[id] = u[y];	d[id] = y;
		d[u[y]] = id;	u[y] = id;


		if(head[x] == -1){
			head[x] = l[id] = r[id] = id;
		}else{
			l[id] = head[x];	r[id] = r[head[x]];
			l[r[head[x]]] = id;	r[head[x]] = id;
		}
		col[id] = y;	row[id] = x;
		cnt[y] ++;	id++;
	}


	void del(int x){
		int i;
		for(i = u[x]; i != x; i = u[i]){
			l[r[i]] = l[i];	r[l[i]] = r[i];
		}

	}

	void resume(int x){
		int i;
		for(i = d[x]; i != x; i = d[i]){
			l[r[i]] = r[l[i]] = i;
		}
	}

	int H(){
		memset(vis, false, sizeof(vis));

		int i, j,k, ans = 0;

		for(i = r[0]; i != 0; i = r[i]){
			if(vis[i]) continue;
			ans ++;	vis[i] = true;
			for(j = d[i]; j != i; j = d[j]){
				for(k = r[j]; k != j; k = r[k]){
					vis[col[k]] = true;
				}
			}
		}

		return ans;
	}

	bool dfs(int ct){
		if(ct + H() > K) return false;

		if(r[0] == 0) return true;

		int i, j, idx, temp = INF;

		for(i = r[0]; i != 0; i = r[i]){
			if(cnt[i] < temp){
				temp = cnt[i];	idx = i;
			}
		}
		for(i = d[idx]; i != idx; i = d[i]){
			del(i);
			for(j = r[i]; j != i; j =r[j]){
				del(j);
			}
			if(dfs(ct + 1)) return true;
			for(j = l[i]; j != i; j = l[j]){
				resume(j);
			}
			resume(i);
		}
		return false;
	}


}dlx;
int n, m;
struct point{
	int x, y;
}p[N], q[N];


void cal(void ){
	int i, j;
	for(i = 1; i <= m; i++)
		for(j = 1; j <= n; j++)
			dis[i][j] = (q[i].x-p[j].x)* (q[i].x-p[j].x)
				+ (q[i].y-p[j].y)* (q[i].y-p[j].y);
}


void build(int mid){
	dlx.init(n);

	int i, j;
	for(i = 1; i <= m; i++){
		for(j = 1; j <= n; j++){
			if(mid >= dis[i][j]){

				dlx.add(i, j);
			}
		}
	}

}

int main(){
	int TC;
	scanf("%d", &TC);
	int i, j;
	while(TC--){
		scanf("%d%d%d", &n, &m, &K);
		for(i = 1;  i <= n; i++){
			scanf("%d%d", &p[i].x, &p[i].y);
		}
		for(j = 1; j <= m; j++){
			scanf("%d%d", &q[j].x, &q[j].y);
		}
		cal();


		int low = 0, high =INF, mid, ans;

		while(low <= high){
			mid = (low + high) >> 1;

			build(mid);
			if(dlx.dfs(0)){
				ans = mid;
				high = mid - 1;
			}
			else low = mid + 1;
		}

		printf("%.6f\n", (double)sqrt((double)ans));
	}
	return 0;
}

