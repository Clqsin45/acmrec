#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 1004
#define M
#define LL __int64
#define INF 0x3f7f7f7f

int f[N], rank[N], vis[N], ans;

void init(int n){
    int i;
    for(i = 1; i <= n; i++){
        f[i] = i;   rank[i] = 1;
    }
    memset(vis, 0, sizeof(vis));
}

int find(int x){
    if(x == f[x])   return x;
    return f[x] = find(f[x]);
}
void merge(int x, int y){
    x = find(x);    y = find(y);
    if(x == y)  return;
    ans --;
    if(rank[x] > rank[y])   {
        f[y] = f[x];
        rank[x] += rank[y];
    }
    else {
        f[x] = f[y];
        rank[y] += rank[x];
    }
}
int main(void)
{
    int TC, n, m, i, x, y;

    scanf("%d", &TC);
    while(TC--){
        scanf("%d%d", &n, &m);
        init(n);    ans = n;
        while(m--){
            scanf("%d%d", &x, &y);
            merge(x, y);
        }
        printf("%d\n", ans);
    }
    return 0;
}
