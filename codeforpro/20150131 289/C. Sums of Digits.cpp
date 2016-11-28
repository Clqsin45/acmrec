#include <bits/stdc++.h>
using namespace std;

#define N 303
int b[N];
string a[N];
string nowget;
bool ok;

void  adddigit(int len, int pos){
    int i, j, k;
    string base = a[pos-1];
    string ans = "";
    nowget = "";
    int sum = 0;

    for(i = 0; i < len; i++){
        ans = base;
        for(j = base[i] - '0' + 1; j <= 9; j++){
            int temp = b[pos] - sum - j;
          //  cout<<pos<<" "<<j<<""<<temp<<endl;
            ans[i] = j + '0';
            if(temp >= 0){
                for(k = len - 1; k > i; k--){
                    ans[k] = min(9, temp);
                    temp -= ans[k];
                    ans[k] += '0';
                }
                if(temp) continue;
                if(nowget == "" || nowget > ans){
                    nowget = ans;
                    ok = true;
                }
            }
        }
        sum += base[i] - '0';
    }

}
void addlen(int len, int pos){
    int i, j;
    int sum = b[pos];
    a[pos] = "";
    for(i = 0; i < len; i++) a[pos] += '0';
    a[pos][0] = '0' + max(1, sum - (len-1)*9);
    sum -= (a[pos][0] - '0');
    for(i = len - 1; i >= 1; i--){
        a[pos][i] = min(9, sum) + '0';
        sum -= (a[pos][i] - '0');
    }
}
int main(){
    int n, i;
    cin >>n ;
    for(i  =  1; i <= n; i++){
        cin >> b[i];
        ok = false;
        int t = max((int)a[i-1].size(), (b[i] + 8 ) / 9);

        if(t == a[i-1].size()){
            adddigit(t, i);
            //cout<<"!!"<<i<<endl;
        }
        if(ok){
            a[i] = nowget;
        }
        else {
            t = max((int)a[i-1].size()+1, (b[i] + 8 ) / 9);

            addlen(t, i);
        }
    }
    for(i = 1; i <= n; i++) cout<<a[i]<<endl;
}
