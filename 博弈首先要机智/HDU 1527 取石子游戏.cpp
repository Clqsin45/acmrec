#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n, m, k;
    while(scanf("%d%d", &n, &m) != EOF){
        if(n < m)   swap(n, m);
        k = n - m;
        if(floor(k*(1.0+sqrt(5.0))/2.0) == m)  cout<<0<<endl;
        else cout << 1 <<endl;
    }
}
