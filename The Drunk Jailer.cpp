#include <stdio.h>
#include <string.h>
int main(void)
{
	int t, n, i, j, ce[102]={0}, count=0;
	scanf("%d", &t);
	while (t--){
		scanf("%d",&n);
		if(n == 0) {
			printf("0\n");
			continue;
		}
		memset(ce,0,sizeof(ce));
		for(i = 1; i <= n; i ++){
			for(j = 1; j <= (n / i); j ++){
				ce[i * j]=(ce[i * j] + 1) % 2;
			}
		}
		for(i = 1; i <= n; i++)
		    count += ce[i];
		printf("%d\n", count);
		count = 0;

	}
	return 0;
}
