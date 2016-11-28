#include <bits/stdc++.h>
using namespace std;

#define N 200005
map<string, int>f;
int fa[N];
string dir[4000];
string temp;
vector<int> vec[4004];
stack<int>ans;
string ch;
int deg[N];
void dfs(int x){
    int y;
    while(!vec[x].empty()){
        y = vec[x].back();
        vec[x].pop_back();
        dfs(y);
    }

    ans.push(x);
}
int find(int x){
    if(fa[x] == x)return x;
    return fa[x] = find(fa[x]);
}
void merge(int x, int y){
    x = find(x);    y = find(y);
    if( x != y){
        fa[x] = y;
    }
}
int main(){
    //freopen("in.txt", "r", stdin);
    int n, i, x, y, out = 0, in = 0, num = 0, s;
    cin >> n;
    bool gg = false;
    for(i = 1; i <= n; i++){
        cin >> ch;
        temp = ch[0];   temp += ch[1];
        x = f[temp];
        if(x == 0) {
            f[temp] = ++num;
           // cout<<temp<<endl;
            dir[num] = temp;
            fa[num] = num;
            x = num;
        }

       temp = ch[1];   temp += ch[2];
        y = f[temp];
        if(y == 0){
            f[temp] = ++num;
            dir[num] = temp;
            fa[num] = num;
            y = num;
        }
        deg[x] ++;  deg[y] --;
        vec[x].push_back(y);
    //    cout<<"haha"<<endl;
        merge(x, y);
    }
  //  cout<<num<<endl;
    for(i = 1; i <= num; i++) fa[i] = find(i);

    for(i = 1; i <= num; i++){
        if(fa[i] != fa[1]){
            gg = true;
            break;
        }
        if(deg[i] != 0){

            if(deg[i] == 1){
                if(out) {
                    gg = true;
                    break;
                }
                out = i;
            }
            else if(deg[i] == -1) {
                if(in){
                    gg = true;
                    break;
                }
                in = i;
            }
            else{
                gg =true;
                break;
            }
        }
    }
    if(gg) cout<<"NO"<<endl;
    else {
        if(out) s = out;
        else s = 1;
        dfs(s);
       // cout<<dir[1]<<endl;
        cout<<"YES"<<endl;
        cout<<dir[s][0];
        while(!ans.empty()){
            cout<<dir[ans.top()][1];    ans.pop();
        }

    }

}
