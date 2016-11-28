#include <bits/stdc++.h>
using namespace std;
const int N = 22;
char a[N];

int main(){
    int i;
    cin>>a;
    int n = strlen(a);
    if(a[0] < '9' && a[0] >'4') a[0] = '9' - a[0] +'0';
    for(i = 1; i < n; i++){
        if(a[i] > '4') a[i] = '9' - a[i] +'0';
    }
    cout<<a<<endl;

}
