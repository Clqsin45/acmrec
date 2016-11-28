#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N  = 100005;
char s[N], t[N];


bool gao(){
    int i, j, n, m;
    n = strlen(s);  m = strlen(t);
    for(i = j = 0; i < n && j < m; i){
        if(s[i] == t[j]){i++; j++;}
        else j++;
    }
    return i == n;
}
int main(){
    while(scanf("%s%s", s, t) != EOF){
        printf("%s\n", gao() ? "Yes" : "No");
    }
    return 0;

}
