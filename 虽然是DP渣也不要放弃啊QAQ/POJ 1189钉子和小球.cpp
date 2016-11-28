#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

#define N 144
typedef  __int64 ll;
struct point{
    ll up, down;
    point(){};
    point(ll x, ll y): up(x), down(y){};
    void print(){
        if(up == 0) down = 1;
        printf("%I64d/%I64d\n", up, down);
    }
    point operator+(const point &I)const{
        if(up==0)  return I;
        if(I.up==0)    return point(up, down);

        ll x = down, y = I.down;
        ll gcd = __gcd(x, y);
        ll com = x / gcd * y;
        ll tempup = y/gcd*up+x/gcd*I.up;
        gcd = __gcd(tempup, com);
        return point(tempup/gcd, com/gcd);
    }

    point operator/(int i)const{
        if(up & 1)return point(up, down * 2);
        return point(up / 2, down);
    }
}dp[N][N];

void init(){
    int i, j;
    for(i = 0; i < N; i++)  for(j = 0; j < N; j++)  dp[i][j] = point(0,1);
}
bool op[N<<2][N<<2];
string ch, c;
int main(){
   // freopen("in.txt", "r", stdin);
   // freopen("out.txt", "w", stdout);
    int i, j, k, n, m;
//
//    point a = point(1, 134217728);  point b = point(1, 134217728);
//    (a/2).print();
    while(scanf("%d%d", &n, &m) != EOF){
        memset(op, 0, sizeof(op));
        getchar();
        for(i = 1; i <= n; i++){
        //    cout<<i<<endl;
            getline(cin, ch);
            int len = ch.size();
            c = "";
            for(j = 0, k = 0; j < len; j++){
                if(ch[j] == '*'){
                    c += '*';
                }
                else if(ch[j] =='.')    c += '.';
            }
          // cout<<c<<endl;
            for(j = 1, k = 0; j < (n<<1); j++){
               //printf("!!!%d %d %d %d %d\n",((i^j) ^ (n&1)), i, j, j > n - i,j< n + i);
                if(((1&(i^j)) ^ (n&1))&& (j > n - i) && (j < n + i)) {
                    if(c[k] == '*')    op[i][j] = true;
                    k++;
                }
            }
        }

        init();

        dp[0][n] = point(1, 1);
        for(i = 1; i <= n; i++){
            for(j = 1; j < (n<<1); j++){
                if(op[i][j]){
                    dp[i][j+1] = dp[i][j+1] + (dp[i-1][j] / 2);
                    dp[i][j-1] = dp[i][j-1]+ (dp[i-1][j] / 2);
                }
                else {
                    dp[i][j] = dp[i-1][j] + dp[i][j];
                }
            }

//            for(j = 0; j < (n<<1); j++){
//                printf("%d %d ", i, j);dp[i][j].print();
//            }
        }
        dp[n][(m<<1)].print();
    }
}
