#include <cstdio>
#include <algorithm>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int map[2][2] = {{0,0},{0, 1}};

int Nim_Multi_Power(int x, int y){
    if(x <2)return map[x][y];
    int i;
    for(i = 0; ; i++){
        if((1<<(1<<i)) > x) break;
    }
    int a = (1<<(1<<(i-1)));
    int p = x / a,  s = y / a, t = y % a;
    int d1 = Nim_Multi_Power(p, s);
    int d2 = Nim_Multi_Power(p, t);
    return (a *(d1 ^ d2))^Nim_Multi_Power(a/2, d1);
}
int Nim_Multi(int x, int y){
    if(x < y) swap(x, y);
    if(x < 2) return map[x][y];

    int i;
    for(i = 0; ; i++){
        if((1<<(1<<i)) > x) break;
    }
    int a = 1 << (1 <<(i-1));
    int p = x / a, q = x % a, s = y / a, t = y % a;
    int c1 = Nim_Multi(p, s);
    int c2 = Nim_Multi(p, t)^Nim_Multi(q, s);
    int c3 = Nim_Multi(q,t);
    return ((c1^c2)*a)^c3^Nim_Multi_Power(a/2, c1);
}
int main(){
    int n, m, x,  y, i, j, ans, TC;
    scanf("%d", &TC);
    while(TC--){
        scanf("%d", &n); ans = 0;
        for(i = 1; i <= n; i++){
            scanf("%d%d", &x, &y);
            ans ^=  Nim_Multi(x, y);
        }
        printf("%s\n", ans ? "Have a try, lxhgww." : "Don't waste your time.");
    }

}
