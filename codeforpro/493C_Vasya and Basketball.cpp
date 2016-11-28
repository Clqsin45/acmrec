#include<bits/stdc++.h>
using namespace std;

#define N 200005
#define LL __int64
#define INF 0x3f3f3f3f
int a[N], b[N], all[N<<1];

int main(){
    int n, m, i, j, tot = 0, ans = -INF, loc, x, temp;
    int suma, sumb, geta, getb;
    scanf("%d", &n);
    for(i = 1; i <= n; i++)scanf("%d", &a[i]), all[++tot] = a[i];
    scanf("%d", &m);
    for(i = 1; i <= m; i++) scanf("%d", &b[i]),all[++tot] = b[i];
    sort(a + 1,  a +n +1);
    sort(b +1, b + m +1);
    sort(all +1, all +tot +1);
    tot = unique(all +1, all + tot +1) - all;
    all[0] = 0; all[++tot] =  INF;
    for(i = 0; i <= tot; i++){
        x = lower_bound(a + 1, a + n +1, all[i]) - a;
        suma = (x - 1) *2 +(n + 1 - x) *3;
     //   printf("%d %d %d\n", i, x, suma);
        x = lower_bound(b + 1, b +m + 1, all[i]) - b;

        sumb = (x - 1) *2 + (m + 1 - x) *3;
       // printf("%d %d %d\n", i, x, sumb);
        if(suma - sumb > ans){
            ans = suma - sumb;
            geta = suma;    getb = sumb;
        }
    }
    printf("%d:%d\n", geta, getb);
}
