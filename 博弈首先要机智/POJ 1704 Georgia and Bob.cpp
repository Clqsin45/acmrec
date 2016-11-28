#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;
int f[N];

int main(){
    int TC, ans, i, n;
    scanf("%d", &TC);
    while(TC--){
        scanf("%d", &n);
        for(i = 1; i <= n; i++) scanf("%d", &f[i]);
        if(n & 1)   f[++n] = 0;
        sort(f +1, f +n +1);
        ans = 0;
        for(i = 1; i <= n; i+= 2){
            ans ^= (f[i+1] - f[i]-1);
        }
        printf("%s\n", ans ? "Georgia will win" : "Bob will win");
    }
}
