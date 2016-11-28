#include <stdio.h>
int n, count = 0, a[10002];
void swap(int x, int y)
{
	int temp;
	temp = a[x];   a[x] = a[y];		a[y] = temp;
	return ;
}

void build(int x)
{
	int i;
	if( (x * 2 + 1) <= n){
		if(a[x * 2] <= a[x * 2 + 1]) i = x * 2;
		else i = x * 2 + 1;
	}
	else i = x * 2;
	
	if(a[i] < a[x] ) {
		swap(i,x);
		if (i * 2 <= n) build (i);
	}
	return ;
}

void find()
{
	int x, y;
	while(n > 1){
		x = a[1];
		a[1]  = a[n];
		n -- ;
		if (a[2] != 0)
			build(1);
		y = a[1];
		count += (x + y);
		a[1] = x+y;
		if(a[2] != 0)  build(1);

	}

}

int main(void)
{
	int i;
	scanf("%d",&n);
	for(i = 1; i <= n; i++){
		scanf("%d",&a[i]);
	}
	for(i = (n / 2); i >= 1; i--)   build(i);
	if (n == 1) count = a[1];
	else find();
	
	printf("%d\n",count);
	return 0;
}
