#include <cstdio>
#include <cstring>
#include <queue>
#include <cstdlib>
#include <algorithm>

using namespace std;
#define N 204
#define M 44000
#define INF 0x3f3f3f3f
#define eps 1e-8
int head[N], cur[N], d[N], st[M], s, e, no, n, m;
int f[N], g[N];
struct point{
	int u, v, flow, next;
	point(){};
	point(int x, int y, int z, int w):u(x), v(y), next(z), flow(w){};
}p[M];
struct record{
	int x, y, dis;
}rec[20004];
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

void build(int mid){
	int i, j;
	init();
	for(i = 1; i <= m; i++){
		if(rec[i].dis <= mid){
			add(rec[i].x, rec[i].y, INF);
			add(rec[i].y, rec[i].x, INF);
		}

	}
	for(i = 1; i <= n; i++){
		add(s, i, f[i]);
		add(i, e, g[i]);
	}
}

int main()
{
	freopen("in", "r", stdin);
	int i, j, x, y, z, low, high, mid, ans, sum;
	while(scanf("%d", &n) && n){
		init();
		high = 0;	sum = 0;	ans = -1;
		s = 0;	e = n + 1;
		for(i = 1; i <= n; i++){
			scanf("%d", &f[i]);
			sum += f[i];
		}
		for(i = 1; i <= n; i++){
			scanf("%d", &g[i]);
		}
		scanf("%d", &m);
		for(i = 1; i <= m; i++){
			scanf("%d%d%d", &rec[i].x, &rec[i].y, &rec[i].dis);
			high = max(high, rec[i].dis);
		}
		high += 1;	low = 0;
	//	printf("%d\n", high);
		while(low <= high){
			mid = (low + high) >> 1;
			build(mid);
			int temp = dinic();
		//	printf("!!!%d %d %d\n", mid, temp, sum);
			if(temp == sum)
			{
				ans = mid;	high = mid - 1;
			}
			else low = mid + 1;
		}
		if(ans == -1)	printf("No Solution\n");
		else printf("%d\n", ans);
	}
	return 0;

}


