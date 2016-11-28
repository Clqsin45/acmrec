#include <cstdio>
#include <cstring>
#include<vector>
#include <algorithm>
using namespace std;

const int N = 1005;

struct point{
    int u, v, next;
    point(){};
    point(int x, int y, int z){u = x, v = y, next=z;};
}p[N<<1];
int head[N], sg[N];
bool vis[N];
vector<int>root;
int no;

void init(){
    memset(head, -1, sizeof(head));
    memset(vis, false, sizeof(vis));
    no = 0;
}
void add(int x, int y ){
    p[no] = point(x, y, head[x]);   head[x] = no++;
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
    while(scanf("%d", &n) != EOF){
        init();
        root.clear();
        int m = n - 1;
        for(i = 0; i <  n; i++){
            scanf("%d", &x);
            if(x == -1){
                root.push_back(i);
            }
            else add(x, i);
        }
        ans = 0;
        for(i = 0; i < root.size(); i++){
            dfs(root[i]);   ans ^= sg[root[i]];
        }
        printf("%s\n", ans  ? "YES" : "NO" );
    }
    return 0;
}
