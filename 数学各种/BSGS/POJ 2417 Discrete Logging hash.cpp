/***************************

version : hash + quickpow 391ms
          hash + exgcd 282ms
***************************/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

#define N
#define LL __int64
#define INF 0x3f7f7f7f

LL M;
class Hash{

    private:
        static const LL MOD=100007;
        int st[MOD + 10];
        LL num[MOD + 10];

    public:
        Hash(){
            memset(num, -1, sizeof(num));
        }

        int find(LL val){
            int loc = val % MOD;
            while(num[loc] != val && num[loc] != -1)    loc = (loc + 1) % MOD;
            return loc;
        }
        void insert(LL val, int to){
            int loc = find(val);
            if(num[loc] == -1){
                num[loc] = val;
                st[loc] = to;
            }
        }
        int require(LL val){
            int loc =find(val);
            if(num[loc] != val) return -1;
            return st[loc];
        }
        void clear(){
            memset(num, -1, sizeof(num));
        }

}f;

LL quickpow(LL x, LL P){
    LL ans = 1LL, t = x;
    while(P){
        if(P & (1LL))
            ans = ans * t % M;
        t = t * t % M;
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
    LL a, b, c, x, y, s, t, ans;

    int i, j, m;

    while(scanf("%I64d%I64d%I64d", &c, &a, &b)  !=  EOF){
        f.clear();      M = c;  ans = -1LL;

        m = ceil(sqrt((double)c));
        t = 1LL;    s = 1LL;
        for(i = 0; i < m; i++){
            f.insert(t, i);
            t = t * a % c;
        }

        for(i = 0; i < m; i++){
            //x = quickpow(s, c - 2);
            exgcd(s, c, x, y);
            x = (x % c + c) % c;
            j = f.require(b * x % c);
            if(j!= -1){
                ans = (LL)i * m + j;
                break;
            }
            s = s * t % c;
        }
        if(ans == -1LL)printf("no solution\n");
        else printf("%I64d\n", ans);


    }
    return 0;
}
