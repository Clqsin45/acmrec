#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define N 204
#define M 40004
#define INF 0x3f3f3f3f
#define eps 1e-8

int head[N], cur[N], d[N], st[M], s, e, no, n;
struct point{
	int u, v, flow, next;
	point(){};
	point(int x, int y, int z, int w):u(x), v(y), next(z), flow(w){};
}p[M];
struct record{
	double x,  y;

}recg[N], rech[N];

void add(int x, int y, int z){
	p[no] = point(x, y, head[x], z);	head[x] = no++;
	p[no] = point(y, x, head[y], 0);	head[y] = no++;
}
void init(){
	memset(head, -1, sizeof(head));
	no = 0;
}

bool bfs(){
	int i, x, y;
	queue<int>q;
	memset(d, -1, sizeof(d));
	d[s] = 0;	q.push(s);
	while(!q.empty()){
		x = q.front();	q.pop();
		for(i = head[x]; i != -1; i = p[i].next){
			if(p[i].flow && d[y = p[i].v] < 0){
				d[y] = d[x] + 1;
				if(y == e)	return true;
				q.push(y);
			}
		}
	}
	return false;
}

int dinic(){
	int i, loc, top, x = s, nowflow, maxflow = 0;
	while(bfs()){
		for(i = s; i <= e; i++)	cur[i] = head[i];
		top = 0;
		while(true){
			if(x == e){
				nowflow = INF;
				for(i = 0; i < top; i ++){
					if(nowflow > p[st[i]].flow){
						nowflow = p[st[i]].flow;
						loc = i;
					}
				}
				for(i = 0; i < top; i++){
					p[st[i]].flow -= nowflow;
					p[st[i]^1].flow += nowflow;
				}
				maxflow += nowflow;
				top = loc;	x = p[st[top]].u;
			}
			for(i = cur[x]; i != -1; i = p[i].next)
				if(p[i].flow && d[p[i].v] == d[x] + 1) break;
			cur[x] = i;
			if(i != -1){
				st[top ++] = i;
				x = p[i].v;
			}
			else {
				if(!top)	break;
				d[x] = -1;
				x = p[st[--top]].u;
			}
		}
	}
	return maxflow;
}

int main()
{
	int i, j,  m, lim, v;
	double x, y;
	while(scanf("%d%d%d%d", &n, &m, &lim, &v) != EOF){
		init();
		s = 0;	e = n + m + 1;
		for(i = 1; i <= n; i++){
			scanf("%lf%lf", &recg[i].x, &recg[i].y);
			add(s, i, 1);
		}
		for(i = 1; i <= m; i++){
			scanf("%lf%lf", &rech[i].x, &rech[i].y);
			add(i + n, e, 1);
		}
		for(i = 1; i <= n; i++){
			for(j = 1; j <= m; j++){
				x = (recg[i].x - rech[j].x)*(recg[i].x - rech[j].x)
					+(recg[i].y - rech[j].y)*(recg[i].y - rech[j].y);
				y = lim * lim * v * v;
				if(x < y - eps)	add(i, j + n, INF);
			}
		}
		printf("%d\n",n -  dinic());
	}
	return 0;
}


