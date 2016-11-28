#include <bits/stdc++.h>
using namespace std;

#define N 104

struct point{
    int num, id;
    int f[N];

    void add(int x){
        f[++id] = x;
    }
    void print(){
        int i;
        for(i = 1; i < num; i++){
            cout<<f[i]<<" ";
        }
        cout<<f[i]<<endl;
    }
}p[N];

int main(){
    int n, i, j, m, k;
    cin >> n >> k;
    for(i = 1; i <= n; i++)
    {
        cin >> p[i].num;
        p[i].id = 0;
    }
    bool all, used, ok = false;
    for(i = 1; i <= k; ){
        all = true, used = true;
        for(j = 1; j <= n; j++){
            if(p[j].id < p[j].num){
                p[j].add(i);
                if(p[j].id < p[j].num){
                    all = false;
                }
            }
            else used = false;
        }
        if(all) {
            ok = true;
            break;
        }
        if(!used) i++;
    }
    if(ok){
        cout<<"YES"<<endl;
        for(i = 1; i <= n; i++){
            p[i].print();
        }
    }
    else cout<<"NO"<<endl;

}
