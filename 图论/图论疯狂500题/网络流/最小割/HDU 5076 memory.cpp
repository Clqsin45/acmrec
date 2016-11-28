#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define N 6666
#define M 6666
#define INF 0x3f3f3f3f
int head[N], dir[280], d[N], cur[N], vis[N], st[M];
int selectmin[280], selectmax[280];
int a[N], val[N];
int no, s, e;
struct point{
	int u, v, next, flow;
	point(){};
	point(int x, int y, int z, int w):u(x), v(y), next(z),flow(w){};
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
	int i, y, x;
	memset(d, -1, sizeof(d));
	queue<int>q;
	q.push(s);
	d[s] = 0;
	while(!q.empty()){
		x = q.front();	q.pop();
		for(i = head[x]; i != -1; i = p[i].next){
			y = p[i].v;
			if(p[i].flow>0 && d[y] < 0){
				d[y] = d[x] + 1;
				if(y == e) return true;
				q.push(y);
			}
		}
	}
	return false;
}

void dinic(){
	int i, top = 0, x = s, nowflow, maxflow = 0, loc;
	while(bfs()){
		for(i = 0; i <= e; i++){
			cur[i] = head[i];
		}
		top = 0;
		while(true){
			if(x == e){
				nowflow = INF;
				for(i = 0; i < top; i++){
					if(p[st[i]].flow < nowflow){
						loc = i;	nowflow = p[st[i]].flow;
					}
				}
				for(i = 0; i < top; i++){
					p[st[i]].flow -= nowflow;
					p[st[i]^1].flow += nowflow;
				}
				maxflow += nowflow;
				top = loc;	x = p[st[top]].u;
			}
			for(i = cur[x];  i != -1; i = p[i].next)
				if(p[i].flow > 0 && d[x] == d[p[i].v] - 1) break;
			cur[x] = i;
			if(~i){
				st[top++] = i;
				x = p[i].v;
			}
			else {
				if(!top) break;
				d[x] = -1;
				x = p[st[--top]].u;
			}
		}
	//	printf("!!%d\n", maxflow );
	}
	//return maxflow;
}

int gao(int x){
	int cnt = 0;
	while(x){
		cnt += (x & 1);
		x >>= 1;
	}
	return cnt;
}
void dabiao(){
	int i;
	for(i = 0; i < 256; i++){
		dir[i] = gao(i);
	}
}
int main(void){

	int TC, n, m, x, y, z, i, j, high, low, sum ;
	scanf("%d", &TC);
	dabiao();
	while(TC--){
		scanf("%d%d", &n, &m);
		n = (1 << n);	m = (1 << m);
		init();		sum = 0;
		for(i = 0; i < n; i++){
			scanf("%d", &a[i]);
		}
		for(i = 0; i < n; i ++){
			scanf("%d", &val[i]);
		}
		s = n << 1;	e = s + 1;

		for(i = 0; i < n; i++){
			high = low = -INF;
			for(j = 0;j < a[i]; j++){
				scanf("%d", &x);
				x += 1024;
				if(x > low){
					selectmin[i] = j;
					low = x;
				}
			}
			for(; j < m; j++){
				scanf("%d", &x);
				x += 1024;
				if(x > high){
					high = x;
					selectmax[i] = j;
				}
			}

			if(dir[i] & 1){
				add(s, i, low);	add(i, i + n, INF);
				add(i + n, e, high);
			//	printf("%d %d %d\n", i, low, high);
			}
			else {
				add(s, i, high);
				add(i, i + n, INF);
				add(i + n, e, low);

			//	printf("%d %d %d\n", i, low, high);
			}
		}
		/*
		for(i = 0; i < n; i++){
			printf("%d %d %d %d\n", i, a[i], selectmin[i], selectmax[i]);
		}
		*/


		for(i = 0; i < n; i++){

				for(j = i+1; j < n; j++){
					if(dir[i^j] != 1) continue;
					if(dir[i]&1)
						add(i, j + n, (val[i] ^ val[j]));
					else add(j, i + n, val[i] ^ val[j]);
				//	sum +=( (val[i] ^ val[j]));
				}

		}
		dinic();
		//printf("%d\n", sum - dinic());
		int tep = (n * 6);

		for(i = 0; i < n; i++){
			if(i) printf(" ");
			if(dir[i] & 1){
				if(d[i] != -1) printf("%d", selectmin[i]);
				else printf("%d", selectmax[i]);
			}
			else{
				if(d[i] != -1) printf("%d", selectmax[i]);
				else printf("%d", selectmin[i]);
			}
		}
		printf("\n");

	}
	return 0;
}


