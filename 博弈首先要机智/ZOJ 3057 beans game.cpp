#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 303;

bool gg[N][N][N];

void modify(int x, int y, int z){
    int i, j, k, m;
    m = 300 - x;
    for(i = 1; i <= m; i++){
        gg[i+x][y][z] = 1;
    }
    m = 300- y;
    for(i = 1; i <= m; i++){
        gg[x][i+y][z] = 1;
    }
    m = 300 - z;
    for(i = 1; i <= m; i++){
        gg[x][y][z+i] = 1;
    }
    m = min(300-x, 300-y);
    for(i = 1; i <= m; i++){
        gg[i+x][y+i][z] = 1;
    }
    m= min(300-x, 300-z);
    for(i = 1; i <= m; i++){
        gg[i+x][y][z+i] = 1;
    }
    m = min(300-y, 300-z);
    for(i = 1; i <= m; i++){
        gg[x][y+i][z+i] = 1;
    }
}
void gao(){
    int x, y, z, i, j, k;

    for(i = 0; i <= 300; i++){
        for(j = 0; j <= 300; j++){
            for(k = 0; k <= 300; k++){
                if(gg[i][j][k])continue;
                modify(i, j, k);
            }
        }
    }

}
int main(){
    int a, b, c;
    gao();
    while(scanf("%d%d%d", &a, &b, &c) != EOF){
        printf("%d\n", gg[a][b][c] ? 1 : 0);
    }
    return 0;

}
