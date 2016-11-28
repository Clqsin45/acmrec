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
int head[N], cur[N], d[N], st[M], s, e, no, n, m, ans;
int score[N];
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

void build(int mid){
	int i, j, t = 0;
	m = (n - 1) * n / 2;
	init();
	s = 0;	e = n + m + 1;
	for(i = 1; i <= n; i++){
		add(s, i, score[i]);
	}
	for(i = 1; i <= m; i++){
		add(i + n, e, 1);
	}
	for(i = 1; i <= n; i++){
		for(j = i + 1; j <= n; j++){
			t ++;
			if(j <= ans && score[j] < score[i]){
				add(j, t + n, 1 );
			}
			else {
				add(i, t + n, 1);
				add(j, t + n, 1);
			}
		}
	}
}

bool cmp(int x, int y){
	return x > y;
}

int main()
{
	freopen("in", "r", stdin);
	int i, j, x, y, z, low, high, mid, sum, TC;
	char st, del[N];
	scanf("%d", &TC);
	getchar();
	while(TC--){

		init();  i = 0; ans = 1; sum = 0;
		while(st = getchar()){

			if(st == '\n') break;
			else if(st >= '0' && st <= '9'){	score[++i] = st - '0';
				printf("%d %d\n",i,score[i]);
			}
		}
		n = i;

		sort(score + 1, score + n + 1, cmp);
		sum = (n-1)*n/2;
		for(ans = 2; ans <= n; ans ++){
			build(ans)	;
			int temp = dinic();
			printf("%d %d\n", temp, sum);
			if(temp < sum) {ans --;	break;}
		}
		printf("%d\n", ans);
	}
	return 0;

}


