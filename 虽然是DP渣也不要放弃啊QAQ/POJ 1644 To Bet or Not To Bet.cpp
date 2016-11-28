#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
using namespace std;

const double eps = 1e-9;
const int N = 100;
double dp[N][N];

int doublecmp(double x){
    if(fabs(x)<eps) return 0;
    return x < 0 ? -1 : 1;
}
struct point{
    int step, info;
    point(){};

    point(int x, int y){step = x, info = y;}
}p[N];

 int main(){
    int TC, t, n, i, j, x;
    scanf("%d", &TC);
    string st;
    while(TC--){
        scanf("%d%d", &n, &t);
        for(i = 1; i <= n; i++){
            cin >> st;
            if(st[0] == 'L'){
                p[i]=point(0, 0);
            } else{
                istringstream is;
                is.str(st);
                is>>x;
                if(x == 0)
                    p[i] = point(0, -1);
                else p[i] = point(x, 1);
            }
        }
        memset(dp, 0, sizeof(dp));
        p[0] = point(0, -1);
        dp[0][0] = 1;   n ++;
        p[n] = point(0, -1); p[n+1] = point(-1, -1);    p[n+2] = point(-2, -1);
        for(i = 1; i <= t; i++){
            for(j = 0; j <= n ;j++){
                if(p[j+1].info == 0){
    //                dp[i][j] += dp[i-1][j];
                    dp[i+1][min(n, j + 1)] += 0.5*dp[i-1][j];
                }
                else{
                    dp[i][j+1+p[j+1].step] += 0.5*dp[i-1][j];
                }
                if(p[j+2].info == 0){
                    dp[i+1][min(n, j + 2)] += 0.5*dp[i-1][j];
                }
                else {
                    dp[i][j+p[j+2].step+2] += 0.5*dp[i-1][j];
                }

            }

        }
//        for(i = 1; i <= t; i++){
//            for(j = 0; j <= n; j++){
//                printf("%d %d %f\n", i, j, dp[i][j]);
//            }
//        }
        x = doublecmp(dp[t][n]-0.5);

        printf("%s %.4f\n",x==0?"Push.":(x<0?"Bet against.":"Bet for."), dp[t][n]);
    }
 }
