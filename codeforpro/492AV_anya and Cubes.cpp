/********************
1+2+...+x <= n, 得到最大的x
CF 492A Vanya and Cubes
**********************/#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, i, ans = 0, sum = 0, temp = 0;
    cin>>n;
    for(i = 1; i <= n; i ++){
       temp += i;
        sum += temp;
        if(sum > n)break;
        ans ++;
    }
    cout<<ans<<endl;
}
