#include <cstdio>
#include <cstring>
using namespace std;


const int N = 1000004;
int f[N], g[N];

int main(){
    int n, m, tc, TC, i, j, k, temp;
    scanf("%d", &TC);
    for(tc = 1; tc <= TC;tc++){
        scanf("%d%d", &n , &k);
        printf("Case %d: ", tc);
        f[i = 0] = g[j = 0] = 1;// printf("%d %d %d %d\n",n, f[i], i, j);
        while(n > f[i]){

            i++;
            f[i] = g[i-1] + 1;
            while(j < i && f[j+1] * k < f[i])  j++;

            if(f[j] * k < f[i]) g[i] = g[j] + f[i];
            else g[i] = f[i];
        }

        if(n == f[i]){
            printf("lose\n");
        }else {
            int ans = f[i];
            while(n ){
                if(f[i] <= n){
                    n-= f[i];
                    ans = f[i];
                }
                i--;
            }
            printf("%d\n", ans);
        }

    }
    return 0;
}
