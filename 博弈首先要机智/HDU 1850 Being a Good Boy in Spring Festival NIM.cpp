#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 104;
int f[N];
int main(){
    int n, i, ans, temp;
    while(cin >> n){
        if(n == 0)  break;
        ans = 0;
        for(i = 1; i<= n; i++){
            cin >> f[i];
            ans ^= f[i];
        }
      //  cout<<ans <<endl;
        int cnt  =0;
        for(i = 1; i<= n; i++){
            temp = (ans ^ f[i]);
            if(temp <= f[i]) cnt ++;
        }
        if(ans == 0)cnt = 0;
        cout << cnt<<endl;
    }
}
