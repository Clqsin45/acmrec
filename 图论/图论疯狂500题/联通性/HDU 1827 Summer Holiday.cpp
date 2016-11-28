#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define N 1004
#define M 2004
#define LL __int64
#define INF 0x3f7f7f7f

int head[N],  belong[N], st[N], dfn[N], low[N], in[N], w[N];
bool vis[N];
int num, id, no, top;
vector<int>v;
vector<int>f[N];
struct point{
    int u, v, next;
    point(){};
    point(int x, int y, int z): u(x), v(y), next(z){};
}p[M];

void init(){
    memset(dfn, -1, sizeof(dfn));
    memset(vis, false, sizeof(vis));
    memset(in, 0, sizeof(in));
    memset(head, -1, sizeof(head));
    top = no = id = top = 0;
}

void add(int x, int y){
    p[no] = point(x, y, head[x]);   head[x] = no++;
}
inline int scan_d() {
	char c;
	int ret=0;
	while((c=getchar())<'0'||c>'9');
	while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();
	return ret;
}

void tarjan(int x){
    low[x] = dfn[x] = ++num;
    vis[x] = true;  st[top++] = x;
    int i, y;

    for(i = head[x]; i != -1; i = p[i].next){
        y = p[i].v;//printf("%d\n", y);
        if(dfn[y] == -1){
            tarjan(y);
            low[x] = min(low[x], low[y]);
        }
        else if(vis[y]){
            low[x] = min(low[x], dfn[y]);
        }
    }

    if(dfn[x] == low[x]){
        ++id;
        do{
            y = st[--top];
            vis[y] = false;
            belong[y] = id;
            f[id].push_back(y);

        }while(st[top] != x);
    }
}
int main(void)
{
    int n, m, j, i, x, y, cnt, ans;
    while(scanf("%d%d", &n, &m) != EOF){
        ans = 0;
        init();
        for(i = 1; i <= n; i++) w[i] = scan_d();

        for(i = 1; i <= m; i++){
            x = scan_d();   y = scan_d();
            add(x, y);
        }
        v.clear();
        fill(f, f +n+ 1, vector <int>());
        for(i = 1; i <= n; i++){
            if(dfn[i] == -1)    tarjan(i);
        }

        for(i = 0; i < m; i++){
            x = belong[p[i].u]; y = belong[p[i].v];
         //   printf("%d %d %d %d %d\n",i, p[i].u, p[i].v, x, y);
            if(x == y)  continue;
            in[y] ++;
        }

        for(i = 1; i <= id; i++){
            if(in[i] == 0)  {
                v.push_back(i);
              //  printf("%d ", i);
            }
        }
        n = v.size();

        for(i = 0; i <n; i++){
            cnt = INF;
            m = f[v[i]].size();
            for(j = 0; j < m; j++){
                cnt = min(cnt, w[f[v[i]][j]]);
            }
            ans += cnt;
        }
        printf("%d %d\n", n, ans);

    }
    return 0;
}
