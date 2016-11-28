#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define N 406
#define M 44400
#define INF 1000000000.0
#define eps 1e-9

int head[N], d[N], cur[N], st[M], s, e, no;
struct point{
	int u, v, next;
	double flow;
	point(){};
	point(int x, int y, int z, double w):u(x), v(y), next(z), flow(w){};
}p[M];

void init(){
	memset(head, -1, sizeof(head));
	no = 0;
}
void add(int x, int y, double z){
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
			if(p[i].flow > eps && d[y] < 0){
				d[y] = d[x] + 1;
				if(y == e) return true;
				q.push(y);
			}
		}
	}
	return false;
}

double dinic(){

	int top, i, x = s, loc;
	double maxflow = 0, nowflow;
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
    int TC, n, m, t, x, y, i;
    double cost, temp;
    scanf("%d", &TC);
    while(TC--){
        scanf("%d%d%d", &n, &m, &t);
        init();
        s = 0;  e = n + m + 1;
        for(i = 1; i <= n; i++){
            scanf("%lf", &cost);
            cost = log(cost);
            add(s, i, cost);
        }
        for(i = 1; i <= m; i++){
            scanf("%lf", &cost);
            cost = log(cost);
            add(i + n, e, cost);
        }
        while(t--){
            scanf("%d%d", &x, &y);
            add(x, y + n, INF);
        }
        printf("%.4f\n", exp(dinic()));
    }
    return 0;
}
