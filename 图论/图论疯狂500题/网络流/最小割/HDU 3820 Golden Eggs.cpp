#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define N 5005
#define M 56000
#define INF 0x3f3f3f3f

int head[N], d[N], cur[N], st[M], s, e, no;
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

int main()
{
	int n, m, i, j, w, g, h, tc, TC, sum, x, all;
	scanf("%d", &TC);
	for(tc = 1; tc <= TC; tc++){
		scanf("%d%d%d%d", &n, &m, &g, &h);
		init();	sum = 0;
		s = 0;	e = n * m * 2 + 1;	all = n * m;
		for(i = 1; i <= n; i++){
			for(j = 1; j <= m; j++){
				scanf("%d", &w);	sum += w;
				x = (i - 1) * m + j;
				add(x, x + all, INF);
				if((i + j) & 1){
					add(s, x, w);
					if(i > 1)	add(x, (i - 2) * m + j + all, g);
					if(i < n) 	add(x, i * m + j + all, g);
					if(j > 1) 	add(x, x - 1 + all, g);
					if(j < m) 	add(x, x + 1 + all, g);
				}
				else{

					add(x + all, e, w);
				}
			}
		}
		for(i = 1; i <= n; i++){
			for(j = 1; j <= m; j++){
				scanf("%d", &w);	sum += w;
				x = (i - 1) * m + j;
				if((i + j) & 1)  add(x + all, e, w);
				else {
					add(s, x, w);
					if(i > 1)	add(x, (i - 2) * m + j + all, h);
					if(i < n) 	add(x, i * m + j + all, h);
					if(j > 1) 	add(x, x - 1 + all, h);
					if(j < m) 	add(x, x + 1 + all, h);
				}
			}
		}
		printf("Case %d: ", tc);
		printf("%d\n", sum - dinic());
	}

}
