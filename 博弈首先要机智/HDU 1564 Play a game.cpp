#include <cstdio>

using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) &&n ){
        printf("%s\n", n & 1? "ailyanlu" : "8600");
    }
    return 0;
}
