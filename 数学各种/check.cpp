#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
using namespace std;
#define ll __int64
#define usint unsigned int
#define RE  freopen("1.in","r",stdin)

class hash {
public:
    hash() {
        memset(a,0xff,sizeof(a));
    }
    int locate(ll x) {
        ll l=x%MOD;
        while(a[l]!=x&&a[l]!=-1) l=(l+1)%MOD;
        return l;
    }
    void insert(ll x,ll va) {
        ll l=locate(x);
        if(a[l]==-1) {
            a[l]=x;
            v[l]=va;
        }
    }
    ll get(ll x) {
        ll l=locate(x);
        return a[l]==x?v[l]:-1;
    }
    void clear() {
        memset(a,0xff,sizeof(a));
    }
private:
    static const ll MOD=100007;
    ll a[MOD+100],v[MOD+100];
} S;

ll exgcd(ll a,ll b,ll &x,ll &y) {
    ll t,ret;
    if (!b) {
        x=1,y=0;
        return a;
    }
    ret=exgcd(b,a%b,x,y);
    t=x,x=y,y=t-a/b*y;
    return ret;
}

int main() {///A^x=B(modC)    A^j=B*A^(-m*i)(mod C)
    ll C,A,B;
    ll m,i,t,D,ans,x,y;
    while(scanf("%lld%lld%lld",&C,&A,&B)!=EOF) {
        S.clear();
        m=ceil(sqrt((double)C));
        t=1;
        for(i=0; i<m; i++) { /**One, two, baby steps.Three, four, baby steps.Five, six, baby steps.**/
            S.insert(t,i);
            t=t*A%C;
        }
        printf("%d\n", m);
        D=1;///此时t=A^m
        ans=-1;
        for(i=0; i<m; i++) { /**一歩 Giant Step , 君にとってLittle だとしても**/
            exgcd(D,C,x,y);///exgcd求逆元，得到x=D^(-i*m)
            if(i == 13883) {printf("%lld %lld\n", D, C);
            printf("%lld\n",x);}
            x=((x*B)%C+C)%C;///B*x=B*D^(-i*m)
            y=S.get(x);
            //printf("%lld,%lld\n",x,y);

            if(y!=-1) {
                ans=i*m+y;
                printf("%lld %d\n",i, y);
                break;
            }
            D=(D*t)%C;///D=t^i,(t=A^m)
        }
        if(ans==-1) printf("no solution\n");
        else printf("%lld\n",ans);
    }
    return 0;
}
