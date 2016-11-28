#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main(){
    int n, m, i;
    while(cin >> n >> m){
        if(n <= m){
            for(i = n; i <m ; i++) cout<<i<<" ";
            cout<<m<<endl;
        }
        else if(n % (m + 1)){
            cout<<n % (m + 1)<<endl;
        }
        else cout<<"none"<<endl;

    }
    return 0;
}
