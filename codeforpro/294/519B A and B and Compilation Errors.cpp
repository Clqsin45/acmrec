#include <bits/stdc++.h>
using namespace std;
const int N = 100004;
int a[3][N];

int main(){
    int i, j, n, ans;
    scanf("%d", &n);
    for(j = 0; j < 3; j++)
        for(i = 0; i < n-j; i++)
            scanf("%d", &a[j][i]);
    sort(a[0], a[0] + n);
    sort(a[1], a[1] + n - 1);
    sort(a[2], a[2] + n - 2);
    a[1][n-1] = 0;  a[2][n-2] = 0;
    for(i = 0; i < n; i++){
        if(a[0][i] != a[1][i])  {
            printf("%d\n", a[0][i]);
            break;
        }
    }
    for(i = 0; i < n-1; i++){
        if(a[1][i] != a[2][i]){
            printf("%d\n", a[1][i]);
            break;
        }
    }
}
