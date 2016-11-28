#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int M = 100004;
const int N =  14;
int dp[M];
int cash[N * 100];

int main(){
    int all, n, val, m, i, j, num, no = 0;
    while(scanf("%d", &all) != EOF){
        no = 0;
        scanf("%d", &n);
        while(n--){
            int time = 1;
            scanf("%d%d", &m, &val);
            while(m > 0){
                if(time > m)    time = m;
                m -= time;
                cash[++no] = val * time;
                time <<= 1;
            }
        }

        memset(dp, 0, sizeof(dp));
        for(i = 1; i <= no; i++){
            for(j = all; j >= cash[i]; j--)
                dp[j] = max(dp[j], dp[j-cash[i]]+cash[i]);
          //  printf("%d\n", dp[all]);
        }

        printf("%d\n", dp[all]);


    }
    return 0;
}
