#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 304
#define INF 0x3f3f3f3f

int f[N][N], p[N], dis[N], s, n;
bool v[N];

int swag(){
	int i, j, ans = INF, k, pre = 0; //0 is the source
	bool flag = false;
	for(i = 1; i <=n; i++)	{
		if(i == s){
			p[0] = s;
			flag = true;
		}
		else p[i - flag] = i;
	}
	while(n > 1){
		pre = 0;
		memset(v, false, sizeof(v));
		memset(dis, 0, sizeof(dis));
		for(i = 1; i < n; i++){   // like prim
			k = -1;
			for(j = 1; j < n; j++){
				if(!v[p[j]]){
					dis[p[j]] += f[p[pre]][p[j]];
					if(k == -1 || dis[p[k]] < dis[p[j]]) k = j;
				}
			}
			v[p[k]] = true;//add to A
			if(i == n - 1){  //final
				ans = min(ans, dis[p[k]]);
				for(j = 0; j < n; j++){
					f[p[pre]][p[j]] += f[p[j]][p[k]];
					f[p[j]][p[pre]] += f[p[j]][p[k]];
				}
				p[k] = p[--n];       //delete the final point
			}
			pre = k;
		}
	}
	return ans;
}
int main(){
	freopen("in", "r", stdin);
	int i, j, x, y, m, w;
	while(scanf("%d%d%d", &n, &m, &s) && (n || m || s)){
		memset(f, 0, sizeof(f));
		while(m--){
			scanf("%d%d%d", &x, &y, &w);

			f[x][y] += w;
			f[y][x] += w;
		}
		printf("%d\n", swag());
	}
	return 0;
}

