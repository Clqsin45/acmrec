#include <cstdio>
#include <cstring>
#include<algorithm>
using namespace std;

const int N  = 1004;
struct point{
    int y, next;
    point(){};
    point(int x, int xx){ y = x, next = xx;};
}p[N*N];
int head[N], sg[N];
int no = 0;
void init(){
    memset(sg, -1, sizeof(sg));
    memset(head, -1, sizeof(head));
    no = 0;
}

void add(int x, int y){
    p[no] = point(y, head[x]);  head[x] = no++;
}

void dfs(int x){
    if(sg[x] != -1) return;
    bool hash[N];
    memset(hash, 0, sizeof(hash));
    int i, y;
    for(i = head[x]; i != -1; i = p[i].next){
        y = p[i].y;
        dfs(y); hash[sg[y]] = true;
    }
    //printf("~~%d %d\n", x, hash[0]);
    i = 0;
    while(hash[i])    i++;
    sg[x] = i;
    return ;
}
int main(){
    int n, m, k , i, x, y, ans;
    while(scanf("%d", &n) != EOF){
        init();
        for(i = 0; i < n; i++){
            scanf("%d", &m);
            while(m--){
                scanf("%d", &x);
                add(i, x);
            }
        }

        while(scanf("%d", &m ) && m){
            ans = 0;
            while(m--){
                scanf("%d", &x);
                if(sg[x] == -1) dfs(x);
                ans ^= sg[x];
              //  printf("!!%d\n", sg[x]);
            }
            printf("%s\n", ans ? "WIN" :  "LOSE");
        }
    }
    return 0;
}
