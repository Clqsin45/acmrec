#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;

struct point{
    int u, v, next;
    point(){};
    point(int x, int y, int z){u = x, v = y, next=z;};
}p[N<<1];
int head[N], sg[N];
bool vis[N];
int no;

void init(){
    memset(head, -1, sizeof(head));
    memset(vis, false, sizeof(vis));
    no = 0;
}
void add(int x, int y ){
    p[no] = point(x, y, head[x]);   head[x] = no++;
    p[no] = point(y, x, head[y]);   head[y] = no++;
}

void dfs(int x){
    int val = 0, i, y;
    vis[x] = true;
    for(i  = head[x]; i != -1; i = p[i].next){
        y = p[i].v;
        if(vis[y])continue;
        dfs(y); val ^= (sg[y] +1);
    }
    sg[x] = val;
}

int main(){
    int TC, i, n, x, y, ans;
    scanf("%d", &TC);

    while(TC--){
        scanf("%d", &n);    init();
        int m = n - 1;
        while(m--){
            scanf("%d%d", &x, &y);
            add(x, y);
        }
        dfs(1);
        printf("%s\n", sg[1] ? "Alice" : "Bob" );
    }
    return 0;
}
