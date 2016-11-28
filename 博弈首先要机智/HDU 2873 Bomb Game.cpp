#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 55;
const int M = 3000;

bool hash[M];
int sg[N][N];
char ch[N][N];
void getsg(int x, int y){
    int i, j;
    memset(hash, 0, sizeof(hash));
    for(i = 1; i < x; i++){
        for(j = 1; j < y; j++){
            hash[sg[i][y]^sg[x][j]] = true;
        }
    }

    for(i = 0; ; i++){
        if(hash[i]) continue;
        sg[x][y] = i;   break;
    }

}
void init(){
    int n, m, i, j;
    for(i = 1; i <= 50; i++){
        sg[1][i] = sg[i][1] = i-1;
    }
    for(i = 2; i <= 50; i++){
        for(j = 2; j <= 50; j++){
            getsg(i, j);
      //      printf("%d %d %d\n", i, j, sg[i][j]);

        }
    }


}
int main(){
    init();

    int n, m, i, j, x, y, ans;
    while(scanf("%d%d", &n, &m) &&( n || m)){
        ans = 0;
        for(i = 1; i <= n; i++){
            scanf("%s", ch[i] + 1);
            for(j = 1; j <= m; j++){
                if(ch[i][j] == '#')  ans ^=sg[i][j];
            }
        }
        //printf("%d\n" ,ans);
        printf("%s\n", ans ? "John" : "Jack");
    }
    return 0;
}
