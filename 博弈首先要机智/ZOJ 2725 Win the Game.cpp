#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 55;
int sg[N];

int dfs(int x){
    if(sg[x] != -1)return sg[x];
    bool hash[N];   memset(hash, 0, sizeof(hash));
    int i;
    for(i = 2; i <= x; i++){
        hash[dfs(i-2) ^ dfs(x-i)]  = true;
    }
    i = 0;
    while(hash[i])  i++;
    return sg[x] = i;
}
int main(){
    int n, m, i, j, ans;
    memset(sg, -1, sizeof(sg));

    while(scanf("%d", &n) != EOF){
        ans = 0;
        while(n--){
            scanf("%d", &m);
            ans ^= dfs(m);
        }
        printf("%s\n", ans ? "Yes" : "No");

    }
    return 0;
}
