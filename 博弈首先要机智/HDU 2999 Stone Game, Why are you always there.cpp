#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N  = 104;
const int M = 1004;

int f[1004], s[N], n;

void dfs(int x){
    if(f[x] != -1)return;

    bool hash[M];   memset(hash, false, sizeof(hash));
    int i , j;
    for(i = 1; i <= n; i++) {
        if(s[i] > x)   break;
        for(j = 1; j <= x; j++){
            if(s[i] + j > x + 1)    break;
            dfs(j-1);   dfs((x-s[i]-j+1));
            //printf("%d %d %d\n", j - 1, x - s[i] - j + 1);
            hash[f[j-1]^f[x-s[i]- j + 1]] = true;
        }
    }
//printf("!!!%d\n", hash[0]);
    for(i = 0; ; i++){
        if(hash[i])continue;
        f[x] = i;
        break;
    }
}
inline int scan_d() {
    char c;
    int ret=0;
    while((c=getchar())<'0'||c>'9');
    while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();
    return ret;
}
int main(){
    int m, i, j, x, ans;
    while(scanf("%d", &n) != EOF){
        memset(f, -1, sizeof(f));
        f[0] = 0;
        for(i = 1; i <= n; i++) {
            s[i] = scan_d();
        }
        sort(s + 1, s  + n + 1);
        n = unique(s + 1, s + n + 1) - s - 1;
     //   printf("!!%d\n", n);
        //scanf("%d", &m);
        m = scan_d();
        while(m--){
            x = scan_d();
            dfs(x);
         //   printf("%d\n", f[x]);
            printf("%d\n", f[x] ? 1 : 2);
        }
    }
    return 0;
}
