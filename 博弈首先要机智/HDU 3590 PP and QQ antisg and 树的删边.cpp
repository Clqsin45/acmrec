#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 105;

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
    int TC, i, n, x, y, ans, cnt;

    while(scanf("%d" , &TC) != EOF){
        ans = cnt = 0;
        while(TC--){
            scanf("%d", &n);    init();
            int m = n - 1;

            while(m--){
                scanf("%d%d", &x, &y);
                add(x, y);

            }
            dfs(1);
          //  printf("!!!%d\n", sg[1]);
            ans ^= sg[1];
            cnt += (sg[1] > 1);
        }
      //  printf("%d %d\n", cnt , ans);

        printf("%s\n", ((ans>0)^ (cnt>0)) ? "QQ" : "PP");

    }
    return 0;
}
