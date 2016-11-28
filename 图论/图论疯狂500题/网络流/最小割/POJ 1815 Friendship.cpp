#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

#define N 404
#define M 84000
#define INF 0x3f3f3f3f

int head[N], f[202][202], d[N], st[M], cur[N], s, e, no, n, m;
bool vis[N];
vector<int>v;

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
	memset(vis, false, sizeof(vis));
	v.clear();
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

int main(){
	freopen("in", "r", stdin);
	int i, j, x, y, ans, temp, k, pre;
	while(scanf("%d%d%d", &n, &x, &y) != EOF){
		init();
		s = 0;	e = 2 * n + 1;
		for(i = 1; i <= n; i++){
			if(i == x|| i == y)	add(i, i + n, INF);
			else add(i, i + n, 1);
		}

		for(i = 1; i <= n; i++){
			for(j = 1; j <= n; j++){
				scanf("%d", &f[i][j]);
				if(f[i][j]){
					add(i + n, j, INF);
				}
			}
		}
		add(s, x, INF);	add(y, e, INF);
		if(f[x][y]){
			printf("NO ANSWER!\n");
			continue;
		}
	    pre = ans = dinic();

		for(i = 1; i <= n; i++){
			if(i == x|| i == y)continue;
			memset(head, -1, sizeof(head));
			no = 0;
			for(j = 1; j <= n; j++){
				if(j == i)	continue;
				if(vis[j])	continue;
				if(j == x || j == y)	add(j, j + n, INF);
				else add(j, j + n, 1);
			}
			for(j = 1; j <= n; j++){
			//	if(j == i)	continue;
				for(k = 1; k <= n; k++){
				//	if(k == i)	continue;
					if(f[j][k]){
						add(j + n, k, INF);
					}
				}
			}
			add(s, x, INF);	add(y, e, INF);
			temp = dinic();
		//	printf("%d %d\n", temp, i);
			if(temp < pre){
				vis[i] = true;	pre = temp;
				v.push_back(i);
			}

		}
		printf("%d\n", ans);
		if(ans == 0)	continue;
		x = v.size();
		for(i = 0; i < x; i++){
			printf("%d%c", v[i], i == x - 1 ? '\n' : ' ');
		}
	}
	return 0;
}




