#include <cstdio>
using namespace std;

int main(){
    int TC, n, m;
    scanf("%d", &TC);
    while(TC--){
        scanf("%d%d", &n, &m);
        printf("%s\n", n %(m+1) ? "first": "second");
    }
    return 0;
}
