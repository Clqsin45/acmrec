#include <bits/stdc++.h>
using namespace std;

#define N 500005
char ch[N];
bool vis[200];
int n;

double f[N], g[N];
void init(){
    vis['I'] = vis['E'] = vis['A'] = vis['O'] = vis['U'] = vis['Y'] = true;
    int i;
    n = strlen(ch + 1);
    f[0] = g[0] = 0.0;
    for(i = 1; i <= n; i++){
        f[i] = f[i-1] + 1.0 / i;
        g[i] = g[i-1] + 1.0 * i / (n - i + 1);
    }
}


int main(){
    scanf("%s", ch +1);
    init();

    double ans = 0.0;
    int i, t;
    for(i = 1; i <= n; i++){
        if(!vis[ch[i]]) continue;
        t = min(i, n - i + 1);
        ans += t;
        ans += t * (f[n-t+1] - f[t]);
        ans += g[n - (n-t+1)];
    }
    printf("%.10f\n", ans);
}
