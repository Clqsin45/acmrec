#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;

const int N = 30004;
ll f[N], g[N];

int main(){
    int  m, tc, TC, i, j,  temp;
    ll n, k;
    scanf("%d", &TC);
    while(TC--){
        scanf("%lld%lld", &k , &n); //k±¶£¬¹²N ¸ö
        f[i = 0] = g[j = 0] = 1;
        while(n > f[i]){

            i++;
            f[i] = g[i-1] + 1;
            while(j < i && f[j+1] * k < f[i])  j++;

            if(f[j] * k < f[i]) g[i] = g[j] + f[i];
            else g[i] = f[i];
        }
      //  printf("%d\n", i);
        ll ans;
        if(n == f[i]){
            ans = n - i - 1;
        }else {
            ans = n - i;
        }printf("%lld\n", ans);

    }
    return 0;
}
