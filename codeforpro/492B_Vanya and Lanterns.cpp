/********************
1 ≤ l ≤ 10^9的路上，给出一堆一维的点 1000个之内，为路灯。所有路灯的照明范围相同，问能照明整条路的最小范围是多少
相邻两个点距离最大值/2，0-第一个路灯 最后一个路灯-l
取最大值
第一反应居然还二分了一下真是被自己蠢死= =
CF 492A Vanya and Cubes
**********************/
#include <bits/stdc++.h>
using namespace std;
#define N 1004
int a[N];
int main(){
    int n, l, i, ans = 0;
    cin>>n>>l;
    for(i = 1; i <= n; i++)cin>>a[i];
    a[0] = 0;
    sort(a, a +n +1);
    for(i = 1; i <= n; i++){
        ans = max(ans, a[i] - a[i-1]);
    }
    //printf("%d\n", a[1]);
    ans = max(a[1] *2, ans);   ans = max((l-a[n])*2, ans);
    printf("%.10f\n", ans *1.0 / 2.0);
}
