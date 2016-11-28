#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(){
    int n, m, x,  y, ans, i;
    while(scanf("%d%d", &n, &m) != EOF){
        ans =0;
        for(i = 1; i <= n; i++){
            scanf("%d%d", &x, &y);
            ans ^= (max(y-x, x - y)- 1);
        }
        printf("%s\n", ans ? "I WIN!" :"BAD LUCK!");
    }
    return 0;
}
