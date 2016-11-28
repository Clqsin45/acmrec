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

int dfs(int x){
    int pos = lower_bound(f , f +N +1, x) - f;
    if(f[pos] == x)return x;
    return dfs(x - f[pos-1]);
}
int main(){
    init();

    int n;
    while(scanf("%d", &n)!= EOF){
        if(g[n])printf("lose\n");
        else {
            int pos = lower_bound(f, f + N + 1, n) - f;
            printf("%d\n", dfs(n - f[pos-1]));
        }
    }
    return 0;
}
