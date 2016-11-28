#include <cstdlib>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

#define N 204
#define M 14000
#define INF 0x3f3f3f3f
vector<int>vd;
vector<char>vc;

int head[N], d[N], cur[N], st[M], s, e, no, n, m;
bool vis[N];
struct point{
	int u, v, flow, next;
	point(){};
	point(int x, int y, int z, int w): u(x), v(y), next(z), flow(w){};
}p[M];
void add(int x, int y, int z){
	p[no] = point(x, y, head[x], z);	head[x] = no++;
	p[no] = point(y, x, head[y], 0);	head[y] = no++;
}

void init(){
	memset(head, -1, sizeof(head));
	memset(vis, 0, sizeof(vis));

	vd.clear();	vc.clear();
	no = 0;
}


bool bfs(){
	int x, y, i;
	queue<int>q;
	memset(d, -1, sizeof(d));
	q.push(s);	d[s] = 0;
	while(!q.empty()){
		x = q.front();	q.pop();
		for(i = head[x]; i != -1; i = p[i].next){
			y = p[i].v;
			if(p[i].flow && d[y] < 0){
				d[y] = d[x] + 1;
				if(y == e) return true;
				q.push(y);
			}
		}
	}
	return false;
}
int dinic(){

	int minflow, i, top, x = s, maxflow = 0, y, loc;
	while(bfs()){
		for(i = s; i <= e; i++)cur[i] = head[i];
		top = 0;
		while(true){
			if(x == e){
				minflow = INF;
				for(i = 0; i < top; i++){
					if(p[st[i]].flow < minflow){
						minflow = p[st[i]].flow;
						loc = i;
					}
				}
				for(i = 0; i < top; i++){
					p[st[i]].flow -= minflow;
					p[st[i]^1].flow += minflow;
				}
				maxflow += minflow;
				top = loc;	x = p[st[top]].u;
			}
			for(i = cur[x] ; i != -1; i = p[i].next)
				if(p[i].flow && d[p[i].v] == d[x] + 1)	break;
			cur[x] = i;
			if(i != -1){
				st[top++] = i;
				x = p[i].v;
			}
			else {
				if(!top) break;
				d[x] = -1;
				x = p[st[--top]].u;
			}
		}
	}
	return maxflow;
}
void dfs(int x){
	vis[x] = true;
	int i, y;
	for(i = head[x]; i != -1; i = p[i].next){
		if(p[i].flow && !vis[y = p[i].v]){
			dfs(y);
		}
	}
}

int main(){
	freopen("in", "r", stdin);
	int i, j, x, y,  temp, k,  ans;
	while(scanf("%d%d", &n, &m) != EOF){
		init();
		s = 0;	e = 2 * n + 1;
		for(i = 1; i <= n; i++){
			scanf("%d", &x);
			add(i + n, e, x);
		}
		for(i = 1; i <= n; i++){
			scanf("%d", &x);
			add(s, i, x);
		}
		while(m--){
			scanf("%d%d", &x, &y);

			add(x, y + n, INF);
		}

		printf("%d\n", dinic());
		dfs(s);
		for(i = 1; i <= n; i++){
			if(!vis[i]){
				vd.push_back(i);	vc.push_back('-');
			}
			if(vis[i+n]){
				vd.push_back(i);	vc.push_back('+');
			}
		}
		ans = vd.size();
		printf("%d\n", ans);
		for(i = 0; i < ans; i++){
			printf("%d  %c\n", vd[i], vc[i]);
		}

	}

	return 0;
}
