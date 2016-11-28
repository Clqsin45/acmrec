#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 104;
const int M = 10004;
int n;
int s[N];
int f[M];

void dfs(int x){
    if(f[x] != -1)return;

    bool hash[N];
    memset(hash, false, sizeof(hash));

    int i;
    for(i = 1; i <= n; i++){
        if(x-s[i] < 0)  break;
        dfs(x-s[i]);
        hash[f[x-s[i]]] = true;
    }
    for(i = 0; i < N; i++){
        if(hash[i]) continue;
        f[x] = i;   break;
    }
    return ;
}

int main(){
    int m, i, j, k, T,x, ans;
    while(scanf("%d", &n) && n){
        for(i = 1; i <= n; i++) scanf("%d", &s[i]);
        sort(s + 1, s + n + 1);
        memset(f, -1, sizeof(f));   f[0] = 0;
        scanf("%d", &T);

        for(i = 1; i <= T; i++){
            scanf("%d", &m);
            ans = 0;
            while(m--){
                scanf("%d", &x);
                if(f[x] == -1)  dfs(x);
                ans ^= f[x];
            }
            printf("%c", ans ?  'W' : 'L');
        }

        printf("\n");

    }
    return 0;
}
