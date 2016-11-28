#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int n, m;
    //看小的控制在谁手里
    while(scanf("%d%d", &n, &m) &&(n || m)){
        printf("%s\n",  (n & 1)&&(m&1) ? "What a pity!":"Wonderful!");
    }
    return 0;
}
