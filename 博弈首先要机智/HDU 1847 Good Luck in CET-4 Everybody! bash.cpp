#include <cstdio>
using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        printf("%s\n", n % 3 ? "Kiki": "Cici");
    }
    return 0;
}
