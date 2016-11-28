#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

#define T 44
#define N 2004
#define M 16405
#define LL __int64
#define INF 0x3f7f7f7f
int f[T][T];
struct point{
    int u, v, flow, next, cost;
    point(){};
    point(int x, int y, int z, int w, int c):u(x), v(y), next(z), flow(w), cost(c){};
}p[M];
int d[N], head[N], pre[N], vis[N], n, m, no, s, e;

void add(int x, int y, int w, int c){
    p[no] = point(x, y, head[x], w, c);
	head[x] = no++;
    p[no] = point(y, x, head[y], 0, -c);    head[y] = no++;
}

void init(){
	memset(head, -1, sizeof(head));
	no = 0;
}
bool spfa(){
    queue<int>q;
    int i, x, y;
    memset(d, 0x80, sizeof(d));
    memset(vis, 0, sizeof(vis));
    memset(pre, -1, sizeof(pre));
	d[s] = 0;
    q.push(s);  vis[s] = true;
    while(!q.empty()){

		x = q.front();  q.pop();;
       // printf("!!!%d\n", x);
		for(i = head[x]; i != -1; i = p[i].next){
            y = p[i].v;
           // printf("y = %d dy =  %d, dx+pc = %d\n", y, d[y], d[x] + p[i].cost);
		//	getchar();getchar();
			if(p[i].flow && d[y] < d[x] + p[i].cost){
                d[y] = d[x] + p[i].cost;
                pre[y] = i;
                if(vis[y])    continue;
                vis[y] = true;
                q.push(y);
            }
        }
		vis[x] = 0;
    }
    return d[e] != d[e + 1];
}
int mcmf(){
    int i, minflow, maxlow = 0, maxcost = 0;

    while(spfa()){
        minflow = INF;
		//printf("~!%d\n", maxcost); //getchar();getchar();
        for(i = pre[e]; i != -1; i = pre[p[i].u]){
          //  if(i == pre[e]) continue;
			minflow = min(minflow, p[i].flow);
        }
	//	printf("%d\n", minflow);
        for(i = pre[e]; i != -1; i = pre[p[i].u]){
            p[i].flow -= minflow;
            p[i^1].flow += minflow;
        }
        maxcost += d[e] * minflow;
    }
    return maxcost;
}
int main(void)
{
	//freopen("in", "r", stdin);
    int i, j, ans, x, y;
    //printf("@@@\n");
    while(scanf("%d", &n) != EOF){
        init();
		for(i = 1; i <= n; i++){
            for(j = 1; j <= n; j++){
                scanf("%d", &f[i][j]);
				x =  (i - 1)*n+j;
				x = x * 2 - 1;	y = x + 1;
				add(x, y, 1, f[i][j]);
				x =i * n + j;	x = 2 * x - 1;
				if(i < n){
					add(y, x, 1, 0);
				}
				if(j < n){
					x = (i - 1) * n + j + 1;	x = 2 * x -1;
					add(y, x, 1, 0);
				}
			}
		}



		// printf("!!!\n");

		s = 0;  e = n * 2 * n;

	//	printf("%d~~~\n", f[1][1]);
		add(s, 1, 2, 0); add(e - 1, e, 1, 0);
        add(1, 2, 1, 0);
		printf("%d\n", mcmf());
    }
    return 0;
}
