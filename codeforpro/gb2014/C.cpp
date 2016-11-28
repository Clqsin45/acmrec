#include <bits/stdc++.h>
using namespace std;
#define LL __int64

#define N 505
#define M 1004
int a[N], w[N];
int d[M], od[N], pos[N];
bool app[N];
LL ans;

int main(void){
    int n, m, i, j, tot = 0, temp, x;
    cin>>n>>m;
    for(i = 1; i <= n; i++) cin>>w[i];
    for(i =1; i <= m; i++)  cin>>d[i];

    for(i = 1; i <= m; i++){
        if(app[d[i]])   continue;
        app[d[i]] = true;
        od[++tot] = d[i];
        pos[d[i]] = tot;
    }
    for(i = 1; i <= m; i++){
        x = d[i];   temp = 0;
        for(j = pos[x] - 1; j >= 1;  j--){
            temp += w[od[j]];
            swap(od[j], od[j+1]);
            pos[od[j]] = j; pos[od[j+1]] = j + 1;
        }
        //cout<<i<<" "<<temp<<endl;
        od[1] = x;  pos[x] = 1;
        ans += temp;
    }
    cout<<ans<<endl;
}
