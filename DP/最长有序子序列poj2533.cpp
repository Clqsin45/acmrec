#include <stdio.h>
#include <string.h>
int a[1002], f[1002];

int main(void)
{
	int n, i, j, max;
	while(scanf("%d",&n)!=EOF){
		memset(f, 0 ,sizeof(f));
		for(i = 0; i < n; i++) scanf("%d", &a[i]);
		f[n - 1] = 1;
		max = 0;
		for(i = (n - 2); i >= 0; i --){
			max = 0;
			for( j = (n - 1); j > i; j --){
    			if(a[i] < a[j] && f[j] > max) {
					max = f[j];
				}
			}
			f[i] = max + 1;
		}
		max = 0;
		for(i = (n - 1); i >= 0; i --){
			if(f[i] > max) max = f[i];
		}
		printf("%d\n", max);
	}
	return 0;
}
