#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1000005;
typedef __int64 ll;

int f[N], s;
void dfs(int x){
    if(f[x] != -1)  return ;

    int i, maxn = (int)max((ll)x*x, (ll)s);
    for(i = 1; i <= maxn; i++){
        if(f[x+i] != -1)
    }
}

int main(){
    int n, tc = 0, x, i, ans, c;
    while(scanf("%d", &n) &&n){
        printf("Case %d: ", ++tc);
        ans = 0;

        for(i = 1; i <= n; i++){
            scanf("%d%d", &s, &c);
            memset(f, -1, sizeof(f));
            f[s] = 0;   dfs(c);
            ans ^= f[c];
        }

    }

}
