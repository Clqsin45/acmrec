#include <bits/stdc++.h>
using namespace std;
const int N  = 100005;
typedef __int64 ll;

int pos[N], scr[N], dir[N];

int main(){
    int n, m, i, j, k, id = 1, x, y;
    scanf("%d%d%d", &n, &m, &k);
    for(i = 1, j = 1; i <= n; i++){
        scanf("%d", &x);
        dir[i] = x;     pos[x] = i;
        scr[x] = id;    j++;
        if(j > k)   {
            j = 1;  id ++;
        }
    }
    ll ans = 0;
    while(m--){
        scanf("%d", &x);
        ans += scr[x];
       // cout<<ans<<endl;
        i = pos[x];
        if(i==1)    continue;
        y = dir[i-1];
        swap(scr[x],scr[y]);
       // cout<<x<<" "<<scr[x]<<" "<<y<<" "<<scr[y]<<endl;
        swap(dir[i], dir[i-1]);
        swap(pos[x], pos[y]);
    }
    cout << ans<<endl;
}
