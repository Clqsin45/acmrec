#include <bits/stdc++.h>
using namespace std;
const int N = 105;
char a[N], b[N];

int main(){
    scanf("%s%s", a, b);
    if(strcmp(a, b) == 0){
        printf("%s\n", a);
    }else printf("%d\n", 1);
    return 0;
}
