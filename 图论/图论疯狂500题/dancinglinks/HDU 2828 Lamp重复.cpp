#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define N 1004
#define T 1000004
#define INF 0x3f3f3f3f

int f[N][N>>1], ans[504];
vector<int>v;
int M ;
struct DLX{
	int r[T], l[T], u[T], d[T];
	int cnt[N], col[T], row[N], head[N];
	bool vis[N];
	int n, id;
	void init(int n){
		this->n = n;
		int i;
		for(i = 0; i <= n; i++){
			d[i] = u[i] = i;
			l[i] = i - 1;	r[i] = i + 1;
		}
		id = n + 1;
		r[n] = 0;	l[0] = n;
		memset(cnt, 0, sizeof(cnt));
		memset(vis, false, sizeof(vis));
		memset(head, -1, sizeof(head));
	}
	void add(int R, int C){
		d[id] =  C;	u[id] = u[C];
		d[u[C]] = id;	u[C]  = id;

		if(head[R] < 0 ){
			head[R] = l[id] = r[id] = id;
		}
		else {
			l[id] = head[R];	r[id] = r[head[R]];
			l[r[head[R]]] =id;	r[head[R]] = id;
			head[R] = id;
		}
		cnt[C] ++;	col[id] = C;	row[id] =R;
		id ++;
	}
	void remove(int x){
		int i;
		for(i = u[x]; i != x; i = u[i]){
			l[r[i]] = l[i];
			r[l[i]] = r[i];
		}
	}

	void resume(int x){
		int i;
		for(i = d[x]; i != x; i = d[i]){
			l[r[i]] = i;	r[l[i]] = i;
		}
	}
	bool dfs(){
		if(r[0] == 0) return true;

		int i, c = r[0], j;
		for(i = r[0]; i != 0; i = r[i]){
			if(cnt[i] <cnt[c]) c = i;
		}
		for(i = d[c]; i != c; i = d[i]){
			if(vis[row[i]^1] ) continue;
			vis[row[i]] = true;
			remove(i);
			for(j = r[i]; j != i; j = r[j]){
				remove(j);
			}

			if(dfs()) return true;
			for(j = l[i]; j != i; j = l[j])					resume(j);
				resume(j);
			resume(i);		vis[row[i]] = false;
		}
		return false;

	}

}dlx;

bool gao(int n, int m){
	dlx.init(n);
	m <<= 1;

	int i, j;
	for(i = 0; i < m; i++){
		for(j = 1; j <= n; j++){
			if(f[i][j]){
				dlx.add(i, j);
			}
		}
	}
	return dlx.dfs();
}


int main(){
	int n, m, i, k, x;
	char op[10];
	while(scanf("%d%d", &n, &m) != EOF){
		memset(f, 0, sizeof(f));
		M = n;
		for(i = 1; i <= n; i++){
			scanf("%d", &k);
			while(k--){
				scanf("%d%s", &x, op);
				x--;
				if(op[1] == 'N'){
					f[x<<1][i] = 1;
				}
				else f[x<<1|1][i] = 1;
			}

		}

		if(gao(n, m)){
			for(i = 0; i < m; i++){
				printf("%s%c", dlx.vis[i<<1] ? "ON": "OFF", i == m - 1? '\n' : ' ');
			}
		}
		else printf("-1\n");
	}
	return 0;
}


