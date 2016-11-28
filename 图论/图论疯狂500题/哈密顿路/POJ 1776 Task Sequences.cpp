#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 1004
#define M
#define LL __int64
#define INF 0x3f7f7f7f
inline int scan_d() {
	char c;
	int ret=0;
	while((c=getchar())<'0'||c>'9');
	while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
int l[N], r[N], f[N][N];

int main(void)
{
    int n, i, j;
    while(scanf("%d", &n) != EOF){

        for(i = 1; i <= n; i++){
            for(j = 1; j <= n; j++){
                f[i][j] = scan_d();
            }
            f[0][i] = f[i][n + 2] = 1 ;
        }
        for(i = 0; i <= n; i++){
            r[i] = n + 2;
        }
        for(i = 1; i <= n; i++){
            for(j = 0; j != n + 2; j = r[j]){

                if(f[j][i]){
                    if(f[i][r[j]]){


                        l[i] = j;       r[i] = r[j];
                        l[r[j]] = i;    r[j] = i;   printf("%d %d %d %d %d %d\n", i, j, l[i], r[i], l[j], r[j]);
                        break;
                    }
                }
            }
        }
        printf("%d\n%d\n", 1, n);
        for(i = r[0]; i != n + 2; i = r[i]){
            printf("%d%c", i, r[i] == n + 2 ? '\n' : ' ');
        }
    }
    return 0;
}
