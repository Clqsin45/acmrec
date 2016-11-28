#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    int ans , i, n, x;
    while(scanf("%d", &n) &&n){
        ans = 0;
        for(i = 1; i <= n; i++){
            scanf("%d", &x);
            ans ^= x;
        }
        printf("%s\n", ans ? "Rabbit Win!": "Grass Win!");
    }
    return 0;
}
