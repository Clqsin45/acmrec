#include <cstdio>
#include <cstring>
#include <queue>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define N 1004
#define M 800050
#define INF 0x3f3f3f3f
#define eps 1e-8

int head[N], cur[N], d[N], st[M], s, e, no, n;
struct point{
	int u, v, flow, next;
	point(){};
	point(int x, int y, int z, int w):u(x), v(y), next(z), flow(w){};
}p[M];
struct record{
	int height;
	char sex;
	char mus[104], sport[104];
}rec[505];

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
	int TC, i, j;
	char temp[4];
	scanf("%d", &TC);
	while(TC--){
		scanf("%d", &n);
		init();
		s = 0;	e = 2 * n + 1;
		for(i = 1; i <= n; i++){
			scanf("%d%s%s%s", &rec[i].height, temp, rec[i].mus, rec[i].sport);
			rec[i].sex = temp[0];
		}
		for(i = 1; i <= n; i++){
			for(j = 1; j <= n; j++){
					if(i == j)  continue;
					if(abs(rec[i].height - rec[j].height) > 40) continue;
					else if(rec[i].sex == rec[j].sex)	continue;
					else if(strcmp(rec[i].mus, rec[j].mus)) continue;
					else if(strcmp(rec[i].sport, rec[j].sport) == 0)	continue;
					add(i, j + n, 1);
			}
			add(s, i, 1);	add(i + n, e, 1);

		}
		//printf("%d\n", n);
		printf("%d\n", n - dinic()/2);
	}
	return 0;
}


