#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a[10002],ans = 0, i, t, n;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		ans = 0;
		for(i = 0; i < n; i++){
			scanf("%d",&a[i]);
			ans = (ans ^ a[i]);
		}

		printf("%d\n",ans);
	}
	
	system("pause");
	return 0;
}
