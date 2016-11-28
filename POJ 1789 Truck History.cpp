#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//PRIMEµÄÓÅ»¯
char c[2002][8];
int n, d[2002][2002], v[2002], low[2002];

int dif(int x , int y)
{
	int i, sum = 0;
	for(i = 0; i < 7; i++)
	    if (c[x][i] != c[y][i]) sum++;
	    
	return sum;
}

int pr()
{
	int i, x, sum = 0 , min, st, ct = 1;
	memset(low, 44, sizeof(low));
	memset(v, 0, sizeof(v));
	v[1] = 1;   st = 1;
	while(ct != n){
		min = 100000000;
		for( i = 2; i <= n; i++)
		{
			if(!v[i] && low[i] > d[st][i]) low[i] = d[st][i];
			if(!v[i] && min > low[i]) {
				min = low[i];
				x = i;
			}
		}
		if(min  == 100000000) break;
		v[x] = 1;
		st = x;
		ct++;
		sum += min;
	}
	return sum;

}
int main(void)
{
	int i, j;
	while(scanf("%d",&n)){
		if(n == 0) break;
		for(i = 1; i <= n; i ++) scanf("%s", &c[i]);
		for(i = 1; i <= n; i++){
			for(j = (i + 1); j <= n; j++){
				d[i][j] = d[j][i] = dif(i, j);
			}
		}
		printf("The highest possible quality is 1/%d.\n", pr());
	}
	system("pause");
	return 0;
}
