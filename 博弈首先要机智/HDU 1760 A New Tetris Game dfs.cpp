#include <cstdio>
#include<cstring>
#include <algorithm>
using namespace std;

const int N = 55;
int f[N][N], sg[N][N], n, m;
int gox[3] = {0, 1, 1}, goy[3] = {1, 0, 1};
bool inmap(int x, int  y){
    return x > 0 && y > 0 && x<= n && y <=m;
}

bool judge(int x, int y){
    int i;
    for(i = 0; i < 3; i++){

        if(inmap(x +gox[i], y + goy[i]) && f[x +gox[i]][y + goy[i]] != 1)    continue;
        return false;
    }
    return true;
}

bool dfs(int x, int y){
    int i, j, k, xx, yy;

    bool flag= false;
    for(i = 1; i < n; i++){
        for(j = 1; j < m; j++){

            if(f[i][j] == 0 && judge(i, j)){//printf("!!!%d %d %d %d\n", x, y, i, j); system("pause");
                f[i][j] = 1;
                for(k = 0; k  < 3; k++) f[i+gox[k]][j+goy[k]] = 1;
                if(!dfs(i, j)) flag = true;
                for(k = 0; k  < 3; k++) f[i+gox[k]][j+goy[k]] = 0;
                f[i][j] = 0;
                if(flag)    return true;
            }
        }
    }

    return false;
}
int main(){
    int  i, j, ans, k;
    while(scanf("%d%d", &n, &m) != EOF){
        for(i = 1; i <= n; i++){
            for(j = 1; j <= m; j++){
                scanf("%1d", &f[i][j]);
            }
        }
        memset(sg, -1, sizeof(sg));
        ans = 0;
        for(i = 1; i < n; i++){
            for(j = 1; j < m; j++){
                if(f[i][j] == 0 && judge(i, j)){
                    f[i][j] = 1;
                    for(k = 0; k  < 3; k++) f[i+gox[k]][j+goy[k]] = 1;
                //    printf("%d %d\n",i, j);
                    if(!dfs(i, j)) ans = true;
                    for(k = 0; k  < 3; k++) f[i+gox[k]][j+goy[k]] = 0;
                    f[i][j] = 0;
                }
            }
        }
        printf("%s\n", ans ? "Yes": "No");
    }
    return 0;
}
