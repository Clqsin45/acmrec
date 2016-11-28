#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100;
typedef __int64 ll;
struct point{
    bool type;
    ll num;
    point(){};
    point(bool tt, ll nn) {type = tt, num = nn;};
}p[N];
void init(){

    int i;
    ll now = 1;
    for(i = 1; i <= 100; i++){
        if(i & 1)   now *= 9;
        else  now *= 2;
        p[i] = point(i & 1, now);
        if(now >= 4294967295) break;
    }
  //  printf("%d\n", i);
}

int findval(ll x){
    int high, low, mid, ans;

    low= 1; high = 15;
    while(low <= high){
        mid = (low + high) >>1;
        if(p[mid].num >= x) {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
 //   printf("%d\n", ans);
    return ans;
}
int main(){
    ll n;

    init();

    while(scanf("%I64d", &n) != EOF){
        printf("%s\n", p[findval(n)].type ? "Stan wins.":"Ollie wins.");
    }
    return 0;
}
