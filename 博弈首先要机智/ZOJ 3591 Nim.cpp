#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 100004;
int a[N], f[N];

void form(int n, int s, int w){
    int g = s;
    f[0] = 0;
    for (int i=1; i <= n; i++) {
        a[i] = g;
        if( a[i] == 0 ) { a[i] = g = w; }
        if( g%2 == 0 ) { g = (g/2); }
        else           { g = (g/2) ^ w; }
        f[i] = f[i-1] ^ a[i];
     //   printf("!%d! %d\n", a[i], f[i]);
    }
}
int main(){
    int n, m , g, TC, i, j, s, w;
    ll ans;

    scanf("%d", &TC);
    while(TC--){
        scanf("%d%d%d", &n, &s, &w);
        ans = 0;
        form(n, s, w);
        f[++n] = 0;
        sort(f + 1, f + n + 1);

        for(i = 1; i <= n; i++){
            j = upper_bound(f + i, f + n + 1, f[i]) - f - 1;
            //printf("%d\n", j);
            if(j == i)continue;
            else {
                m = j - i + 1;
                ans += (ll)m*(m-1)/2;
                i = j;
            }
        }
        printf("%lld\n", (ll)n*(n-1)/2-ans);

    }
    return 0;
}
