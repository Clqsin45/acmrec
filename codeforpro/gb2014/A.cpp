#include<bits/stdc++.h>
using namespace std;
#define N 100005
int a[N];

int main(void){
    int n, t, i, j;
    bool gg = true;

    cin>>n>>t;
    for(i = 1; i < n; i++) cin>>a[i];
    for(i = 1; i < n; ){

        i += a[i];
        if(i == t){
            gg = false;  break;
        }
    }
    if(!gg) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
