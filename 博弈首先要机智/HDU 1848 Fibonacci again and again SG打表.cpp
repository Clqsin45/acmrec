#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 44;

const int M =1005;
int f[N], sg[M];
void dfs(int x){
    if(sg[x] != -1) return;
    bool hash[20];
    memset(hash, 0, sizeof(hash));
    int i;
    for(i = 1; i <= 15; i++){
        if(x - f[i] < 0)break;
        dfs(x - f[i]);
        hash[sg[x-f[i]]] = true;
    }
    for(i = 0; i <= 16; i++){
        if(hash[i])continue;
        sg[x] = i;  break;
    }
}

void init(){
    int i;
    f[1] = 1;   f[2] = 2;
    for(i = 3; i <= 15; i++){
        f[i] = f[i-1] + f[i-2];
        //if(f[i] > 1000) break;
        //printf("%d %d\n",i , f[i]);
    }
    memset(sg, -1, sizeof(sg));
    sg[0] = 0;
    for(i = 1; i <= 1000; i++){
        dfs(i);
    }
}


int main(){
    init();

    int n, m, p;
    while(scanf("%d%d%d", &n ,&m, &p) &&(n || m||p)){

        int temp  = sg[n] ^ sg[m] ^ sg[p];
        printf("%s\n", temp ? "Fibo" : "Nacci");
    }
    return 0;
}
