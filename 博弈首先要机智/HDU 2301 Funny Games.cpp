#include <cstring>
#include <cstdio>
#include <algorithm>
#include<cmath>
using namespace std;

const int N  = 8;
const int M  = 10000004;
const double eps = 1e-9;

int n;
int a[N];

char dp[M];

bool dfs(int x){
  //  printf("%d\n", x);
    if(x <= 0)  return false;
    if(dp[x] != -1)return dp[x];
    int i;
    for(i = 1; i <= n; i++){
        if(!dfs(x + a[i])) return dp[x] = 1;
    }
    return dp[x] = false;
}
int main(){
    int TC, i, j;
    double x;
    int t, v;
    scanf("%d", &TC);

    while(TC--){
        scanf("%lf%d", &x, &n);
        memset(dp,-1,sizeof(dp));
        x = log(x)*1000000;
        t = (int)x;
        for(i = 1; i<= n; i++)  {
            scanf("%lf", &x);
            x = log(x)*1000000; a[i] = (int)x;
        }
        //printf("%d %d %d\n", t, a[1], a[2]);
       // system("pause");
        printf("%s\n", dfs(t) ? "Nils" : "Mikael");
    }
    return 0;
}
