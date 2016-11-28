#include <cstdio>
#include<cstring>
#include <algorithm>
using namespace std;


bool go[6] = {1, 0, 1, 0, 0, 1};

int main(){
    int tc, TC, n, i, ans, x;
    scanf("%d", &TC);
    for(tc=  1; tc <= TC; tc++){
        scanf("%d", &n);
        ans = 0;
        for(i = 1; i <= n; i++){
            scanf("%d", &x);
            ans ^= (go[i%6]*x);
        }
        printf("Case %d: ", tc);
        printf("%s\n",ans ?  "Alice":"Bob");
    }
    return 0;
}
