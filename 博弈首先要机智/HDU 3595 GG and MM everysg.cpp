#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1004;
const int INF = 0x3f3f3f3f;
int f[N][N], step[N][N];


void dfs(int x, int y){
    if(f[x][y] != -1)return ;
    if(x == 0 || y == 0){
      //  printf("here %d %d\n", x, y);
        f[x][y] = f[y][x] = 0;
        step[x][y] = step[y][x] = 0;
        return;
    }
    bool hash[N<<1];
    memset(hash, 0, sizeof(hash));
    int i = x, j = y, k, t, far = -INF, close = INF;
    k = 1;
    if(i > j)swap(i, j);
    while(i * k <= j){
        t = j - i * k;

        dfs(i, t);

        hash[f[i][t]]=true;
        if(f[i][t] == 0) far = max(far, step[i][t]);
        close = min(close, step[i][t]);
        k++;
    }
    for(i = 0; ; i++) {
        if(hash[i])continue;
        f[x][y] = f[y][x] = i;  break;
    }
    if(f[x][y] == 0){
        step[x][y] = step[y][x] = close + 1;
    }
    else step[x][y] = step[y][x] =  far + 1;
    return ;
}
int main(){
    int n, m, i, j, p, q, maxn;
    memset(f, -1, sizeof(f));

    while(scanf("%d", &n)!= EOF){
        maxn = 0;
        while(n--){

            scanf("%d%d", &p, &q);
            dfs(p, q);
            maxn = max(step[p][q], maxn);
        }
      //  printf("%d %d")
        printf("%s\n",(maxn & 1) ? "MM":"GG" );
    }
    return 0;

}
