#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){

    int n, i, x, ans, cnt;

    while(scanf("%d", &n) != EOF){
        ans = cnt = 0;
        while(n--){
            scanf("%d", &x);
            ans ^= x;   cnt += (x > 1);
        }
        printf("%s\n", ((ans > 0) ^ (cnt >= 1)) ? "No" : "Yes");

    }
    return 0;
}
