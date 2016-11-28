/*
ID: someway1
PROG: castle
LANG: C++
*/
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 55;
int n, m;
int gox[4] = {0, -1, 0, 1};
int goy[4] = {-1, 0, 1, 0};
int op[N][N], Size[N*N], vis[N][N];
int id = 0;
struct point{
    int x, y;
    point(){};
    point(int  _x, int _y){
        x = _x; y = _y;
    }
};

bool outmap(int x, int  y){
    return x < 1 || y < 1 || x > n || y > m;
}
void bfs(int x, int y){
    int xx, yy, i;
    queue<struct point>q;
    q.push(point(x , y));
    point a;
    vis[x][y] = ++id;
    Size[id] = 1;
    while(!q.empty()){
        a  = q.front(); q.pop();
        x = a.x;    y = a.y;
        for(i = 0 ;i < 4; i++){
            if(op[x][y] &(1<<i))    continue;
            xx = gox[i] + x;    yy = goy[i] + y;
            if(outmap(xx, yy))continue;
            if(vis[xx][yy])continue;
            vis[xx][yy] = id;
            Size[id] ++;
            q.push(point(xx, yy));
        }
    }
}
int main()
{

//	freopen("castle.in","r",stdin);
//	#ifndef poi
//	freopen("castle.out","w",stdout);
//	#endif

    int i, j, k, x, y;
    while(scanf("%d%d", &n, &m) != EOF){
        memset(vis, 0, sizeof(vis));    id = 0;
        for(i = 1; i <= n; i++){
            for(j = 1; j <= m; j++){
                scanf("%d",&op[i][j]);
            }
        }

        for(i = 1; i <= n; i++){
            for(j = 1; j <= m; j++){
                if(vis[i][j]) continue;
                 bfs(i, j);
            }
        }
        int ans = 0, maxroom = 0, posx, posy, posdir;
        for(i = 1; i <= n; i++){
            for(j = 1; j <= n; j++){
                maxroom = max(maxroom, Size[vis[i][j]]);
                for(k = 0; k < 4; k++){
                    if(op[i][j]&(1<<k)){
                        x = i + gox[k];y = j + goy[k];
                        if(outmap(x, y))    continue;
                        if(vis[i][j] == vis[x][y])continue;
                        int temp = Size[vis[x][y]] + Size[vis[i][j]];
                        if(temp > ans){
                            posx = i;   posy = j;   posdir = k;
                            ans = temp;
                        }
                        else if(temp == ans){
                       //     cout << ans << " " << i << " "<<j <<endl;
                            if(j < posy || (j == posy && i > posx)){
                                posx = i;   posy = j;   posdir = k;
                            }
                        }
                    }
                }
            }
        }
        cout << id <<endl<<maxroom <<endl ;
    //	cout << posx <<" "<<posy <<" ";
    //	switch(posdir){
    //        case 0: cout << "W"<<endl;  break;
    //        case 1: cout << "N"<<endl;  break;
    //        case 2: cout << "E" << endl;    break;
    //        case 3: cout << "S" <<endl; break;
    //	}
    }
	return 0;

}
