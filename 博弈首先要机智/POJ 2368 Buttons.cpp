#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n, m, i, j, ans;
    bool gg;
    while(scanf("%d", &n) != EOF){
        gg = true;
        m = (int)sqrt((double)n) + 1;
        for(i = 3; i <= m; i++){
            if(n % i)   continue;
            printf("%d\n", i - 1);
            gg = false;     break;
        }
        if(gg)  {
            if(n % 2 || n == 4)  printf("%d\n", n - 1);
            else printf("%d\n", n / 2 - 1 );
        }
    }
    return 0;
}
