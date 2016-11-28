#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main(){
    int ans, n, x;
    while(scanf("%d", &n) != EOF){
        ans = 0;
        while(n--){
            scanf("%d", &x);
            ans^= x;
        }
        printf("%s\n", ans ? "Yes" : "No");
    }
    return 0;
}
