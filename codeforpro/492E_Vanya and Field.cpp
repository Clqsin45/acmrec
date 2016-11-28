/********************
n*n的方格，m个点上有苹果。每次从现在的点（x, y）走到((x+dx)%n, (y+dy)%m)
n, m, dx, dy(1 ≤ n ≤ 106, 1 ≤ m ≤ 105, 1 ≤ dx, dy ≤ n)
ndx互质，ndy互质
走到之前走过的点则停止。
问任选一个点开始走最多能搞到多少苹果。

一开始还想图论啥的想多了= =
注意到一堆互质，所以n是底之类的东西，也就是k*(dx) % n 当k从0~n-1可以取遍0~n-1所有值。
所以走n步之后一定回到本点，每个点都对应的可以走到(i,0),独一无二的映射。而且有(i+k*(dx))%n 显然与(0+k*(dx))%n的某种差是一个定值
因此先处理出0,0到达的点，即f[x]为到第i行的时候的列数。
这样取出最多的路径就方便了
**********************/
#include<bits/stdc++.h>
using namespace std;
#define N 1000004
int f[N], cnt[N];

void gao(void){
    int n, m, dx, dy;
    scanf("%d%d%d%d", &n, &m, &dx, &dy);
    int x, y, t, ans = -1, loc;
    x = y = 0;
    for(int i = 0; i < n; i++){
        f[x] = y;
        x  = (x +dx) % n;
        y = (y + dy) % n;
    }
    while(m--){
        scanf("%d%d", &x, &y);
        t = (y - f[x] + n) % n;
        cnt[t]++;
        if(cnt[t] > ans){
            ans = cnt[t];
            loc = t;
        }
    }
    printf("%d %d\n", 0, loc);
}
int main(void){

    gao();
}
