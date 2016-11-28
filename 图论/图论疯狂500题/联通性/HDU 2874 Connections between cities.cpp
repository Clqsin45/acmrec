#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

#define N 10002
#define M 1000002
#define LL long long
#define INF 0x3f3f3f3f
int dfn[N], ans[M], head[N], HQ[N], dis[N], no;
bool vis[N];
struct point{
    int v, next, cost;
    point(){};
    point(int x, int y, int z):v(x), next(y), cost(z){};
}p[N << 1];
struct edge{
    int v, next;
    edge(){};
    edge(int x, int y): v(x), next(y){};
}Q[M << 1];

inline int scan_d() {
    char c;
    int ret=0;
    while((c=getchar())<'0'||c>'9');
    while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();
    return ret;
}

void init(){
    memset(head, -1,sizeof(head));
    memset(HQ, -1, sizeof(HQ));
    memset(dfn, 0, sizeof(dfn));
    memset(ans, -1, sizeof(ans));
	no = 0;
}
int find(int x){
	if(x == dfn[x])	return x;
	return dfn[x] = find(dfn[x]);
}
void tarjan(int x, int fa){
	dfn[x] = x;	vis[x] = true;
    int i, y;
    for(i = HQ[x]; i != -1; i = Q[i].next){
        y = Q[i].v;
        if(vis[y]){
            ans[i >> 1] = dis[x] + dis[y] - 2 * dis[find(y)];
        }
    }
    for(i = head[x]; i != -1; i = p[i].next){
        y = p[i].v;
        if(y == fa) continue;
        dis[y] = dis[x] + p[i].cost;
		tarjan(y, x);
        dfn[y] = x;
    }
}


int main(void){
    int n, m, i, x, y, z, c;
    while(scanf("%d%d%d", &n, &m, &c) != EOF){
          init();
          while(m -- ){
              x = scan_d();   y = scan_d(); z= scan_d();
              p[no] = point(y, head[x], z); head[x] = no++;
              p[no] = point(x, head[y], z); head[y] = no++;
          }
          no = 0;
          for(i = 0; i < c; i++){
              x = scan_d();   y = scan_d();
              Q[no] = edge(y, HQ[x]);   HQ[x] = no++;
              Q[no] = edge(x, HQ[y]);   HQ[y] = no++;
          }
          for(i = 1; i <= n; i++){
              if(dfn[i] )   continue;
			  memset(vis, false, sizeof(vis));
			  dis[i] = 0;
              tarjan(i, -1);
          }
          for(i = 0; i < c; i++){
              if(ans[i] == -1) printf("Not connected\n");
              else printf("%d\n", ans[i]);
          }
    }
	return 0;
}
