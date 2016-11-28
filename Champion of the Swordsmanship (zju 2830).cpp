#include <stdio.h>

int main(void)
{
	long long int x;
	int n;
	while(scanf("%lld",&x)==1 && x)
	{
		n = 0;
		while(x >= 3){
			n += x/3;
			x = (x - (x / 3)* 3 + x / 3);
		}
	    if(x != 1) n++;
		printf("%d\n",n);
	}
	return 0;
	
}
