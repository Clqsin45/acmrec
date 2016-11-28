#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1004;
int f[N], g[N];

int main(){
    int n, m, i, j, ans;

    while(scanf("%d%d", &n, &m) != EOF){
        ans = 0;    j = 0;
        f[0] = -1;
        for(i = 1; i <= n; i++){
            scanf("%d", &f[i]);
        }
        if(m == 1)  printf("Alice\n");
        else {
            for(i = !(n & 1); i < n; i+=2){
                g[++j] = f[i+1] - f[i]-1;
                if((n&1)&&j==1&&m==2)   g[j]--;
                ans ^= g[j];
            }
            //printf("%d %d\n",j, ans);
            printf("%s\n", ans ? "Alice":"Bob");
        }
    }
    return 0;
}
