#include <stdio.h>
int stack[15004];
int main(void)
{
	int t, n, i, j, top, in, flag, sign, x;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		stack[0] = 0;
		top = 1;
		x = 1;
		stack[top] = x;
		flag = 1;
		i = n;
		while(i--){
			scanf("%d", &in);
			while(stack[top] != in){
				if(x > n) {
					flag = 0;
					break;
				}
				else stack[++top] = (++x);
			}
			top--;

		}
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;

}
