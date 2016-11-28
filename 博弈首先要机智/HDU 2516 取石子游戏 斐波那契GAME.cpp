#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
const int N = 45;

int no = 0;
long long f[N+2];
map<int,bool>g;
void init(){
    int i, j;
    g.clear();
    f[0] = f[1] = 1;
    for(i = 2; i <= N; i++)   {
        f[i] = f[i-1]+f[i-2];
        g[f[i]] = true;
    }

}

int main(){
    init();

    int n;
    while(scanf("%d", &n) && n){
        printf("%s\n", g[n] ? "Second win":"First win");
    }
    return 0;
}
