#include <cstdio>
#include<cstring>
#include <algorithm>
using namespace std;

const int N  = 202;
const int M = 505;

int sg[N][N];


int dfs(int x, int y){
    if(sg[x][y] != -1)return sg[x][y];
    int i, j;
    bool hash[M];   memset(hash, 0, sizeof(hash));
    int  m = x / 2;
    for(i = 2; i <= m; i++){
        hash[dfs(i, y) ^ dfs(x-i, y)] = true;
    }
    m = y / 2;
    for(i = 2; i <= m; i++){
        hash[dfs(x, i)^dfs(x, y-i)] = true;
    }
    i = 0;
    while(hash[i]) i++;
    return sg[x][y] = i;


}
int main(){
    int n, m , i, j;
    memset(sg, -1, sizeof(sg));
    while(scanf("%d%d", &n, &m) != EOF){
        printf("%s\n", dfs(n, m) ? "WIN":"LOSE");
    }
    return 0;

}
