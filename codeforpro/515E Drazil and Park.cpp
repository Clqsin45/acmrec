#include <bits/stdc++.h>
using namespace std;
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int N = 100005;
const int INF = 0x3f3f3f3f3f3fll;
typedef __int64 ll;

ll d[N<<1], h[N<<1];

ll f[N<<3], g[N<<3], s[N<<3];
struct ans{
    ll maxf, maxg, maxs;
    ans(){};
    ans(ll ms, ll mf, ll mg){maxs = ms, maxf = mf, maxg = mg;};
};
void pushup(int x){
    f[x] = max(f[x<<1],f[x<<1|1]);
    g[x] = max(g[x<<1], g[x<<1|1]);
    s[x] = max(s[x<<1], s[x<<1|1]);
    s[x] = max(s[x], f[x<<1]+g[x<<1|1]);

}
void build(int l, int r, int rt){
    if(l == r){
        s[rt] = 0;
        f[rt] = (h[l]<<1)-d[l-1];
        g[rt] = (h[l]<<1)+d[l-1];
        return;
    }
    int mid = (l + r) >> 1;
    build(lson);    build(rson);
    pushup(rt);
}

ans ask(int L, int R, int l, int r, int rt){
   // printf("%d %d %d\n", l, r, rt); system("pause");
    if(L <= l && R >= r){
        return ans(s[rt], f[rt], g[rt]);
    }
    int mid = (l + r) >> 1;
    bool goleft = false, goright = false;
    ans out = ans(-INF, -INF, 0);
    ans Left, Right;
    if(L <= mid){
        Left = ask(L, R, lson);
        goleft = true;
    }
    if(R > mid) {
        Right = ask(L, R, rson);
        goright = true;
    }
    if(!goleft){
        out = ans(Right.maxs, Right.maxf, Right.maxg);
    }
    else if(!goright){
        out = ans(Left.maxs, Left.maxf, Left.maxg);
    }
    else {
        out = ans(max(Left.maxs, Right.maxs),
                  max(Left.maxf, Right.maxf),max(Left.maxg, Right.maxg) );
        out.maxs = max(out.maxs, Left.maxf + Right.maxg);
    }
    return out;
}

int main(){
    int n, m, i, j,l, r;
    scanf("%d%d", &n, &m);
    for(i = 1;i <= n; i++){
        scanf("%I64d", &d[i]);
        d[i+n] = d[i];
    }
    for(i = 1; i <= n; i++) {
        scanf("%I64d", &h[i]);
        h[n+i] = h[i];
    }
    int nn = n <<1;
    for(i = 1; i <= nn; i++)    d[i] = d[i-1] + d[i];

    build(1,nn, 1);
    while(m--){
        scanf("%d%d", &l, &r);
        if(r < l){
            swap(l, r);
            l++;    r--;
            printf("%I64d\n", ask(l, r, 1, nn, 1).maxs);
        }
        else {
            swap(l, r);
            l++;    r+= (n-1);
          //  printf("%d %d\n", l, r);system("pause");
            printf("%I64d\n", ask(l, r, 1, nn, 1).maxs);
        }
    }
    return 0;

}
