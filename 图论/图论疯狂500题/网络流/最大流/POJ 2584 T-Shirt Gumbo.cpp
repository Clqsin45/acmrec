#include <cstdio>
#include <cstring>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <map>
using namespace std;
#define N 40
#define M 2004
#define INF 0x3f3f3f3f
#define eps 1e-8
map<char, int>f;
int head[N], cur[N], d[N], st[M], s, e, no, n;

struct point{
	int u, v, flow, next;
	point(){};
	point(int x, int y, int z, int w):u(x), v(y), next(z), flow(w){};
}p[M];
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
	freopen("in", "r", stdin);
	int TC, i, j, num, x, y, w;
 	char cont[104];
	s = 0;	e = 28;
	f['S'] = 1;	f['M'] = 2;	f['L'] = 3;	f['X'] = 4;	f['T'] =5;
	while(scanf("%s", cont)){

		if(cont[0] != 'S')	break;
		scanf("%d", &n);
		init();
		for(i = 1; i <= n; i++){
			add(s, i, 1);
			scanf("%s", cont);
			x = f[cont[0]]; y =f[cont[1]];
			for(j = x; j <= y; j++){
				add(i, j + n, 1);
			}
		}

		for(i = 1; i <= 5; i++){
			scanf("%d", &w);
			add(i + n, e, w);

		}

		if(dinic() == n)	printf("T-shirts rock!\n");
		else printf("I'd rather not wear a shirt anyway...\n");
		scanf("%s", cont);
	}
	return 0;
}


