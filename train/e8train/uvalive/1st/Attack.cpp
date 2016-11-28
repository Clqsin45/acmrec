#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

#define N 10004
#define M 60000000
#define INF 0x3f3f3f3f

int d[N], head[N], cur[N], st[M];
int no, s, e;
struct point{
	int u, v, next, flow;
	point(){};
	point(int x, int y, int z, int ww): u(x), v(y), next(z), flow(ww){};

}
p[M];
char map[104][104];
int dirx[104][104], diry[104][104];
void add(int x, int y , int z){
	p[no] = point(x, y, head[x], z);	head[x] = no++;
	p[no] = point(y, x, head[y], 0);	head[y] = no++;
}

void init(void){
	memset(head, -1, sizeof(head));
	memset(dirx, -1, sizeof(dirx));
	memset(diry, -1, sizeof(diry));
	no = 0;
}

bool bfs(void){
	int i, x, y;
	queue<int>q;
	memset(d, -1, sizeof(d));
	d[s] = 0;	q.push(s);

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
	int x = s, top, i, maxflow = 0, nowflow, loc;
	while(bfs()){
		for(i = s; i <= e; i++) cur[i] = head[i];
		top = 0;
		while(true){
			if(x == e){
				nowflow = INF;
				for(i = 0; i < top; i++){
					if(p[st[i]].flow < nowflow) {
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
				//x = p[st[--top]].v;
				st[top++] = i;
				x = p[i].v;
			}
			else{
				if(!top) break;
				d[x] = -1;
				x = p[st[--top]].u;
			}
		}
	}
	return maxflow;
}



int main(){
	int n, i, j, ans;
	while(scanf("%d", &n) != EOF){
		for( i = 1; i <= n; i++){
			scanf("%s", map[i] + 1);
		}
		init();
		int numx = 0, numy = 0;
		for(i = 1; i <= n; i++){
			for(j = 1; j <= n; j++){
				if(map[i][j] == 'X') continue;
				if(map[i][j-1] == '.') dirx[i][j] = numx;
				else dirx[i][j] = ++numx;
			}
		}

		for(j = 1; j <= n; j++){
			for(i = 1; i <= n; i++){
				if(map[i][j] == 'X') continue;

				if(map[i-1][j] == '.') diry[i][j] = numy;
				else diry[i][j] = ++numy;
			}
		}
		s = 0;	e = numx + numy + 1;

		for(i = 1; i <= numx; i++)	add(s, i, 1);
		for(i = 1; i <= numy; i++)	add(i + numx, e, 1);
	//	printf("%d %d\n", numx, numy);
		for(i =1; i <= n; i++){
			for(j =1; j <= n; j++){
				if(map[i][j] == '.')
					add(dirx[i][j], diry[i][j] + numx, 1);
			}
		}

		printf("%d\n", dinic());
	}
	return 0;
}




