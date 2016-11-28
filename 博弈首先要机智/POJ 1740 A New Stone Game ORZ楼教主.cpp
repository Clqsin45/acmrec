#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 11;
int a[N];
int main(){
    int n, m, x, ans, i;
    while(scanf("%d", &n) && n){
        ans = 0;
        for(i = 1; i <= n; i++) scanf("%d", &a[i]);
        if(n & 1){
            ans = 1;
        }else {
            sort(a + 1, a+ n +1);
            for(i = 1; i < n; i+= 2){
                if(a[i] != a[i + 1])    {
                    ans = 1;
                    break;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
