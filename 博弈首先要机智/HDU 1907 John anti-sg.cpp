#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    int ans, cnt, i, n, x, TC;
    scanf("%d", &TC);
    while(TC--){
        scanf("%d", &n);    cnt = ans = 0;
        while(n--){
            scanf("%d", &x);
            ans ^= x;   cnt += (x > 1);
        }
    //    printf("%d %d %d\n",cnt >= 1, , ans, cnt);
        printf("%s\n", ((ans > 0) ^ (cnt >= 1)) ? "Brother" : "John");
    }
    return 0;
}
