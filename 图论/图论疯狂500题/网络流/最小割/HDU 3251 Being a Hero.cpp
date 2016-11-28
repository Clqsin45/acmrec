#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define N 1004
#define M 400000
#define INF 0x3f3f3f3f

int head[N], d[N], cur[N], st[M], s, e, no;
bool viss[N], vise[N];
struct point{
	int u, v, flow, next;
	point(){};
	point(int x, int y, int z, int w):u(x), v(y), next(z), flow(w){};
}p[M];
vector<int> v;

void init(){
	memset(head, -1, sizeof(head));
	memset(viss, false, sizeof(viss));
	memset(vise, false, sizeof(vise));
	no = 0;
}
void add(int x, int y, int z){
	p[no] = point(x, y, head[x], z);	head[x] = no++;
	p[no] = point(y, x, head[y], 0);	head[y] = no++;
}

bool bfs(){
	memset(d, -1, sizeof(d));
	queue<int>q;
	d[s] = 0;
	int i , x, y;
	q.push(s);
	while(!q.empty()){
		x = q.front();
		q.pop();

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

	int top, i, x = s, maxflow = 0, nowflow, loc;
	while(bfs()){
		for(i = s; i <= e; i ++) cur[i] = head[i];
		top = 0;
		while(true){
			if(x == e){
				nowflow = INF;
				for(i = 0; i < top; i++){
					if(nowflow > p[st[i]].flow){
						loc = i;
						nowflow = p[st[i]].flow;
					}
		}
				for(i = 0; i < top; i++){
					p[st[i]].flow -= nowflow;
					p[st[i]^1].flow += nowflow;
				}
				maxflow += nowflow;
				top = loc; x = p[st[top]].u;
			}
			for(i = cur[x]; i != -1; i = p[i].next)
				if(p[i].flow && d[p[i].v] == d[x] + 1) break;
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

void dfs(int op, int x, bool *vis){
	vis[x] = true;
	int y, i;
	for(i = head[x]; i != -1; i = p[i].next){
		if(p[i^op].flow && !vis[p[i].v]){
			dfs(op, p[i].v, vis);
		}
	}
}
int main(){
	freopen("in", "r", stdin);
	int tc, TC, i, j, x, y, z, n, m, w, sum;
	scanf("%d", &TC);
	for(tc = 1; tc <= TC; tc++){
		scanf("%d%d%d", &n, &m, &w);
		init();	sum = 0;	v.clear();
		s = 0; e = n + 1;
		for(i = 1; i <= m; i++){
			scanf("%d%d%d", &x, &y, &z);
			add(x, y, z);
		}
		while(w--){
			scanf("%d%d", &x, &y);
			sum += y;
			add(x, e, y);
		}
		add(s, 1, INF);
		printf("Case %d: %d\n", tc, sum - dinic());
		dfs(0, s, viss);
		dfs(1, e, vise);
		sum = 0;
		for(i = 1; i <= m; i++){
			x = 2 * (i - 1);
			if(viss[p[x].u] && vise[p[x].v]){
				v.push_back(i);
			}

		}
		x = v.size();
		printf("%d", x);
		for(i = 0; i < v.size(); i++){
			printf(" %d", v[i]);
		}
		printf("\n");

	}
}
