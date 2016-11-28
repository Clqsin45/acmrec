#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2004;

int sg[N];

int dfs(int x){
    if(x < 0)return 0;

    if(sg[x] != -1) return sg[x];

    bool hash[N];
    memset(hash, 0, sizeof(hash));
    int i;
    for(i = 1; i <= x; i++){
        hash[dfs(i-3)^dfs(x-i-2)] = true;
    }
    i = 0;
    while(hash[i])  i++;
    return sg[x] = i;

}

int main(){
    int n, m, i, ans;
    memset(sg, -1, sizeof(sg));
    sg[0] = 0;
    sg[1] = sg[2] = sg[3] = 1;
    while(scanf("%d", &n) != EOF){
        printf("%d\n", dfs(n) ? 1 : 2);
    }
    return 0;

}
