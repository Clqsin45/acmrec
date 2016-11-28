/********************
10^5门课，每门课最多得到r分,r<=10^9，需要平均分为avg，avg <= min(10^6,r)
已知第i门课已经得到ai分，1 ≤ ai ≤ r,每写bi篇论文可以多得一分，1 ≤ bi ≤ 10^6
问最少需要些多少篇论文可以获得平均分

按b的值统计，即写b篇论文可以拿一分的课还能拿几分
按b 从小到大，直至凑满分数
492C. Vanya and Exams
**********************/
#include <bits/stdc++.h>
using namespace std;

#define N 1000005
#define LL __int64
LL lt[N];
int n, r, avg;
long long sum = 0, nowget = 0, ans = 0;

void input(){
    int a,  b;
    cin >> n >> r >> avg;
    sum = (LL) n * avg;

    memset(lt, 0, sizeof(lt));
    for(int i = 1; i <= n; i++){
        cin>>a>>b;
        lt[b] += (r - a);
        nowget += a;
    }
}

void gao(void){
    sum -= nowget;
    for(int i = 1; i <= N; i++){
        if(sum > 0){
            ans += min(sum, lt[i]) * i;
            sum -= min(sum, lt[i]);
        }
        else break;
    }cout<<ans<<endl;
}
int main(void){
    input();
    gao();
}
