#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 22;

int a[N];

int main(){
    int TC, i, n, cnt;
    bool gg;
    scanf("%d", &TC);
    while(TC--){
        scanf("%d", &n);
        gg = true;
        for(i = 1; i <= n; i++)scanf("%d", &a[i]);
        for(i = 1, cnt = 0; i <= n; i++){
            if(a[i] <= 0)   break;
            cnt ++;
        }
        if(cnt & 1) gg = false;
        if(gg){
            for(cnt =  0, i = n; i >= 1; i--){
                if(a[i] <= 0) break;
                cnt ++;
            }
            if(cnt & 1)gg= false;
        }
        printf("%s\n", gg ? "NO" : "YES");
    }
    return 0;
}
