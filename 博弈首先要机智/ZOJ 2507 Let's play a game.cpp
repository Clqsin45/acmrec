#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int i, x, ans, cnt, n, TC;
    scanf("%d", &TC);
    while(TC--){
        scanf("%d", &n);
        ans = cnt = 0;
        while(n--){
            scanf("%d", &x);
            cnt += (x > 1);
            ans ^= x;
        }
        printf("%d\n", (ans > 0) ^ (cnt > 1) ? 2 : 1);

    }
}
