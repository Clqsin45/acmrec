#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int head[N], cnt[N], deep[N];
int dp[N][20];
struct point{
    int v, next;
    point(){};
    point(int x, int y){v = x, next=  y;};
}p[N<<1];
int no, mos = 0;

void add(int x,  int y){
    p[no] = point(y, head[x]);  head[x] = no++;
    p[no] = point(x, head[y]);  head[y] = no++;
}


void init(){
    memset(head, -1, sizeof(head));
    memset(cnt, 0, sizeof(cnt));
    no = 0;
}

void dfs(int x, int fa){
    int i, y;
    deep[x] = deep[fa] + 1; mos = max(mos, deep[x]);
    dp[x][0] = fa;
    cnt[x] = 1;

    for(i = head[x]; i != -1; i = p[i].next){
        y = p[i].v;
        if(y == fa) continue;
        dfs(y, x);
        cnt[x] += cnt[y] ;
    }
}

void gao(int n){
    int i, j;
    for(j = 1; (1 << j ) < mos; j++){
        for(i = 1; i <= n; i++){
            dp[i][j] = dp[dp[i][j-1]][j-1];
         //   printf("%d %d %d\n", i, j, dp[i][j]);
        }
    }
    mos  = j - 1;
}

int find(int x, int y){
    if(deep[x] > deep[y])   swap(x, y);
    int i;
    for(i = mos; i >= 0 ; i--){
        if((deep[y] - deep[x]) >> i & 1) y = dp[y][i];

    }
    if(x == y)  return y;
    for(i = mos; i >= 0 ; i--){
        if(dp[x][i] != dp[y][i]){
            x = dp[x][i];
            y = dp[y][i];
        }
    }
    return dp[x][0];
}

int search(int x, int dis){
    int i;
    for(i = 0; i <= mos; i++){
        if(dis >> i & 1) x = dp[x][i];
    }
    return x;
}
int main(){
    int n, m, i, x, y, z, a, b;
    int temp;
    scanf("%d", &n);
    init();
    for(i = 1; i < n; i++){
        scanf("%d%d", &x, &y);
        add(x, y);
    }
    deep[0] = 0;
    dfs(1, 0);
    gao(n);

    scanf("%d", &m);
    while(m--){
        scanf("%d%d", &x, &y);
        if(x == y){
            printf("%d\n", n);
            continue;
        }
        if(deep[x] < deep[y])   swap(x, y);
        z = find(x, y);
      //  printf("lca :%d\n", z);
        temp = deep[x] +deep[y] - (deep[z]<<1);
        if(temp & 1){
            printf("0\n");
            continue;
        }
        temp >>= 1;
        if(deep[x] == deep[y]){
            a = search(x, temp - 1);
            b = search(y, temp - 1);
            printf("%d\n", n - cnt[a] - cnt[b]);
        }else{
            a = search(x, temp);
            b = search(x, temp - 1);
            //printf("%d %d %d\n", a, b, temp);
            printf("%d\n", cnt[a] - cnt[b]);
        }
    }
    return 0;
}
