#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100005
int f[N];
int main(void){
	int n, g, i, ans, x, y, no;
	while(scanf("%d%d", &n, &g) != EOF){
		ans = 0;	no = 0;
		for(i = 1; i <= n; i++){
			scanf("%d%d", &x, &y);
			if(x > y) ans += 3;
			else f[++no] = y - x;
		}
		sort(f + 1, f + no + 1);
		for(i =1; i <= no && g > 0; i++){
			if(f[i] == 0) {
				g--;
				ans += 3;
			}
			else {
				if(f[i] > g) break;
				else if(f[i] == g) {
					ans ++;	g -= f[i];
				}
				else {
					ans += 3;
					g -= (f[i] + 1);
				}
			}
		}
		for(; i <= no; i++){
			if(f[i] == 0) ans ++;
			else break;
		}
		printf("%d\n", ans);
	}
	return 0;
}

