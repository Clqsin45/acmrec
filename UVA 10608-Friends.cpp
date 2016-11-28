#include <stdio.h>
#define MAX 30010


int f[MAX], count[MAX];
int find(int x)
{
	if (f[x] == x) return x;
	else return (f[x] = find(f[x]));
}

void build(int x, int y)
{
	x = find(x);    y = find(y);
	if(x == y) return;
	else{
		f[y] = x;
		count[x] += count[y];
	}
	return;

}

int main(void)
{
	int x, y, t, m, n, i, max;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d", &m, &n);
		for(i = 1; i <= m; i++){
			f[i] = i;
			count[i] = 1;
		}
		
		while(n--){
			scanf("%d%d",&x, &y);
			build(x, y);
		}
		
		max = 0;
		for(i = 1; i <= m; i++){
			if (count[i] > max) max = count[i];
		}
		
		printf("%d\n",max);
	}

	return 0;
}
