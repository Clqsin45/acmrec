#include <bits/stdc++.h>
using namespace std;
#define ll __int64

int main(){
    ll ans =  0, n, h, i, temp, now = 1;
    cin >> h >> n;
    while(h ){

        if(h == 1){
            ans += ((n & 1) ? 1 : (now+1));
        }
        else if((((n+1) / 2) & 1LL) ^ (n & 1LL)){
            ans ++;
        }
        else ans += (now+1);
       // cout<<h<<" "<< n<<" " <<ans<<" " << now<<endl;
        now = (now + 1) * 2 - 1;
        h--;
        n = (n+1)/ 2;
    }
    cout <<ans<<endl;
}
