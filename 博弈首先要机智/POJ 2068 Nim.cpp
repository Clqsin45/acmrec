#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N  = 22;
const int M = 10004;

int sg[N][M], num[N], ct;


int dfs(int n, int m){
    if(sg[n][m] != -1 ) return sg[n][m];
    if(m == 0)  return sg[n][m] = 1;
    sg[n][m] = 0;
    int i;
    for(i = 1; i <= num[n] && i <= m; i++){
        if(!dfs(n%ct+1, m - i) )    {
            sg[n][m] = 1;   break;
        }
    }
    return sg[n][m];
}
int main(){
    int n, m , s, i, x, y;
    while(scanf("%d", &n) && n){
        scanf("%d", &s);
        ct = 2 * n;
        memset(sg, -1, sizeof(sg));
        for(i = 1; i <= 2 * n; i++){
            scanf("%d", &num[i]);
        }
        printf("%d\n", dfs(1, s) ? 1 : 0);
    }
}
