#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 40004;

char s[N];
int n, m;
int cal(int x, int y) {
    return (x-1)*m+y;
}

void gao(int pos){
    pos --;
    int x = pos / m + 1;
    int i;
    for(i = pos % m + 1 + x; i <= m; i+= x) {
        s[cal(x, i)] = 'H';
    }
    int y = pos % m + 1;
    for(i = pos / m + 1 + y; i <= n; i+= y)
        s[cal(i, y)] = 'H';
}
int main(){
    int tc = 0, i, j, k;
    while(scanf("%d%d", &n, &m) != EOF){
        memset(s, 0, sizeof(s));

        for(i = 1; i <= n * m; i++){
            if(s[i] == 'H') continue;
            s[i] = 'P';
            gao(i);
        }
        printf("Case #%d:\n", ++tc);
        k = 1;
        for(i = 1; i <= n; i++){
            for(j = 1; j <= m; j++)
                printf("%c", s[k++]);
            printf("\n");
        }
    }
    return 0;
}
