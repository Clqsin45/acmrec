#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 204;
char mp[N][N], ch[N];

int main(){
    int n, m, i, j, k;
    while(scanf("%d", &n) && n){
        scanf("%s", ch);
        m = strlen(ch); k = 0;
        for(i = 1; k < m; i++){
            if(i & 1){
                for(j = 1; j <= n ;j++){
                    mp[i][j] = ch[k++];
                }
            }
            else {
                for(j = n ; j >= 1; j--)
                    mp[i][j] = ch[k++];
            }
        }
        m = i-1;
        for(i = 1; i <= n; i++){
            for(j = 1; j <= m; j++) printf("%c", mp[j][i]);
        }
        printf("\n");
    }
    return 0;
}
