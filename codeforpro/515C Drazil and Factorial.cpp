#include <bits/stdc++.h>
using namespace std;
char a[16];
int f[10];

int main(){
    int n, i;
    memset(f, 0, sizeof(f));
    cin>> n >>a;
    for(i = 0; i <n ;i++) {
        if(a[i] == '4'){
            f[2] += 2;
            f[3] ++;
        }
        else if(a[i] == '6'){
            f[5] ++;    f[3] ++;
        }
        else if(a[i] == '8'){
            f[7]++; f[2] += 3;
        }
        else if(a[i] == '9'){ //8*9=3!*3!*2!
            f[7] ++;    f[3] += 2;  f[2]++;
        }
        else f[a[i]-'0'] ++;
    }
   // cout<<f[2]<<f[3]<<endl;
    for(i = 7; i >= 2; i--){
        while(f[i]--) cout<<i;
    }
    cout<<endl;

}
