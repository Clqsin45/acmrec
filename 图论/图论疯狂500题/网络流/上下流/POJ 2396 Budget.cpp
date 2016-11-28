#include <cstdlib>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

#define N 5500
#define M 440000
#define INF 0x3f3f3f3f
int head[N], d[N], cur[N], st[M], no, n, m, sum, S, T;
int high[204][22], low[204][22];
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
	memset(low, 0, sizeof(low));
	int i, j;
	for(i = 1; i <= n; i ++){
		for(j = 1; j <= m; j++)
			high[i][j] = INF;
	}
	no = 0;
}


bool bfs(int s, int e){
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
int dinic(int s, int e){

	int minflow, i, top, x = s, maxflow = 0, y, loc;
	while(bfs(s, e)){
		for(i = 0; i <= T; i++)cur[i] = head[i];
		top = 0;
		while(true){
			if(x == e){
				minflow = INF + 1;
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

void build(int x, int y, char type, int z){
	int i, j, xs, xe, ys, ye;
    int a, b;
	if(x == 0)   {
		xs = 1;	xe = n;
	}
	else xs = xe = x;
	if(y == 0)	{
		ys = 1;	ye = m;
	}
	else ys = ye = y;
	for(i = xs; i <= xe; i++){
		for(j = ys; j <= ye; j++){
			a = (i - 1) * m + j + n + m;
			if(type == '>'){
				low[i][j] = z + 1;
			}
			else if(type == '='){
				low[i][j] = high[i][j] = z;
			}
			else {
				high[i][j] = z - 1;
			}
		}
	}
}
void add(){
	int i, j, x;
	for(i = 1; i <= n; i++){
		for(j = 1; j <= m; j ++){
			x = (i - 1) * m + j + n + m;
			if(low[i][j] == 0){
				add(i, x, high[i][j]);
				add(x, j + n, INF);
			}
			else {
				add(i, S, low[i][j]);
				add(T, x, low[i][j]);
				add(x, j + n, INF);
				sum += low[i][j];
				add(i, x, high[i][j] - low[i][j]);
			}
		}
	}
}

int main(){
	freopen("in", "r", stdin);
	int TC, i, j, x, y,  temp, k,s, e, ans, t, z;
	int sx, sy;
	char ch[10];
	scanf("%d", &TC);
	while(TC--){
		sum = sx = sy =  0;
		scanf("%d%d", &n, &m);
		s = 0;	e = n + m + n * m + 1;
		S = e + 1;	T = e + 2;
		init();
		for(i = 1; i <= n; i++){
			scanf("%d", &x);
			add(s, i, x);
			sx += x;
		}
		for(i = 1; i <= m; i++){
			scanf("%d", &x);
			add(i + n, e, x);
			sy += x;
		}
		scanf("%d", &k);
		while(k--){
			scanf("%d%d%s%d", &x, &y, ch,&z);
			build(x, y, ch[0], z);
		}
		if(sx != sy){
			printf("IMPOSSIBLE\n");
			continue;
		}
		add();

		add(e, s, INF);
		dinic(T, S);
		ans = p[no - 1].flow;
		//printf("%d %d\n", ans, sum);
		if(ans != sum){
			printf("IMPOSSIBLE\n");
			continue;
		}
		p[no - 1].flow = p[no - 2].flow = 0;
		ans += dinic(s, e);
		if(ans == sx){
		//	printf("!!!!!!!\n");
			for(i = 1; i <= n; i++){
				for(j = 1; j <= m; j++){
					x = n + m + (i - 1) * m + j;
					for(k = head[x]; k != -1; k = p[k].next){
						if(p[k].v <= n + m && p[k].v > n) temp = p[k^1].flow;
					}
					printf("%d%c", temp, j == m ? '\n' : ' ');
				}

			}
		}
		else {
			printf("IMPOSSIBLE\n");
		}
	}

	return 0;
}
