#include <bits/stdc++.h>
using namespace std;

#define N 1004
bool f[N][N];

bool gao(int x, int y){
    int i, j;
    for(i = -1; i <= 1; i+=2){
        for(j = -1; j <= 1; j+= 2){
            if(f[x+i][y+j] && f[x][y+j] && f[x+i][y]) return true;
        }
    }
    return false;
}
int main(void){
    int n, m, i, j, k,x, y;
    int gg = 0;
    cin>>n>>m>>k;
    for(i = 1; i <= k; i++){
        cin>>x>>y;
        f[x][y] = true;
        if(gg)
            continue;
        if(gao(x,y)){
            gg = i;
        }
    }
    cout<<gg<<endl;
}
