#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){

    int n, k, TC, temp;
    scanf("%d", &TC);
    while(TC--){
        scanf("%d%d", &n, &k);
        if(k & 1){
            printf("%d\n", n & 1);
        }
        else{
            temp = n % (k + 1);
            if(temp == k)   printf("%d\n", k);
            else printf("%d\n", temp & 1);
        }
    }
    return 0;
}
