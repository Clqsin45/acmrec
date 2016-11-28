#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 22;

int f[N], l;

void dfs(int x){
    if(f[x] != -1)  return ;
    bool hash[N];
    memset(hash, false, sizeof(hash));
    int i;
    for(i = 1; i <= l; i++){
        if(x - i < 0)   break;
        dfs(x-i);   hash[f[x-i]] = true;
    }
    for(i = 0; i <= N; i++){
        if(hash[i]) continue;
        f[x] = i;   break;
    }
    return ;
}
int main(){
    int n, x, i, ans, TC;
    scanf("%d", &TC);
    while(TC--){
        scanf("%d", &n);    ans = 0;
        for(i = 1; i <= n; i++){
            memset(f, -1, sizeof(f));
            scanf("%d%d", &x, &l);
            f[0] = 0;
            dfs(x);
            ans ^= f[x];
        }
        printf("%s\n", ans ? "No": "Yes" );
    }
    return 0;
}
