#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define N 406
#define M 44400
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

int main(){

	int n, m, w, i, j, x, all;
	while(scanf("%d", &n) != EOF){
		s = 0;	e = n * n + 1;
		init();
		all = 0;
		for(i = 1; i <= n; i++){
			for(j = 1; j <= n; j++){
				x = (i - 1) * n + j;
				scanf("%d", &w);
				all += w;

				if((i + j) & 1){
					if(i > 1) add(x, (i - 2) * n + j, INF);
					if(i < n) add(x, i * n + j, INF);
					if(j > 1) add(x, x - 1, INF);
					if(j < n) add(x, x + 1, INF);
					add(s, x, w);
				}
				else add(x, e, w);
			}
		}
		printf("%d\n", all - dinic());

	}
	return 0;
}
