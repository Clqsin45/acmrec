#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int TC, n, k, tc;
    while(scanf("%d", &n) && n){
        printf("%s\n", n <= 2 ? "Alice" : "Bob");
    }
    return 0;
}
