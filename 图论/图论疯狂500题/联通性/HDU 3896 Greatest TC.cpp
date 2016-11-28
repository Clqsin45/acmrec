#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

#define N 100004
#define M 1000004
#define LL __int64
#define INF 0x3f3f3f3f
int low[N], dfn[N], leave[N], deep[N], head[N];
int no, num;
int f[20][N];
bool vis[M];
struct point{
    int u, v, next;
    point(){};
    point(int x, int y, int z):u(x), v(y), next(z){};
}p[M];

void init(){
    memset(head, -1, sizeof(head));
    memset(dfn, -1, sizeof(dfn));
    memset(f, -1, sizeof(f));
    num = no = 0;
}

void add(int x, int y){
    p[no] = point(x, y, head[x]);   head[x] = no++;
    p[no] = point(y, x, head[y]);   head[y] = no++;
}
void tarjan(int x, int fa, int dth){
   // printf("%d\n", x);
    dfn[x] = low[x] = ++num;
    deep[x] = dth;
    int i, y;
    for(i = head[x]; i != -1; i = p[i].next){
        y = p[i].v;
        if(y == fa || vis[i >> 1]) continue;
        if(dfn[y] == -1){
            f[1][y] = x;
            vis[i >> 1] = true;
            tarjan(y, x, dth + 1);
            low[x] = min(low[x], low[y]);
        }
        else low[x] = min(low[x], dfn[y]);
    }
    leave[x] = num;
}

bool edge(int a, int b, int c, int d){
    if(deep[c] < deep[d])   swap(c, d);
    int ina = 0, inb = 0;
    if(dfn[c] <= dfn[a] &&leave[c] >= leave[a])  ina = 1 ;
    if(dfn[c] <= dfn[b] && leave[c] >= leave[b])  inb = 1;
    if((ina + inb) & 1){
        if(low[c] <= dfn[d])return true;
        return false;
    }
    else return true;
}

int find(int x, int dis){
    int t = x, loc = 1;
    if(dis < 0) return -1;
    for(; dis; dis >>= 1){
        if(dis & 1) t = f[loc][t];
        loc ++;
    }
    return t;
}

bool findpoint(int a, int b, int c){
    int ina = 0, inb = 0;
    int x, y;
    if(dfn[c] <= dfn[a] && leave[c] >= leave[a])  ina = 1 ;
    if(dfn[c] <= dfn[b] && leave[c] >= leave[b])  inb = 1;
    if(ina + inb == 0) return true;
    if(ina && !inb){
        x = find(a, deep[a] - deep[c] - 1);
        if(low[x] < dfn[c]) return true;
    }
    if(inb && !ina){
        x = find(b, deep[b] - deep[c] - 1);
        if(low[x] < dfn[c]) return true;
    }
    x = find(a, deep[a] - deep[c] - 1);
    y = find(b, deep[b] - deep[c] - 1);
    if(x == y) return true;
    if(low[x] < dfn[c] && low[y] < dfn[c])  return true;
    return false;

}


int main(void){
//    freopen("input.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int n, m, i, x, y, j, Q, a, b, c, d, type;
    while(scanf("%d%d", &n, &m) != EOF){
        init();
        for(i = 1; i <= m; i++){
            scanf("%d%d", &x, &y);
            add(x, y);
        }
        for(i = 1; i <= n; i++){
            if(dfn[i] == -1)    tarjan(i, -1, 0);
        }

        for(i = 2; i < 20; i ++)
            for(j = 1; j <= n; j++)
                if(f[i - 1][j] != -1)
                    f[i][j] = f[i - 1][f[i - 1][j]];
        scanf("%d", &Q);
        while(Q--){
            scanf("%d", &type);
            if(type == 1){
                scanf("%d%d%d%d", &a, &b, &c, &d);
                if(edge(a, b, c, d))    printf("yes\n");
                else printf("no\n");
            }
            else {
                scanf("%d%d%d", &a, &b, &c);
                if(findpoint(a, b, c)) printf("yes\n");
                else printf("no\n");
            }
        }
    }
	return 0;
}
