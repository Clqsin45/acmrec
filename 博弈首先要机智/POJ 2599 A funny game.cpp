#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N  = 1004;
int head[N];
bool f[N][N], vis[N];
struct point{
    int x, y, next;
    point(){};
    point(int a, int b, int c){ x = a, y = b, next = c;};
}p[N<<1];
int ans , no;

void init(){
    memset(head, -1, sizeof(head));
    memset(vis, false, sizeof(vis));
    memset(f, false, sizeof(f));
    no = 0;
}

void add(int x, int y){
    p[no] = point(x, y, head[x]);   head[x] = no++;
}

int dfs(int x){
    int i, y;  vis[x] = true;
    for(i = head[x]; i != -1; i= p[i].next){
        if(vis[y = p[i].y]) continue;
        if(!dfs(y)){
            ans = y;    return true;
        }
    }
    return false;
}

int main(){
    int n, k, i, j, x, y;
    while(scanf("%d%d", &n, &k) != EOF){
        init();
        for(i = 1; i < n; i++){
            scanf("%d%d", &x, &y);
            f[x][y] = f[y][x] = true;
        }
        for(i = 1; i <= n; i++){
            for(j = n; j >= 1; j--){
                if(f[i][j])add(i, j);
            }
        }

        if(dfs(k)){
            printf("First player wins flying to airport %d\n", ans);
        }
        else printf("First player loses\n");
    }
}
