#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 200004;
int f[N];

int main(){
    int n, i, j, ans, temp;
    while(scanf("%d", &n) &&n){
        ans = 0;
        for(i = 1; i <= n; i++){
            scanf("%d", &f[i]);
            ans ^= f[i];
        }
        if(ans == 0){
            printf("No\n");
            continue;
        }
        printf("Yes\n");
        for(i = 1; i <= n; i++){
            temp = ans ^f[i];
            if(temp <= f[i]){
                printf("%d %d\n", f[i], temp);
            }
        }
    }
    return 0;
}
