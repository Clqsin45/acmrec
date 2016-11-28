#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define N 2004
#define M 2000004
#define LL __int64
#define INF 0x3f7f7f7f

char a[10], b[10];
int  head[N], col[N], ans[N], ct, n, no;

struct point{
    int v, next;
    point(){};
    point(int x, int y):v(x), next(y){};
}p[M];

void init(){
    memset(head, -1, sizeof(head));
    memset(col,0, sizeof(col));
    no = 0;
}

void add(int x, int y){
    p[no] = point(y, head[x]);  head[x] = no++;
}

bool dfs(int x){
    if(col[x] == 1) return true;
    if(col[x] == 2) return false;

    int i, y;

    ans[++ct] = x;
    col[x] = 1; col[x ^ 1] = 2;

    for(i = head[x]; i != -1; i = p[i].next){
        y = p[i].v;
        if(!dfs(y)) return false;
    }
    return true;
}

bool solve(){
    int i, j;
    for(i = 0; i < n; i++){
        if(col[i])  continue;
        ct = 0;
        if(!dfs(i)){
            for(j = 1; j<= ct; j++){
                col[ans[j]] = col[ans[j] ^ 1] = 0;
            }
            if(!dfs(i ^ 1)) return false;
        }
    }
    return true;
}

int main(void)
{
    int m, i, j, x, y;

    while(scanf("%d%d", &n, &m) != EOF){
        init();
        n <<= 1;
        for(i = 1; i <= m; i++){
            scanf("%s%s", a, b);
            x = atoi( a+ 1);    y = atoi(b + 1);
            x --;   y --;
            if(a[0] == '+' && b[0] == '+'){
                add(x << 1 | 1, y << 1);    add(y << 1 | 1, x << 1);
            }
            else if(a[0] == '-' && b[0] == '-'){
                add(x << 1, y << 1 | 1);    add(y << 1, x << 1 | 1);
            }
            else if(a[0] =='+' && b[0] == '-'){
                add(x << 1 | 1, y << 1 | 1);    add(y << 1, x << 1);
            }
            else{
                add(y << 1 | 1, x << 1 | 1);    add(x << 1, y << 1);
            }
        }
        printf("%d\n", solve());
    }
    return 0;
}
