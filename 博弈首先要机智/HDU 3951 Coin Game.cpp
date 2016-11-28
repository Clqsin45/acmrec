#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int TC, n, k, tc;
    scanf("%d", &TC);
    for(tc = 1; tc<= TC; tc++){
        scanf("%d%d", &n, &k);
        printf("Case %d: ", tc);
        if(k == 1){
            printf("%s\n", n & 1 ? "first" : "second");
        }else{
            printf("%s\n", n <= k ? "first": "second");
        }
    }
    return 0;
}
