#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define N 40004
#define M 400004
#define INF 0x3f3f3f3f
int head[N], d[N], st[M],cur[N], s, e, no;
struct point{
	int u, v, flow, next;
	point(){};
	point(int x, int y, int z, int w):u(x), v(y), next(z), flow(w){};
}p[M];
void init(){
	memset(head, -1, sizeof(head));
	no = 0;
}
void add(int x, int y, int z){
	p[no] = point(x, y, head[x], z); head[x] = no++;
	p[no] = point(y, x, head[y], 0);	head[y] = no++;
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
	int n, m, x, y, tc = 1, w, i, j;
	while(scanf("%d%d", &n, &m)!= EOF){
		printf("Case %d:\n", tc++);
		init();
		s = 0;	e = n * m + 1;
		for(i = 1; i <= n; i++){
			for(j = 1; j <= m; j++){
				scanf("%d", &w);
				x = (i - 1) * m + j;
				if(i > 1) add(x, (i - 2) * m + j, 1);
				if(i < n) add(x, i * m + j, 1);
				if(j > 1) add(x, x - 1, 1);
				if(j < m) add(x, x + 1, 1);
				if(w == 1) add(s, x, INF);
				if(w == 2) add(x, e, INF);
			}
		}
		printf("%d\n", dinic());
	}
	return 0;
}
