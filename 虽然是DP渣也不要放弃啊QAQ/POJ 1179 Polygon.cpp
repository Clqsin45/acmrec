#include<cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 104;
const int INF = 0x3f3f3f3f;
int f[N][N], g[N][N], num[N];
bool op[N], visf[N][N], visg[N][N];
vector<int>ans;
int findmin(int left, int right);

int findmax(int left, int right){
    if(visf[left][right])   return f[left][right];
    visf[left][right] = true;
    if(right - left <= 1){
     //   printf("%d %d\n", left, right);
        if(left == right)  {
             f[left][right] = num[left];   //printf("!!%d\n", f[left][right]);
            return f[left][right] ;
        }
        else if(op[right]) {
             f[left][right] = num[left]*num[right]; //  printf("!!%d %d %d\n",num[left],num[right] ,f[left][right]);
            return f[left][right] ;
        }
        else {
             f[left][right] = num[left]+num[right];  // printf("!!%d\n", f[left][right]);
            return f[left][right] ;
        }
    }

    int i, leftmax, leftmin, rightmax, rightmin;
    for(i = left; i < right; i++){
        leftmax = findmax(left, i);
        rightmax = findmax(i + 1, right);
        if(!op[i+1]){
            f[left][right] = max(f[left][right], leftmax+rightmax);
            continue;
        }
        //else f[left][right] = max(f[left][right], leftmax * rightmax);
        leftmin = findmin(left, i);
        rightmin = findmin(i + 1, right);
        f[left][right] = max(f[left][right],
                             max(max(leftmax*rightmax, leftmin* rightmin),
                                max(leftmin*rightmax, leftmax*rightmin)));
    }
   // printf("%d %d %d \n", left,right, f[left][right]);
    return f[left][right];
}

int findmin(int left, int right){
    if(visg[left][right])   return g[left][right];
    visg[left][right] = true;
    if(left >= right - 1){
        if(left == right) return g[left][right] = num[left];
        else if(op[right]) return g[left][right] = num[left]*num[right];
        else return g[left][right] = num[left] + num[right];
    }

    int i, leftmax, leftmin, rightmax, rightmin;
    for(i = left; i < right; i++){

        leftmin = findmin(left, i);
        rightmin = findmin(i + 1, right);
        if(!op[i+1]){
            g[left][right] = min(g[left][right], leftmin+rightmin);
            continue;
        }
        leftmax = findmax(left, i);
        rightmax = findmax(i + 1, right);
        g[left][right] = min(g[left][right],
                             min(min(leftmax*rightmax, leftmin*rightmin),
                                min(leftmin*rightmax, leftmax*rightmin)));
    }

    return g[left][right];

}
int main(){
    int n, i, j;
    char ch[10];

    while(scanf("%d", &n) != EOF){
        for(i = 1; i <= n; i++){
            scanf("%s%d", ch, &num[i]);
            num[i+n] = num[i];
            op[i] = op[n+i] = (ch[0] == 'x');
        }

        memset(visf, false, sizeof(visf));
        memset(visg, false, sizeof(visg));
        memset(f, 0xbf, sizeof(f));
        memset(g, 0x3f, sizeof(g));
        //printf("%d %d\n", f[0][0], temp);
        int maxn = -INF;
        for(i = 1; i <= n; i++){
            int temp = findmax(i, i + n - 1);
            if(temp > maxn){
                ans.clear();
                ans.push_back(i);
                maxn = temp;
            }
            else if(temp == maxn) ans.push_back(i);
           // printf("%d %d\n", i, temp);
        }
//
//        for(i = 1; i <= n; i++){
//            printf("%d\n", g[i][i+1]);
//        }
        printf("%d\n", maxn);
        n = ans.size();
        for(i = 0; i < n; i++){
            printf("%d%c", ans[i], i == n-1?'\n' : ' ' );
        }
    }

}
