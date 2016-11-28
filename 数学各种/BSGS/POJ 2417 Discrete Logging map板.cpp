/******************
map
quickpow 4945
exgcd 4700+
******************/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <iostream>
using namespace std;

#define N
#define M
#define LL __int64
#define INF 0x3f7f7f7f
map<long long, int>f;
LL MOD;

LL quickpow(LL x, LL P){
    LL ans = 1LL, t = x;
    while(P){
        if(P & (1LL))
            ans = ans * t % MOD;
        t = t * t % MOD;
        P >>= 1;
    }
    return ans;
}
LL exgcd(LL a,LL b,LL &x,LL &y) {
    LL t,ret;
    if (!b) {
        x=1LL,y=0LL;
        return a;
    }
    ret=exgcd(b,a%b,x,y);
    t=x,x=y,y=t-a/b*y;
    return ret;
}
int main(void)
{
   // freopen("out.txt", "w", stdout);
    LL a, b, c, x, t, ans,  s, y;

    int i, m, j;
    while(scanf("%I64d%I64d%I64d", &c, &a,  &b) != EOF){

        m = ceil(sqrt((double)c));
        MOD = c;
        f.clear();  ans = -1LL;

        t = 1LL;    s = 1LL;
        for(j = 0; j < m; j++){
            if(f[t] == 0) f[t] = j + 1;
            t = t * a % c;
        }
        for(i = 0;  i < m; i++){
            //x = quickpow(s, c - 2);
            exgcd(s, c, x, y);
            if(f[(b * x % c + c) % c] != 0){
                ans = i * m + f[(b * x % c + c) % c] - 1;
                break;
            }
            s = s * t % c;
        }
        if(ans != -1LL){
            printf("%I64d\n", ans);
        }
        else printf("no solution\n");
    }
    return 0;
}
