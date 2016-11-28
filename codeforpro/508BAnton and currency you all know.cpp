#include <bits/stdc++.h>
using namespace std;

#define N 100005

char a[N];

int main(void){
    cin>>a+1;
    int n = strlen(a+1);
    int i;
    bool tran = false;

    for(i = 1; i < n; i++){
        if((a[i]-'0')&1)    continue;
        if(a[i] < a[n]) {

            swap(a[i], a[n]);
            tran = true;
            break;
        }
    }
    if(tran){
        cout<<a+1<<endl;
        return 0;
    }
    for(i =n - 1; i>=1 ; i--){
        if((a[i]-'0')&1)    continue;
        swap(a[i], a[n]);
        tran = true;
        break;
    }
    if(tran){
        cout<<a+1<<endl;
    }
    else cout<<-1<<endl;
    return 0;
}
