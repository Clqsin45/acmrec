#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 50005
#define M 100004

int head[N], HQ[N], HF[N], ans[N], dfn[N], up[N], down[N], high[N], low[N];
bool vis[N];
int w[N];
struct point{
	int u, v, next;
	point(){};
	point(int x, int y, int z): u(x), v(y), next(z){};
}p[M], Q[M], F[M];
int no;

void init(){
	memset(head, -1, sizeof(head));
	memset(HQ, -1, sizeof(HQ));
	memset(HF, -1, sizeof(HF));

	memset(vis, false, sizeof(vis));
	memset(dfn, -1, sizeof(dfn));
	memset(up,0,sizeof(up));
	memset(low,0x3f, sizeof(low));
	memset(high, 0, sizeof(high));
	memset(down, 0,sizeof(down));
	memset(ans, 0,sizeof(ans));
	no = 0;

}
void add(int x, int y){
	p[no] = point(x,y,head[x]);	head[x] =no++;
	p[no]=point(y,x,head[y]);	head[y]=no++;
}

void addQ(int x,int y){
	Q[no]=point(x,y,HQ[x]);	HQ[x]=no++;
	Q[no]=point(y,x,HQ[y]);	HQ[y]=no++;
}

void addF(int x, int y){
	F[no]=point(x,y,HF[x]);	HF[x]=no++;

}
void update(int x){
//	printf("in%d\n",x);
	if(x!=dfn[x]){
		update(dfn[x]);

		up[x]=max(up[x],max(up[dfn[x]],high[dfn[x]]-low[x]));
		down[x]=max(down[x],max(down[dfn[x]],high[x]-low[dfn[x]]));
		high[x]=max(high[x], max(w[x],high[dfn[x]]));
		low[x]=min(low[x],min(w[x],low[dfn[x]]));
		dfn[x]=dfn[dfn[x]];
//		printf("%d %d %d %d %d %d\n", x, dfn[x],up[x], down[x], high[x], low[x]);
	}
}


void tarjan(int x,int fa){
	dfn[x] = x;
	low[x]=high[x]=w[x];
//	printf("!!%d\n", x);
	int i, y,u,v;
	for(i=HQ[x]; i!=-1; i=Q[i].next){
		if(vis[i/2]) continue;
		y=Q[i].v;
		if(dfn[y]!=-1){
//			printf("first\n");
			update(y);
			vis[i/2]=true;
			addF(dfn[y],i);
		}
	}

	for(i=head[x];i!=-1;i=p[i].next){
		y=p[i].v;
		if(dfn[y]==-1){
			tarjan(y,x);
			dfn[y]=x;
		}
	}

	for(i=HF[x];i!=-1;i=F[i].next){
//		printf("second\n");
		y=F[i].v;
		u=Q[y].u;
		v=Q[y].v;
		update(u);
		update(v);
//	printf("%d %d %d %d %d %d\n", u,dfn[u], low[u], high[u],up[u], down[u] );
//		printf("%d %d %d %d %d %d\n", v,dfn[v], low[v], high[v],up[v], down[v] );

		if(y&1)swap(u,v);
		ans[y>>1]=max(up[u],max(down[v],high[v]-low[u]));
	}

}


int main(void){
	int n, i, j, x, y, K;
	while(scanf("%d", &n) != EOF){
		for(i=1; i <= n; i++){
			scanf("%d", &w[i]);
		}
		init();
		for(i=1; i <n;i++){
			scanf("%d%d", &x, &y);
			add(x,y);
		}

		no=0;
		scanf("%d", &K);
		for(i = 0; i < K; i++){
			scanf("%d%d", &x,&y);
			addQ(x,y);
		}
		no = 0;
		tarjan(1,1);

		for(i = 0; i < K; i++){
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}
