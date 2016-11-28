#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int d, t, l, n, i, h, max, min, s;
	scanf("%d",&t);
	while(t--){
		max = 0;
		scanf("%d %d", &l, &n);
		if(n == 0) {
			printf("0 0\n");
			continue;
		}
		min = 0;
		
		for(i = 0 ;i < n; i++){
			scanf("%d", &d);
			if ((d > (l-d)? d : (l-d) )> max)
				max = (d > (l-d)? d : (l-d));
			if(d > (l / 2)) d = l - d;
			if (d > min) min = d;
			
		}
		printf("%d %d\n", min, max);
	}
	return 0;
}
