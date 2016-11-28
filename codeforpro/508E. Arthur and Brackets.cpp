#include <bits/stdc++.h>
using namespace std;

#define N 4004

struct point{
    int left, right;

    void add(int x){
        left += x;  right += x;
    }
}p[666];
stack <int> S;
char ans[1400];
int main(){
    int n, i, pos = 0, j;

    cin >> n;
    for(i = 1; i <= n; i++){
        cin >> p[i].left >> p[i].right;
        ans[++pos] = '(';
        p[i].add(pos);
        S.push(i);
        while(!S.empty()){
            int x = S.top();
            if(pos + 1 < p[x].left || pos + 1 > p[x].right) break;
            ans[++pos] = ')';
            S.pop();
        }
    }
            if(!S.empty()){
            cout<<"IMPOSSIBLE"<<endl;
        }
        else cout<< ans + 1<<endl;
}
