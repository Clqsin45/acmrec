#include <stdio.h>
#include <string.h>

int n, time[102][102], check[102];
int max, min;
int fl()
{
	int i, j, k, st;
	for(k = 1;k <= n; k++ ){
		for(i = 1; i <= n; i ++ ){
			for(j = 1; j <= n; j ++ ){
				if(time[i][j] > (time[i][k] + time[k][j]))
					time[i][j] = (time[i][k] + time[k][j]);
			}
		}
	}
	min = 2147483647;
	for(i = 1; i <= n; i++)
	{
		max = 0;
		for(j = 1; j <= n ; j ++){
			if(i != j && time[i][j] > max) max = time[i][j];
		}
        if(min > max) {
		min = max;
		st = i;
		}
	}

	return st;
}
int main(void)
{
	int i, j, t, s, ct, y;
	while (scanf("%d",&n)){
		if(n == 0) break;
		ct = 0 ;
		memset(check, 0, sizeof(check));
		memset(time, 44, sizeof(time));
		for(i = 1; i <= n; i++){
			scanf("%d", &t);
			if (t != 0 && check[i] == 0) {
				check[i] = 1;
				ct++;
			}
			for(j = 1; j <= t; j ++) {
				scanf("%d %d",&s, &y);
				time[i][s] = y ;
				if(check[s] == 0) {
					check[s] = 1;
					ct++;
				}
			}
		}
		if(ct != n) {
			printf("disjoint\n");
			continue;
		}
		printf("%d %d\n",fl(), min);
	}
	return 0;
}
