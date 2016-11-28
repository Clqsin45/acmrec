#include <bits/stdc++.h>
using namespace std;

#define N 100005
#define M 200004
#define LL __int64

LL all[N];

struct point{
    int u,v, next, w;
    point(){};
    point(int x, int y, int z, int dis){
        u =x; v = y;
        next = z;   w = dis;
    }
}p[M];
struct Gai{
    int no, w;
}gai[N];
int head[N], son[N], down[N];
bool vis[N];
int no;

void init(){
    memset(head, -1, sizeof(head));
    memset(son, 0, sizeof(son));
    memset(vis,false, sizeof(vis));
    no = 0;
}

void add(int x, int y, int z){
    p[no] = point(x, y, head[x], z);    head[x] = no++;
    p[no] = point(y, x, head[y], z);    head[y] = no++;
}

int getsum(int x, int fa, int fleg){
    int  y, i, j, temp = 0;

    for(i = head[x]; i != -1; i = p[i].next){
        if(vis[i/2])continue;
        vis[i/2] = true;
        y = p[i].v;
        down[i/2] = getsum(y, x, i / 2);
      ///  if(i/2==4) printf("%d %d\n", y, down[i/2]);
        temp += down[i/2];
    }
    son[x] = temp;
    return temp + 1;
}
int main(void){
    int n, i, j, x, y, z, m;
    scanf("%d", &n);
    init();
    for(i = 1; i < n; i++){
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
    }
    getsum(1, -1, n);

   // for(i = 0; i < n -1; i ++)  printf("%d %d\n", i, down[i]);
    LL ans = 0LL;
    for(i = 0; i < n - 1; i++){
        ans += (LL)p[i<<1].w*down[i]*(n-down[i]);
      //  printf("%d %I64d %d\n", i, ans, p[i<<1].w);
    }
    int Q;

    scanf("%d", &Q);
    while(Q--){
        scanf("%d%d", &i, &m);
        i--;
        ans -= (LL)(p[i<<1].w-m)*down[i]*(n-down[i]);
        p[i<<1].w = p[i<<1|1].w = m;
        printf("%.10f\n", 1.0 * ans / n / (n-1) *6);
    }
}

