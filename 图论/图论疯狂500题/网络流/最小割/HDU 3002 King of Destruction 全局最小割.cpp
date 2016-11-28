#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define N 104
#define M 400000
#define INF 0x3f3f3f3f

int f[N][N], dis[N],v[N], n; // dis[i] = disof(i, Aj);
bool vis[N];      //in A or not

int swag(){
	int i, j, ans = INF, k, pre = 0; //0 is the source
	for(i = 0; i < n; i++)	v[i] = i;
	while(n > 1){
		pre = 0;
		memset(vis, false, sizeof(vis));
		memset(dis, 0, sizeof(dis));
		for(i = 1; i < n; i++){   // like prim
			k = -1;
			for(j = 1; j < n; j++){
				if(!vis[v[j]]){
					dis[v[j]] += f[v[pre]][v[j]];
					if(k == -1 || dis[v[k]] < dis[v[j]]) k = j;
				}
			}
			vis[v[k]] = true;//add to A
			if(i == n - 1){  //final
				ans = min(ans, dis[v[k]]);
				for(j = 0; j < n; j++){
					f[v[pre]][v[j]] += f[v[j]][v[k]];
					f[v[j]][v[pre]] += f[v[j]][v[k]];
				}
				v[k] = v[--n];       //delete the final point
			}
			pre = k;
		}
	}
	return ans;
}
int main(){

	int m, w, x, y, i;
	while(scanf("%d%d", &n, &m) != EOF){
		memset(f, 0,sizeof(f));
		while(m--){
			scanf("%d%d%d", &x, &y, &w);
			f[x][y] += w;
			f[y][x] += w;
		}
		printf("%d\n", swag());
	}
	return 0;
}
