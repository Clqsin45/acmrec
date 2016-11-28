#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const int N = 30;
int f[N];

map<int, int>g;

void init(){
    int i;
    g.clear();
    f[1] = 1;   g[1] = true;
    for(i = 2; i <= 25; i++) {
        f[i] = f[i-1]<<1;
        g[f[i]] = i;
    }
    //for(i = 1; i <= 25; i++)printf("%d %d\n", i, f[i]);
}
int main(){
    init();


    int TC, i, n, m, p;
    scanf("%d", &TC);
    while(TC--){
        scanf("%d%d%d", &n, &m, &p);
        if(n <= 2*m + 2){
            int cnt = (n+1) / 2;
            if(p == n){
                printf("%d\n", m - cnt +1);
            }
            else if((p&1) == (n&1)){
                printf("1\n");
            }
            else printf("0\n");
        }
        else{
            if(p == n){
                if(g[n-2*m]){
                    printf("0\n");
                }
                else {
                    printf("Thrown\n");
                }
            }
            else if(g[n-2*m]){
                printf("0\n");
            }
            else{
                for(i = 1; i <= 25; i++) {
                    if(n-2*m < f[i])    break;
                }
               // printf("%d %d\n", i);
                if(f[i-1] <p - 2 * m) printf("Thrown\n");
                else printf("0\n");
            }
        }
    }
    return 0;
}
