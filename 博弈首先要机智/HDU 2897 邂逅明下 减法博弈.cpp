#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    int n, p, q;
    while(scanf("%d%d%d", &n, &p, &q) != EOF){
        if(n == 0){
            printf("LOST\n");
        }
        else if(n%(p+q)==0 || n % (p+q) > p){
            printf("WIN\n");
        }
        else printf("LOST\n");
    }
    return 0;
}
