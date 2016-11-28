#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1005;

int a[N];
int main(){
    int n, i, temp, cnt, ans;
    while(scanf("%d", &n) && n){
        ans = cnt = 0;
        for(i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            ans ^= a[i];
        }
        if(ans){
            for(i = 1; i <= n; i++){
                temp = (ans ^ a[i]);
                if(temp <= a[i])    cnt ++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
