#include <bits/stdc++.h>
using namespace std;
const int N = 104;
char a[N], b[N];
char c[N];
int main(){
    cin>>a>>b;
    int n = strlen(a);
    int i, j,temp = 1;
    bool gg= true;
    for(i = n - 1; i >= 0; i--){
        c[i] = a[i] + temp;
        if(c[i] > 'z'){
            c[i] = 'a';
        }else{
            temp = 0;
        }
    }

    for(i = 0; i < n; i++){
        if(c[i] == b[i])    continue;
        if(c[i] < b[i]) {
            gg = false; break;
        }else break;
    }
    c[n] = '\0';
    if(gg)cout<<"No such string"<<endl;
    else cout<<c<<endl;
}
