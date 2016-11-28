#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 1004
#define M
#define LL __int64
#define INF 0x3f7f7f7f
int f[N], rank[N];

int find(int x){
    if(x == f[x])   return x;
    f[x] = find(f[x]);
}

bool merge(int x, int y){
    x = find(x);    y = find(y);
    if(x == y)  return false;

    if(rank[x] > rank[y]){
        f[y] = f[x];    rank[x] += rank[y];
    }
    else {
        f[x] = f[y];    rank[y] += rank[x];
    }
    return true;
}
int main(void)
{
    int n, m, ans, i, x, y;
    while(scanf("%d", &n) && n){
        scanf("%d", &m);
        for(i = 1; i <= n; i++) {
            f[i] = i;   rank[i] = 1;
        }
        ans = n - 1;
        while(m--){
            scanf("%d%d", &x, &y);
            ans -= merge(x, y);
        }
        printf("%d\n", ans);
    }

    return 0;
}
