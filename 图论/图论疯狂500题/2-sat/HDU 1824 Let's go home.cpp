#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 6005
#define M 32004
#define LL __int64
#define INF 0x3f7f7f7f
int col[N], ans[N], head[N], no, n, ct;
struct point{
    int v, next;
    point(){};
    point(int x, int y):v(x), next(y){};
}p[M];

void init(){
    memset(head, -1, sizeof(head));
    memset(col, 0, sizeof(col));
    no = 0;
}

void add(int x, int y){
    p[no] = point(y, head[x]);  head[x] = no++;
}

bool dfs(int x){
    int i, j, t, y;

    if(col[x] == 1) return true;
    if(col[x] == 2) return false;

    col[x] = 1; col[x ^ 1] = 2;

    ans[++ct] = x;
    for(i = head[x]; i != -1; i = p[i].next){
        y = p[i].v;

        if(!dfs(y))  return false;
    }
    return true;
}

bool solve(){
    int i, j, t;

    for(i = 0 ; i < n; i++){
        if(col[i])  continue;

        ct = 0;
        if(!dfs(i)){
            for(j = 1; j <= ct; j++){
                col[ans[j]] = col[ans[j] ^ 1] = 0;
            }
            if(!dfs(i ^ 1)) return false;
        }
    }
    return true;
}
int main(void)
{
    int team, a, b, c,  m;
    while(scanf("%d%d", &team, &m) != EOF){
        n = 6 * team;
        init();
        while(team--){
            scanf("%d%d%d", &a, &b, &c);
            add(a << 1 | 1, b << 1);
            add(a << 1 | 1, c << 1);

            add(b << 1 | 1, a << 1 );    add(c << 1 | 1, a << 1);

        }

        while(m--){
            scanf("%d%d", &a, &b);
            add(a << 1, b << 1 | 1);    add(b << 1, a << 1 | 1);
        }
    //    printf("!!\n");
        if(solve()) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
