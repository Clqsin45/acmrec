#include<bits/stdc++.h>
using namespace std;

#define N 304
#define M 5000
#define T 32000
#define INF 0x3f3f3f3f
int f[N][M];
int a[N], b[N], cost[N], rec[T];
bool nicprime[T];
int cnt = 0;
vector<int>fact;


void init(){
    int i, j;
    memset(nicprime, false, sizeof(nicprime));
    for(i = 2; i <= 31633; i++){
        if(!nicprime[i])    rec[cnt++] = i;
        for(j = 0; j < cnt && i * rec[j] <= 31633; j++)
        {
            nicprime[i * rec[j]] = true;
            if(i % rec[j] == 0)   break;
        }
    }
}
void calpri(int i){
    int n = sqrt(a[i]) + 1, t  = a[i];
  //  printf("%d %d %d\n", i, n, t);
    for(i = 0; i < cnt; i++){
        if(rec[i] > n)  break;
        if(t  % rec[i])  continue;
        fact.push_back(rec[i]);

        while((t % rec[i]) == 0) t /= rec[i];//printf("!!!%d %d\n", i, t);
        if(t == 1) break;
    }
    if(t != 1)  fact.push_back(t);
}

void compri(int j){
    int i,  m = fact.size();
    b[j] = 0;
    for(i = 0; i < m; i++){
        if((a[j] % fact[i])==0) b[j] |= 1;
        b[j] <<= 1;
    }
    b[j] >>= 1;
}

int main(){
    int i, j, n, ans = INF, m, k;
    init();
    cin >> n;
    for(i = 1; i <= n; i++){
        cin>>a[i];
    }
    //cout<<__gcd(a[1], a[6])<<endl;
    for(i = 1; i <= n; i++) cin >> cost[i];
    for(i = 1; i <= n; i++){
        fact.clear();
        calpri(i);
        m = 1 << (fact.size());
        memset(f, 0x3f, sizeof(f));
        f[i][m-1] = cost[i];
       // cout<<i << " "<< m - 1<<endl;
        for(j = i +1; j <= n; j++){
            compri(j);

            for(k = 0; k < m; k++){
                f[j][k] = min(f[j-1][k], f[j][k]);
                f[j][k&b[j]] = min(f[j][k&b[j]], f[j-1][k] + cost[j]);
            }
          //  cout<<j<<" "<<b[j]<<" "<<f[j][0]<<endl;
        }
        if(f[n][0] != f[0][0]){
          //  cout<<i<<endl;
            ans = min(ans, f[n][0]);
        }
    }
    if(ans == INF)ans = - 1;
    cout<<ans<<endl;
    return 0;

}
