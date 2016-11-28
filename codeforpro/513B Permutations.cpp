#include <bits/stdc++.h>
using namespace std;
const int N  = 55;
typedef __int64 ll;
int a[N];

int main(){
    int n,i, j;
    ll m;
    cin >> n >> m;
    int left = 1, right = n;
    for(i = 1; i <= n; i++){
        if((1ll<<(n-i-1)) >= m){
            a[left++] = i;
        }
        else{
            a[right--] = i;
            m -= (1ll<<(n-i-1));
        }
    }
    for(i = 1; i <= n; i++){
        printf("%d%c", a[i], i == n ? '\n' : ' ');
    }
    return 0;
}
