#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N  20004
#define M  50005
#define LL __int64
#define INF 0x3f7f7f7f
int head[N], belong[N], dfn[N], low[N], in[N], out[N], st[N];
bool vis[N];
int no, num, id, top;

struct point{
    int v, next;
    point(){};
    point(int x, int y):v(x), next(y){};
}p[M], r[M];

void init(){
    no = id = num = top = 0;
    memset(head,  -1, sizeof(head));
    memset(dfn, -1, sizeof(dfn));
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
}
void add(int x, int y){
    p[no] = point(y, head[x]);  head[x] = no++;
}
void tarjan(int x){
    int i, y;
    dfn[x] = low[x] = ++num;

    vis[x] = true;  st[top ++] = x;

    for(i = head[x]; i != -1; i = p[i].next){
        y = p[i].v;

        if(dfn[y] == -1){
            tarjan(y);
            low[x] = min(low[x], low[y]);
        }
        else if(vis[y]){
            low[x] = min(low[x], dfn[y]);
        }
    }

    if(low[x] == dfn[x]){
        id++;
        do{
            y = st[--top];
            vis[y] = false;
            belong[y] = id;
        }while(st[top] != x);
    }
}
inline int scan_d() {
	char c;
	int ret=0;
	while((c=getchar())<'0'||c>'9');
	while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();
	return ret;
}

int main(void)
{
    int TC, n, m, i, x, y, cntin, cntout;
    while(scanf("%d%d", &n, &m) != EOF){
        init();
        cntin = cntout = 0;
        for(i = 1; i <= m; i++){
            x = scan_d();   y = scan_d();
            add(x, y);  r[i] = point(x,  y);
        }

        for(i = 1; i <= n; i++){
            if(dfn[i] == -1)    tarjan(i);
        }
        if(id == 1){
            printf("0\n");
            continue;
        }
        for(i = 1; i <= m; i++){
            x = belong[r[i].v]; y = belong[r[i].next];
            if(x == y) continue;
            in[y] ++;   out[x] ++;
          //  printf("%d %d %d %d\n", x, y, in[x], in[y]);
        }
       // printf("%d\n", id);
        for(i = 1; i <= id; i++){
            if(in[i] == 0)  cntin++;
            if(out[i] == 0) cntout ++;
        }
        printf("%d\n", max(cntin, cntout));

    }
    return 0;
}
