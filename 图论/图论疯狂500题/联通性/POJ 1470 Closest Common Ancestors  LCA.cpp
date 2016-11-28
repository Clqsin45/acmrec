#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
using namespace std;

#define N 1004
#define M 1004

int head[N], dfn[N], in[N];
int HQ[N], ans[N];
struct point{
	int u, v, next;
	point(){};
	point(int x, int y, int z): u(x), v(y), next(z){};
}p[M], Q[1700000];
int  no, n, m;
bool vis[810004];
void init(){
	memset(head, -1, sizeof(head));
	memset(HQ, -1, sizeof(HQ));
	memset(vis, false, sizeof(vis));
	memset(dfn, -1, sizeof(dfn));
	memset(ans, 0, sizeof(ans));
	memset(in, 0, sizeof(in));
	no = 0;
}

void add(int x, int y){
	p[no] = point(x, y, head[x]);	head[x] = no++;
	}

void quireadd(int x, int y){
	Q[no] = point(x, y, HQ[x]);	HQ[x] = no++;
	Q[no] = point(y, x, HQ[y]);	HQ[y] = no++;

}
int find(int x){
	if(x == dfn[x]) return x;
	return dfn[x] = find(dfn[x]);
}
void tarjan(int x, int fa){
	int i, y;
	dfn[x] = x;
//	printf("%d\n",x);
	for(i = head[x]; i != -1; i = p[i].next){
		y = p[i].v;
		if(dfn[y] == -1) tarjan(y, x);
	}
	for(i = HQ[x]; i != -1; i = Q[i].next){
		y = Q[i].v;
		if(vis[i/2])	continue;
		if(dfn[y] != -1){
			vis[i/2] = true;

			ans[find(y)] ++;
		}
	}
	dfn[x] = fa;
}


int main(){
	int i, TC, x, y, temp;
	bool flag ;
	char c;

	while(scanf("%d", &n) != EOF){
		m = n - 1;
		init();
		for(i = 1; i <= n; i++){
			scanf("%d", &x);
			temp = 0;	flag= false;
			while(c = getchar()){
				if(isdigit(c)){
					temp = temp * 10 + c - '0';
					flag = true;
				}
				c = getchar();
				if(flag && !isdigit(c)) break;
			}
			while(temp--){
				scanf("%d", &y);
				add(x, y);
				in[y] ++;
			}
		}

		scanf("%d", &m);	no = 0;
		char ch1[2], ch2[2];
		while(m--){
			scanf("%1s%d%d%1s", ch1, &x, &y, ch2);
			quireadd(x, y);
		}
		for(i = 1; i <= n; i++){
			if(in[i]) continue;
			tarjan(i, i);
			break;
		}
		for(i = 1; i <= n; i++){
			if(ans[i])	printf("%d:%d\n", i, ans[i]);
		}
		//printf("%d\n", ans);
	}
}


