#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int N = 200004;

int fa[N], dis[N];
int find(int x){
    if(x == fa[x])  return x;
    else{
        int y = fa[x];
        fa[x] = find(y);
        dis[x] += dis[y];
        return fa[x];
    }
}
void comb(int x, int  y){
    fa[x] = y;  dis[x] += abs(x-y)%1000;
}

int ask(int x){
    find(x);
    return dis[x];
}

int main(){
    int TC,i, x, y, n;
    char op[4];
    scanf("%d", &TC);
    while(TC--){
        scanf("%d", &n);
        for(i = 1; i <= n; i++) {
            fa[i] = i;
            dis[i] = 0;
        }
        while(scanf("%s", op)&&op[0] != 'O'){
            if(op[0] == 'E'){
                scanf("%d", &x);
                printf("%d\n", ask(x));
            }
            else {
                scanf("%d%d", &x, &y);
                comb(x, y);
            }
        }
    }
    return 0;
}
