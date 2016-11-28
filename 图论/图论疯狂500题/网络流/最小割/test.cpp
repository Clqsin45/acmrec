#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 104
#define M
#define LL __int64
#define INF 0x3f7f7f7f


int f[N];
int main(void)
{
    int n, i, x, y, m, t;
    double ans;
    scanf("%d", &n);
    t = n;
    memset(f, 0, sizeof(f));
    while(n --){
        scanf("%d", &x);
        f[x] = true;
    }
    scanf("%d%d", &n, &m);
     i = 0; n = m;
    while(m--){
        scanf("%d%d", &x, &y);
        if(f[x] && f[y])   i++;
    }
    printf("%f\n", 1.0 * n / t);
    return 0;
}
