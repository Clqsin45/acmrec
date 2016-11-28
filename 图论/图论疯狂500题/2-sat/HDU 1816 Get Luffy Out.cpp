#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 5000
#define M 10000
#define LL __int64
#define INF 0x3f7f7f7f

struct Pair{
    int x, y;
}key[N >> 1], lock[N];

struct point{
    int v, next;
    point(){};
    point(int x, int y):v(x), next(y){};
}p[M];
int head[N], col[N], ans[N];
int no, ct, n, k;


void init(){
    memset(head, -1, sizeof(head));
    memset(col, 0, sizeof(col));
    no = 0;
}

void add(int x, int y){
    p[no] = point(y, head[x]);  head[x] = no++;
}

void build(int mid){
    int i;
    init();
    for(i = 1; i <= k; i++){
        add(key[i].x << 1, key[i].y << 1 | 1);
        add(key[i].y << 1, key[i].x << 1 | 1);
    }
    for(i = 1; i <= mid; i++){
        add(lock[i].x << 1 | 1, lock[i].y << 1);
        add(lock[i].y << 1 | 1, lock[i].x << 1);
    }
}

bool dfs(int x){
    if(col[x] == 1) return true;
    if(col[x] == 2) return false;

    col[x] = 1; col[x ^ 1]  = 2;
    int i, y;
    ans[++ct] = x;
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
            for(j = 1; j <= ct; j++){
                col[ans[j]] = col[ans[j]^1] = 0;
            }
            if(!dfs(i ^ 1)) return false;
        }
    }
    return true;
}

int main(void)
{
    int m, low, high, mid, ans, i, j, x, y;
    while(scanf("%d%d", &k, &m) && (k || m)){
        for(i = 1; i <= k; i++) scanf("%d%d", &key[i].x, &key[i].y);

        for(i =1; i <= m; i++)  scanf("%d%d", &lock[i].x, &lock[i].y);

        low = 0;    high = m;
        n = k * 4;  ans = 0;
        while(low <= high){
            mid = (low + high) >> 1;
            build(mid);
            if(solve()){
                ans = mid;  low = mid + 1;
            }
            else high = mid - 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
