#include <bits/stdc++.h>
using namespace std;
const int N  = 104;

int a[N], b[N];

int main(){
    int n, m, g, i, j, x, y;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    cin >> n >> m;
    cin >> g;
    while(g--){
        cin>>x;
        a[x] = 1;
    }
    cin >> g;
    while(g--){
        cin>>x;
        b[x] = 1;
    }
    g = __gcd(n, m);
    g = n / g * m * max(n, m);
    for(i = 0; i < g; i++){
        x = i % n;  y = i % m;
        a[x] = b[y] = (a[x] || b[y]);
    }
    bool gg = false;
    for(i = 0; i < n; i++) {
        if(a[i])continue;
        gg = true;  break;
    }
    for(i = 0; i < m && !gg; i++){
        if(b[i])continue;
        gg = true;  break;
    }
    printf("%s\n", gg ? "No" : "Yes");

}
