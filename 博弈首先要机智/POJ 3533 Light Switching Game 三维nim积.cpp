#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1004;
int f[N][N], a[N];
int x, y, z, n, ans;
int Nim_Multi(int x, int y);

int Nim_Multi_Power(int x, int y){
    if(f[x][y] != -1)return f[x][y];

    if(!x)  return f[x][y] = 1 <<y;
    if(!y)  return f[x][y] = 1 << x;
    int k = 1, ans= 1, t, x1 = x, x2 = x, y1 = y, y2 = y;
    while(x || y){
        t = 1 <<k;
        if((x&1||y&1)&&!((x&1)&&(y&1))) ans *= t;
        k <<= 1;
        x >>= 1;
        y >>= 1;
    }
    k = 1;
    while(x1 || y1){
        t = 1 << k;
        if((x1&1) &&(y1 & 1))   ans = Nim_Multi(ans, t / 2 * 3);
        k <<= 1;    x1>>=1; y1>>=1;
    }
    return f[x2][y2] = ans;
}
int Nim_Multi(int x, int y){
    if(!x || !y)return 0;
    if(x==1)    return y;
    if(y == 1)  return x;
    int ans = 0;
    int i, j, k, t;
    for(i = x, j = 0; i; i>>=1, j++){
        if(i & 1)   {
            for(t = y, k = 0; t; t >>= 1, k ++){
                if(t & 1){
                    ans ^= Nim_Multi_Power(j, k);
                }
            }
        }
    }
    return ans;
}

void gao(int x){
    bool hash[N];
    memset(hash, false, sizeof(hash));
    int i;
    for(i = 1; i < x; i++)  hash[a[i]] = true;
    i = 1;
    while(hash[i])  ++i;
    a[x] = i;
    return ;
}


int main(){
    memset(f, -1, sizeof(f));
    int i, x, y;
    for(i = 1; i <= 1000; i++)  gao(i);

    while(scanf("%d", &n) != EOF){
        ans = 0;
        for(i = 0; i < n; i++){
            scanf("%d%d%d", &x, &y, &z);
            ans ^= Nim_Multi(a[x], Nim_Multi(a[y], a[z]));
        }
        printf("%s\n", ans ?  "No": "Yes");
    }
    return 0;
}
