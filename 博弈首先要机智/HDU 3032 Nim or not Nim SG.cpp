#include <cstdio>
#include <algorithm>
using namespace std;
int go[4] = {-1, 0, 0, 1};
int main(){
    int n, m, ans, x, TC;
    scanf("%d", &TC);
    while(TC--){
       scanf("%d", &n);
       ans = 0;
       while(n--){
            scanf("%d", &x);
            if(x == 0)  ans ^= 0;
            else if(x == 1) ans ^= 1;
            else{
                m = x % 4;
                ans ^= (x+ go[m]);
            }
       }
       printf("%s\n", ans ? "Alice" : "Bob");
    }
    return 0;
}
