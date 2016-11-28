#include <bits/stdc++.h>
using namespace std;

const int N = 2003;
int d[N][N];
char ch[N][N];
int gox[4] = {0, 0, -1, 1}, goy[4] = {1, -1, 0, 0};
char f[4][2] = {'>','<','<','>','^','v','v','^'};
struct point{
    int x, y;
    point(){};
    point(int xx, int yy){x = xx, y = yy;};
};
queue<struct point>q;
int n, m;

bool inmap(int x, int y){
    return x >= 0 && x <n && y >= 0 && y <m;
}

void add(int x, int y){
    int xx, yy, i;
    for(i = 0; i < 4;i ++){
        xx = x +gox[i]; yy = y +goy[i];
        if(inmap(xx, yy) && ch[xx][yy] =='.') d[x][y] ++;
    }
}

void getd(){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(ch[i][j] == '.') {
                add(i, j);
                if(d[i][j] == 1)
                    q.push(point(i, j));
            }
        }
    }
}

void del(int x, int y){
    int xx, yy, i;
   // if(x == 3 &&y == 1) printf("!!!!!!!!!!!!\n");
    for(i = 0; i < 4;i ++){
        xx = x +gox[i]; yy = y +goy[i];
        if(inmap[xx][yy] && ch[xx][yy] =='.') d[xx][yy]--;
        if(d[xx][yy] == 1)  q.push(point(xx, yy));
    }
}

int bfs(){
    point a, b;
    int i, x, y, cnt = 0;
    while(!q.empty()){
        a = q.front();  q.pop();
        if(ch[a.x][a.y] != '.')continue;
        //printf("%d %d\n", a.x, a.y);
        for(i = 0; i < 4; i++){
            x = a.x +gox[i];
            y = a.y + goy[i];
            if(inmap(x, y) && ch[x][y] == '.'){
            //    printf("%d %d %d\n", x, y , i);
                ch[a.x][a.y] = f[i][1];
                ch[x][y] = f[i][0];
               // printf("!!%d %d %c\n", a.x, a.y, ch[0][0]);
                cnt += 2;
                del(a.x, a.y);
                del(x, y);
             //   printf("%d\n", d[2][1]);
                break;
            }
        }
    }
    return cnt;
}

int main(){
    int i, j, cnt = 0, get = 0;
    memset(d, 0, sizeof(d));
    cin >> n >> m;
    for(i = 0; i < n; i++)  {
        cin>>ch[i];
        for(j = 0; j < m; j++){
            cnt+= (ch[i][j]=='.');
        }
    }

    getd();
//    for(i = 0; i < n; i++){
//        for(j = 0; j < m; j++){
//            printf("%d ", d[i][j]);
//        }
//        printf("\n");
//    }
   // printf("%d %d\n", cnt, bfs());
    if(bfs() == cnt){
        for(i = 0; i < n; i++)cout<<ch[i]<<endl;
    }
    else
        printf("Not unique\n");
    return 0;
}
