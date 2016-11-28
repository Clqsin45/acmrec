#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

/*******************
11.4 = 奇。即找下一步为奇数的。
走一步会把偶数变奇数 故所有偶数日
特别的。9.30和11.30 下一步10.1和12。1也是奇数
*******************/
int main(){
    int TC, i, j, n, m, y;
    scanf("%d", &TC);
    while(TC--){
        scanf("%d%d%d", &y, &n, &m);
        if((n+m)%2==0 ||( (n==11 || n == 9)&&m==30)){
            printf("YES\n");
        }
        else printf("NO\n");
    }
}
