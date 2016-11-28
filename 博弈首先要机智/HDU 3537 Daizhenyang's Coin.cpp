#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
map<int, bool>hehe;

bool countnumber(int x){
    int temp = 0;
    while(x){
        temp ^= (x&1);
        x >>= 1;
    }
    return 1^temp;
}
int main(){
    int n, i, j, ans;
    while(scanf("%d", &n) != EOF){
        ans = 0;
        hehe.clear();
        for(i = 1; i <= n; i++){
            scanf("%d", &j);
            if(hehe[j]) continue;
            hehe[j] = true;
            ans ^= (2*j+countnumber(j));
        }
        printf("%s\n", ans ? "No" : "Yes");
    }
}
