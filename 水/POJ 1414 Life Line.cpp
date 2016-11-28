#include <cstdio>
#include <cstring>
#include <algorithm>
#include<queue>
using namespace std;

const int N = 14;
struct point{
    int x, y ;
    point(){};
    point(int xx, int yy){x = xx, y = yy;};
};
int n;

int typ[N][N], gox[6] = {0, 0, -1, -1, 1, 1}, goy[6] = {-1, 1, -1, 0, 0, 1};
bool vis[N][N];

bool outmap(int i, int j){
    return i < 1 || j < 1|| i > n || j > i;
}
void bfs(int x, int y ){
    int tp = typ[x][y];
    queue<struct point>Q;
    Q.push(point(x, y));
    point u, v;
    vis[x][y] = true;
    while(!Q.empty()){
        u = Q.front();  Q.pop();
        x = u.x;    y =u.y;
        for(int i = 0; i < 6; i++){
            int xx = x +gox[i], yy = y +goy[i];
            if(outmap(xx, yy) || vis[xx][yy])  continue;
            if(typ[xx][yy] == tp){
                Q.push(point(xx, yy));
                vis[xx][yy] = true;
            }
        }
    }
}

int gao(int tp){
    //printf("~~~~~~~~~~~~~~%d\n", tp);
    int i, j, k, x, y;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= i; j++){
            if(typ[i][j] == 0){
               // printf("??%d %d\n", i, j);
                for(k = 0; k < 6; k++){
                    x=  i+gox[k], y =  j+goy[k];
                    if(outmap(x, y)) continue;

                    if(typ[x][y] != 0 && !vis[x][y]){
                        bfs(i+gox[k], j+goy[k]);
                    }
                }
            }
        }
    }

    int temp = 0;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= i; j++){
            if(typ[i][j] == 0)  continue;
            if(vis[i][j])   continue;
           // printf("%d %d\n", i, j);
            temp += (typ[i][j] == tp ? -1 : 1);
        }
    }
    return temp;
}
int main(){
    int  m, i, j;
    while(scanf("%d%d", &n, &m) &&(n||m)){
        for(i = 1; i <=n; i++){
            for(j = 1; j <= i; j++){
                scanf("%d", &typ[i][j]);
            }
        }
        int ans = -0x3f3f3f3f;
        for(i = 1; i <=n;i ++){
            for(j = 1; j <=i; j++){
                if(typ[i][j] == 0) {
                    memset(vis, false, sizeof(vis));
                    typ[i][j] = m;

                    ans = max(ans, gao(m));
                    typ[i][j] = 0;
                   //printf("~~~~%d %d %d\n", i, j, ans);
                }
            }
        }
        printf("%d\n", ans);
    }

}
