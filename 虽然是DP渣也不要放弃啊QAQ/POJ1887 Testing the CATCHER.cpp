#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N  = 100004;
const int M = 32800;

int dp[M], a[N], ans;

int find(int x){
    int low = 0, high = ans, mid;
    while(low <= high){
        mid = (low + high) >> 1;
        if(dp[mid] == x)  return mid;
        if(dp[mid] < x) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}
int main(){
    int n, temp, i, j, tc = 0;
    n = 0;
    while(scanf("%d", &a[++n])){
        if(a[n] == -1)  break;
        if(tc)  printf("\n");
        while(scanf("%d",&a[++n])){
            if(a[n] == -1)  {
                --n;    break;
            }
        }
        dp[0] = 0;
        ans = 0;
        for(i = 1; i <= n; i++){
            temp = find(a[i]);
            dp[temp] = a[i];
            if(ans < temp)    ans = temp;
        }
        printf("Test #%d:\n  maximum possible interceptions: %d\n", ++tc, ans+1);
        n = 0;
    }
    return 0;
}
