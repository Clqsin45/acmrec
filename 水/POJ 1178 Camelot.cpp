#include <cstdio>
#include<cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define N  10
#define INF 0x3f3f3f3f

int goxking[N] = {0, 0, 0, -1, 1, -1, -1, 1, 1};
int goyking[N] = {0, -1, 1, 0, 0, -1, 1, -1, 1};
int goxknight[N] = {-1, -1, 1, 1, -2, -2, 2, 2};
int goyknight[N] = {-2, 2, -2, 2, -1, 1, -1, 1};

int d[N][N][N][N];

struct point{
    int x, y;
    point(){};
    point(int xx, int yy) : x(xx), y(yy){};

    point go(int i){
        return point(x + goxknight[i], y + goyknight[i]);
    }
};

vector<struct point> knight;
struct point start;

char op[222];
bool inmap(int x, int y ){
    return x >= 1 && x <= 8 &&y >= 1 && y <= 8;
}
void bfs(int x, int y){
    queue<struct point> Q;
    point u, v;
    u = point(x, y);
    memset(d[x][y], -1, sizeof(int)*100);
    d[x][y][x][y] = 0;
    Q.push(u);
    while(!Q.empty()){
        u = Q.front();  Q.pop();
        for(int i = 0; i < 8; i++){
            v = u.go(i);
            if(inmap(v.x, v.y) &&  d[x][y][v.x][v.y] < 0) {
                d[x][y][v.x][v.y] = d[x][y][u.x][u.y] + 1;
                Q.push(v);
            }
        }
    }
    return;
}

int main(){
   //freopen("out.txt", "w", stdout);
    scanf("%s", op);
    int i, j, k,  x, y, n = strlen(op);
    for(i = 0; i < n; i+= 2){
        x = op[i] - 'A' + 1;
        y = op[i + 1] - '0';
        if(i == 0)  start = point(x, y);
        else knight.push_back(point (x, y));
    }
    for(i = 1;i <= 8; i++){
        for(j = 1;j  <= 8; j++){
            bfs(i, j);
        }
    }

    int m = knight.size();
    int temp, ans = INF;
    for(i = 0; i <= 8; i++){
        x = start.x + goxking[i];
        y = start.y + goyking[i];
      //  printf("%d   %d\n", x, y);
        if(!inmap(x, y))    continue;

        for(j = 0; j < m; j++){
            for(int xx = 1; xx <= 8; xx++){
                for(int yy = 1; yy <= 8; yy++){
                  //  if(xx != 3 || yy != 4  || i != 3)    continue;
                    temp = d[x][y][knight[j].x][knight[j].y];
                 //   printf("%d %d %d\n", x, y, temp);
                    for(k = 0; k < m; k++){ temp += d[xx][yy][knight[k].x][knight[k].y];}
                    temp += d[xx][yy][x][y];    temp -= d[xx][yy][knight[j].x][knight[j].y];
                  //  printf("!%d %d\n", temp, ans);
                    ans = min(temp +(i > 0), ans);
                    //printf("%d %d\n", temp, ans);
                }

            }
        }

    }
    printf("%d\n", ans);
}

