#include <stdio.h>
#include <string.h>
char x[1002], y[1002];
int f[1002][202];

int main(void)
{
	int i, j, max, lx, ly, s = 0;
	while(scanf("%s%s",x+1,y+1) == 2){
		s = 0;
		f[0][0] = f[1][0] = f[0][1] = 0;
		lx = strlen(x+1);     ly = strlen(y+1);
		for(i = 1; i <= lx; i++){
			for(j = 1; j <= ly; j++)
			{
				max = (f[i - 1][j] > f[i][j - 1] ? f[i - 1][j] : f[i][j - 1]);
				if ((f[i - 1][j - 1] + 1) * (x[i] == y[j]))
					max = (f[i - 1][j - 1] + 1) * (x[i] == y[j]);
				f[i][j] = max;
				if (max > s) s = max;
			}
		}
		printf("%d\n",s);
	}
	return 0;
	
}
