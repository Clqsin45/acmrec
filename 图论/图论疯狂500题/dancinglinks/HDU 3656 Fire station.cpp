#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define N 55
#define T 4003
#define INF 0x3f3f3f3f
int n, m;
int dis[N][N], num[T];
int maxn;
struct DLX{
	int l[T], r[T], u[T], d[T];
	int cnt[N], col[T], head[N];
	bool vis[N];

	int id, n;

	void init(int nt){
		this->n = nt;
		int i;
		for(i = 0; i <= n; i++){
			u[i] = d[i]  = i;
			l[i] = i-1;	r[i] = i + 1;

		}
		l[0] = n;	r[n]  = 0;
		memset(cnt, 0, sizeof(cnt));
		memset(head, -1, sizeof(head));
		id = n + 1;
	}

	void add(int x, int y){
		d[id] = y;	u[id] = u[y];
		d[u[y]] = id;	u[y] = id;

		if(head[x] == -1){
			head[x] = l[id] = r[id] = id;
		}
		else{
			l[id ] = head[x];	r[id] = r[head[x]];
			l[r[head[x]]] = id;	r[head[x]] = id;
			head[x] = id;
		}
		col[id] = y;	cnt[y] ++;
		id ++;
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
		int i, j, k, ans = 0;
		memset(vis, false, sizeof(vis));
		for(i = r[0]; i != 0; i = r[i]){
			if(vis[i]) continue;
			ans ++;	vis[i] = true;
			for(j = d[i]; j != i; j = d[j]){
				for(k = r[j] ; k != j; k = r[k]){
					vis[col[k]] = true;
				}
			}
		}
		return ans;
	}
	bool dfs(int ct){
		if(ct + H() > m) return false;
		if(r[0 ] == 0) return true;

		int i, j, idx, temp = INF;
		for(i = r[0]; i != 0; i = r[i]){
			if(cnt[i] < temp){
				temp = cnt[i];
				idx = i;
			}
		}
		for(i = d[idx]; i != idx; i = d[i]){
			del(i);
			for(j = r[i]; j != i; j =r[j]){
				del(j);
			}if(dfs(ct + 1)) return true;
			for(j = l[i]; j != i; j = l[j]){
				resume(j);
			}
			resume(i);
		}
		return false;
	}


}dlx;
struct point{
	int x, y;
}p[N];

void cal(){
	int i, j;
	dis[0][0] = 0;
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			dis[i][j] = (p[i].x-p[j].x)*(p[i].x-p[j].x)
				+(p[i].y-p[j].y)*(p[i].y-p[j].y);
		//	dis[0][0] = max(dis[0][0], dis[i][j]);
		//	printf("%d ", dis[i][j]);
			num[++maxn] = dis[i][j];
		}
		//printf("\n");
	}
}
void build(int mid){
	int i, j;
	dlx.init(n);

	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			if(dis[i][j] <= mid) 	dlx.add(i, j);
		}
	}
}



int main(void){
	int TC, i;

	int low, mid, ans, high;

	scanf("%d", &TC);
	while(TC--){
		scanf("%d%d", &n, &m);
		for(i = 1; i <= n; i++){
			scanf("%d%d", &p[i].x, &p[i].y);
		}
		maxn = 0;	cal();

		sort(num + 1, num + 1 + maxn);
//		for(i = 1; i <= maxn; i++) printf("%d\n", num[i]);

		maxn = unique(num+1, num+1+maxn)-num;
	//	printf("%d\n", maxn);
		low = 1;	high = maxn-1;
		while(low <= high){
			mid = (low+high)>>1;
			build(num[mid]);
			if(dlx.dfs(0)){
				ans = num[mid];
				high = mid -1;
			}
			else low = mid + 1;
		}
		printf("%.6f\n", sqrt((double)ans));
	}
	return 0;
}
