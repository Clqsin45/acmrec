#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

#define N 40004
#define M
#define LL __int64
#define INF 0x3f3f3f3f
int dfn[N], head[N], HQ[N], ans[202], dis[N];
int no;
struct point{
    int v, next, cost;
    point(){};
    point(int x, int y, int z):v(x), next(y), cost(z){};
}p[N << 1], q[444];
void init(){
    memset(head, -1, sizeof(head));
    memset(HQ, -1, sizeof(HQ));
    memset(dfn, 0, sizeof(dfn));
    no = 0;
}

int find(int x){
    if(x == dfn[x] ) return x;
    return dfn[x] = find(dfn[x]);
}
void tarjan(int x, int fa){
    int i, j, k, y;
    dfn[x] = x;
    for(i = HQ[x]; i != -1; i = q[i].next){
        y = q[i].v;
        if(!dfn[y])     continue;
        ans[i >> 1] = dis[x] + dis[y] - 2 * dis[find(y)];
     //   printf("dis[%d] =  %d  dis[%d] = %d %d %d %d\n", x, dis[x], y, dis[y], find(y), dis[find(y)], i >> 1);
    }
    for(i = head[x]; i != -1; i = p[i].next){
        y = p[i].v;
        if(y == fa) continue;
        dis[y] = dis[x] + p[i].cost;
        tarjan(y,x );
    }
    dfn[x] = fa;
}
inline int scan_d() {
    char c;
    int ret=0;
    while((c=getchar())<'0'||c>'9');
    while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();
    return ret;
}
int main(void){
    int TC, i, n, m, x, y, z;
    scanf("%d", &TC);
    while(TC--){
        scanf("%d%d", &n, &m);
        init();
        for(i = 1; i < n; i++){
            x = scan_d();   y = scan_d(); z= scan_d();
           // scanf("%d%d%d", &x, &y, &z);
            p[no] = point(y, head[x], z);   head[x] = no++;
            p[no] = point(x, head[y], z);   head[y] = no++;
        }
        no = 0;
        for(i = 0; i < m; i++){
            //scanf("%d%d", &x, &y);
            x = scan_d();   y = scan_d();
            q[no] = point( y, HQ[x], 0); HQ[x] = no++;
            q[no] = point( x, HQ[y], 0); HQ[y] = no++;
        }
        dis[1] = 0;
        tarjan(1, 1);
        for(i = 0; i < m; i++){
            printf("%d\n", ans[i]);
        }
    }
	return 0;
}
