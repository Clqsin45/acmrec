#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define N 2504
#define M 64000
#define T 55
#define INF 0x3f3f3f3f

int head[N], d[N], cur[N], st[M], s, e, no;
int f[T][T];
bool vis[T][T];
struct point{
	int u, v, flow, next;
	point(){};
	point(int x, int y, int z, int w):u(x), v(y), next(z), flow(w){};
}p[M];

void init(){
	memset(head, -1, sizeof(head));
	memset(vis, false, sizeof(vis));
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

int main(){
	freopen("in", "r", stdin);
	int n, m, i, j, sum, cmd, x;
	while(scanf("%d%d%d", &n, &m, &cmd) != EOF){
		init();	sum = 0;
		s = 0;	e = n * m + 1;
		for(i = 1; i <= n; i++){
			for(j = 1; j <= m; j++){
				scanf("%d", &f[i][j]);
				sum += f[i][j];
			}
		}
		while(cmd--){
			scanf("%d%d", &i, &j);
			vis[i][j] = true;
		}
		for(i = 1; i <= n; i++){
			for(j = 1; j <= m; j++){
				x = (i - 1) * m + j;
				if((i + j) & 1){
					add(s, x, vis[i][j] ? INF: f[i][j]);
					if(i > 1)	add(x, (i - 2) * m + j, 2 * (f[i][j] & f[i - 1][j]));
					if(i < n)	add(x, i * m + j, 2 * (f[i][j] & f[i + 1][j]));
					if(j > 1)	add(x, x - 1, 2 * (f[i][j] & f[i][j - 1]));
					if(j < m)	add(x, x + 1, 2 * (f[i][j] & f[i][j + 1]));
				}
				else add(x , e, vis[i][j] ? INF:f[i][j]);

			}
		}
		printf("%d\n", sum - dinic());
	}
	return 0;
}
