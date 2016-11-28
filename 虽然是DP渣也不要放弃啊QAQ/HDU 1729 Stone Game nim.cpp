#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;


const int N = 1000004;
typedef __int64 ll;
int  c;

int cal(int x){
    int y = sqrt(1.0*x) + 1;
    while(y*y+y>=x)  {
        y--;
    }

    return c > y ? x-c:cal(y);
}

int main(){
    int n, m,s,  tc = 0;
    while(scanf("%d", &n) && n){
        printf("Case %d:\n", ++tc);
        int ans = 0;
        while(n--){
            scanf("%d%d", &s, &c);
            if(c == 0)  continue;
            ans^=cal(s);
         //   printf("%d\n", ans);
        }
        printf("%s\n", ans ? "Yes" : "No");
    }
    return 0;
}
