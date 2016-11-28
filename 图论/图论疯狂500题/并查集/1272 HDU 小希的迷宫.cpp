#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 100004
#define M
#define LL __int64
#define INF 0x3f7f7f7f
int f[N], rank[N], vis[N];

void init(){
    int i;
    for(i = 1; i <= 100000; i++){
        f[i] = i;
        rank[i] = 1;
    }
    memset(vis, false, sizeof(vis));
}
int find(int x){
    if(x == f[x])    return x;
    return f[x] = find(f[x]);
}

bool merge(int x, int y){
    x = find(x);    y = find(y);
    if(x == y)  return true;
    if(rank[x] > rank[y]){
        f[y] = f[x];
        rank[x] += rank[y];
    }
    else{
        f[x] = f[y];
        rank[y] += rank[x];
    }
    return false;
}
int main(void)
{
    int i, x, y, cnt, cmd;
    bool flag;
    while(true){
        cnt =cmd = 0;
        scanf("%d%d", &x, &y);

        if(x == 0 && y == 0){
            printf("Yes\n");
            continue;
        }
        if(x == -1 && y == -1)  break;
        init(); flag = true;
        if(!vis[x]){
            vis[x] = true;  cnt++;
        }
        if(!vis[y]){
            vis[y] = true;  cnt++;
        }
        cmd = 1;
        if(merge(x, y))    flag = false;
        while(scanf("%d%d", &x, &y) && (x || y)){
            if(merge(x, y)) flag = false;
            if(!vis[x]){
                vis[x] = true;  cnt++;
            }
            if(!vis[y]){
                vis[y] = true;  cnt++;
            }
            cmd ++;
        }
        if(cmd != cnt - 1)  flag= false;
        printf("%s\n", flag ? "Yes" : "No");
    }
    return 0;
}
