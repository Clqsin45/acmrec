#include <cstdlib>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;

#define N 104
#define M 54000
#define INF 0x3f3f3f3f
int head[N], d[N], cur[N], st[M], s, e, no, n, m;
bool f[N][N];
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
	memset(f, 0 , sizeof(f));
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

void build(int x, int y){
	int i, j;
	memset(head, -1, sizeof(head));	no = 0;
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			if(f[i][j])	add(i + n, j, INF);
		}
	}
	for(i = 1; i <= n; i++){
		if(i == x || i == y)add(i, i + n, INF);
		else 	add(i, i + n, 1);
	}
	add(s, x, INF);	add(y, e, INF);
}
int main(){
	freopen("in", "r", stdin);
	char ch[100];
	int i, j, x, y,  temp, k,  ans;
	while(scanf("%d%d", &n, &m) != EOF){
		init();
		if(n == 0 || n == 1){
			printf("%d\n", n);
			continue;
		}
		s = 0;	e = 2 * n + 1;
		for(i = 1; i <= m; i++){
			scanf("%s", ch);
			sscanf(ch, "(%d,%d)", &x, &y);
			x ++;	y ++;
			f[x][y] = f[y][x] = true;
		}
		ans = INF;
		for(i = 1; i <= n; i++){
			for(j = 1; j <= n; j++){
				if(i == j||f[i][j] )	continue;
				build(i, j);
				temp = dinic();
				//printf("%d %d %d\n", i, j, temp);
				ans = min(ans, temp);
			}
		}
		if(ans == INF)	ans = n;
		printf("%d\n", ans);
	}

	return 0;
}
