/*****************
选出最多个数st每个数互相不能整除。。
为什么感觉 不是dlx。。。
= =
*******************/


#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 1004
#define T 1000004
#define ll __int64
#define INF 0x3f3f3f3f
int ans;
struct DLX{
	int l[T], r[T], u[T], d[T];
	int col[T], row[T], cnt[N], head[N];
	int id, n;

	void init(int nt){
		this->n = nt;
		int i;
		for(i = 0; i <= n; i++){
			u[i] = d[i] = i;
			l[i] = i - 1; r[i] = i + 1;
		}
		r[n] = 0;	l[0] = n;
		memset(cnt, false, sizeof(cnt));
		memset(head, -1, sizeof(head));
		id = n + 1;
	}

	void add(int x, int y){
		int i;
		u[id] = u[y];	d[id] = y;
		d[u[id]] = id;	u[y] = id;

		if(head[x] == -1){
			head[x] = l[id] = r[id] = id;
		}
		else{
			l[id] = head[x];	r[id] = r[head[x]];
			l[r[head[x]]] = id;	r[head[x]] = id;
			head[x] = id;
		}
		cnt[y] ++;col[id] = y;
		id++;
	}

	void del(int x){
		int i, j;
		for(i = u[x]; i != x; i = u[i]){
			l[r[i]] = l[i];	r[l[i]] = r[i];
		}
	}

	void resume(int x){
		int i, j;
		for(i = d[x]; i != x; i = d[i]){
			l[r[i]] = i;	r[l[i]] = i;
		}
	}

	int H(){
		int i, ans = 0;
		for(i = r[0]; i != 0; i =r[i]) ans ++;
		return ans;
	}

	void dfs(int ct){
		if(r[0] == 0) {
			ans = max(ans, ct);
			return;
		}
		if(ct + H() <= ans)	return;

		int i, j, temp = INF, idx;
		for(i = r[0]; i != 0; i = r[i]){
			if(temp > cnt[i]){
				temp = cnt[i];
				idx = i;
			}
		}
		for(i = d[idx]; i != idx; i = d[i]){
			del(i);
			for(j = r[i]; j != i; j = r[j]){
				del(j);
			}
			dfs(ct + 1);
			for(j = l[i]; j != i; j = l[j]){
				resume(j);
			}
			resume(i);
		}
	}
}dlx;
ll a[N];

int main(){
	int i, j, n, m;
	int TC;
	scanf("%d", &TC);
	while(TC--){
		scanf("%d", &n);
		dlx.init(n);
		for(i = 1; i <= n; i++){
			scanf("%I64d", &a[i]);
		}
		for(i = 1; i <= n; i++){
			for(j = 1; j <= n; j++){
				if(a[j] % a[i] && a[i] % a[j])continue;
				dlx.add(i, j);
			//	printf("%d %d\n", i, j);
			}
		}
		ans = 0;
		dlx.dfs(0);
//		printf("%d\n", ans);
	cout<<ans<<endl;
	}
	return 0;

}
