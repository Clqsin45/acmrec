#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[3004],d[3004];
int main(void)
{
	int t, n, i, flag;
	scanf("%d", &t);
	while (t--){
		scanf("%d",&n);
		scanf("%d",&a[0]);
		if(n == 1) {
			printf("Jolly\n");
			continue;
		}
		memset(d,0,sizeof(d));
		flag = 0;
		for(i = 1; i < n; i++){
			scanf("%d",&a[i]);
			if(!flag){
				if(abs(a[i]-a[i-1])>(n-1)) flag = 1;
				else if (a[i] == a[i-1]) flag = 1;
				else if (d[abs(a[i]-a[i-1])] == 1) flag = 1;
				else d[abs(a[i]-a[i-1])] = 1;
			}
		}
		if(flag) printf("Not jolly\n");
		else printf("Jolly\n");
	}
	return 0;
}
