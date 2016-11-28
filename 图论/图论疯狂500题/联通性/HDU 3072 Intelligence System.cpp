#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define N 50005
#define M  100005
#define LL __int64
#define INF 0x3f7f7f7f

int head[N],  belong[N], st[N], dfn[N], low[N], in[N], d[N];
bool vis[N];
int num, id, no, top;
vector<int>v;
vector<int>f[104];
struct point{
    int u, v, w,next;
    point(){};
    point(int x, int y, int z, int t): u(x), v(y), next(z), w(t){};
}p[M], go[M];

void init(){
    memset(dfn, -1, sizeof(dfn));
    memset(vis, false, sizeof(vis));
    memset(in, 0, sizeof(in));
    memset(head, -1, sizeof(head));
    top = no = id = top = 0;
}

void add(int x, int y, int w){
    p[no] = point(x, y, head[x], w);   head[x] = no++;
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

void spfa(int s){
    int x, y, i;
    d[s] = 0;
    vis[s] = 0;
    queue<int>q;

    q.push(s);

    while(!q.empty()){
        x = q.front();  q.pop();
        for(i = head[x]; i != -1; i = go[i].next){
            y = go[i].v;
            if(d[y] > go[i].w){
                d[y] = go[i].w;
                if(vis[y])    continue;
                vis[y] = true;  q.push(y);
            }
        }
        vis[x] = false;
    }

}
int main(void)
{
    int n, m, j, i, x, y, cnt, ans, z;
    while(scanf("%d%d", &n, &m) != EOF){
        ans = 0;
        init();

        for(i = 1; i <= m; i++){
            x = scan_d();   y = scan_d();   z = scan_d();
            add(x, y, z);
        }
        v.clear();
        fill(f, f +101, vector <int>());
        for(i = 0; i < n; i++){
            if(dfn[i] == -1)    tarjan(i);
        }
        memset(head, -1, sizeof(head));
        memset(vis, 0, sizeof(vis));
        memset(d, 0x3f, sizeof(d));
        no = 0;
        for(i = 0; i < m; i++){
            x = belong[p[i].u]; y = belong[p[i].v];
         //   printf("%d %d %d %d %d\n",i, p[i].u, p[i].v, x, y);
            if(x == y)  continue;
            in[y] ++;
            go[no] = point(x, y, head[x], p[i].w);   head[x] = no++;
        }
        for(i = 1; i <= id; i++){
            if(in[i] == 0){
                spfa(i);
                break;
            }
        }
        ans = 0;
        for(i = 1; i <= id; i++){
            ans += d[i];
        }
        printf("%d\n", ans);

    }
    return 0;
}
