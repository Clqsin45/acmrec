#include <bits/stdc++.h>
using namespace std;
const int N = 100004;
typedef __int64 ll;
bool vis[N];
ll get[N], a[N], ok[N];
char ch[11];
int main(){
    int n, k, i;
    for(i = 1; i <= n; i++){
        scanf("%s", ch);
        if(ch[0] == '?')    {
            vis[i] =false;
        }
        else {
            a[i] = atoi(ch);
            vis[i] = true;
        }
    }
    int f, r, id = 0, unknow = 0;
    ll sum = 0;
    for(f = r = 1; r <= n; r++){
        if(!vis[r]) unknow ++;
        else sum += a[r];
        if(r-f+1 == k ){
            if(!unknow){
                get[++id] = sum;
                ok[id] = true;
            }
            if(!vis[f]) unknow --;
            else sum -= a[f];
            f++;
        }
    }
}
