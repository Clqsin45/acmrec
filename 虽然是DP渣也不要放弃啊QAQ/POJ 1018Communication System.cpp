#include<cstdio>
#include <cstring>
#include <algorithm>
#include<map>
using namespace std;

#define N 10005
#define INF 0x3f3f3f3f
map<int, int>f;
int a[N], s[105], id, maxn;
struct point{
    int band, price;
    point(){};
    point(int x, int y){band = x, price = y;}

    void scan(){
        scanf("%d%d", &band, &price);
        a[++id] = band;
    }
    bool operator<(const point &I)const{
        if(band == I.band)  return price < I.price;
        return band <I.band;
    }
    bool operator==(const point &I)const{
        return band == I.band;
    }
}p[104][104];

int dp[2][N];

int main(){
    int no , TC, i, n, j, k, m, x;
    scanf("%d", &TC);
    while(TC--){
        scanf("%d", &n);    id = 0;
        for(i = 1; i <= n; i++){
            scanf("%d", &m);    s[i] = m;
            for(j =1; j <= m; j++){
                p[i][j].scan();
            }
            sort(p[i] +1, p[i] + 1 + m);
            s[i] = unique(p[i] +1, p[i] + 1 + m) - p[i] - 1;
        }
        sort(a + 1, a + id + 1);
        id = unique(a +1,  a+id +1) - a- 1;
        f.clear();
        for(i = 1; i <= id; i++){
            f[a[i]] = i;
        }
     //   printf("%d\n", id);
        for(i = 1; i <= n; i++){
            for(j = 1;j <=s[i]; j++){
                p[i][j].band = f[p[i][j].band];
          //      printf("%d ", p[i][j].band);
            }
            //printf("\n");
        }


        for(i = 1; i <= id; i++)    dp[0][i] = 0;
        for(i = 1; i <= n; i++){
         //   printf("!!%d\n", i);
            memset(dp[i&1], 0x3f, sizeof(int)*N);
            for(j =  1; j <= s[i]; j++){
                x = p[i][j].band;
                for(k = 1; k <= id+1; k++){
                    dp[i&1][min(x, k)] = min(dp[i&1][min(x, k)], dp[!(i&1)][k]+p[i][j].price);
                //    printf("%d %d %d %d\n", j, k, min(j,k), dp[i&1][min(x, k)] );
                }
            }
        }
        double ans = 0.0;
        for(i = 1; i <= id; i++){
            ans = max(a[i]*1.0 / dp[n & 1][i], ans);
        }
        printf("%.3f\n", ans);


    }
}
