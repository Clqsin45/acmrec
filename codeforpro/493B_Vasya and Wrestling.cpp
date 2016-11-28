#include <bits/stdc++.h>
using namespace std;

#define N 200004
#define LL __int64
int a[2][N];


int main(void){
    int x, i, n, last, ta = 0, tb = 0;
    int gg = -1;
    LL sum = 0LL;

    scanf("%d", &n);
    while(n--){
        scanf("%d", &x);
        sum += x;
        if(x < 0){
            a[1][++tb] = -x;
        }
        else a[0][++ta] = x;
        last = x;
    }
    if(sum < 0) gg = 1;
    else if(sum > 1) gg = 0;
    else{
        for(i = 1; i <= ta || i <= tb; i++){
            if(a[1][i] == a[0][i]) continue;
            if(a[1][i] < a[0][i]) gg = 0;
            else gg = 1;
            break;
        }
        if(gg == -1){
            gg = (last < 0);
        }
    }
    printf("%s\n", gg ? "second" : "first");
    return 0;
}
