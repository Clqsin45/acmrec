#include <stdio.h>
#include <string.h>
#include <math.h>

double x[102], y[102], d[102][102];
int v[102], s[102], n;

double cal(int i, int j)
{
	return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}
double pr()
{
	int i, j, ct = 1, st;
	double min, sum = 0;
	memset(v, 0 , sizeof(v));
	memset(s, 0 , sizeof (s));
	v[1] = 1; s[1] = 1;
	while(ct != n){
		min = 10000000;
		for(i = 1; i <= ct; i++)
		{
			for(j = 1; j <= n; j++){
				if(!v[j] && d[s[i]][j] < min){
					min = d[s[i]][j];
					st = j;
				}
			}
		}
		v[st] = 1;
		s[++ct] = st;
		sum += min;
	}
	return sum;
}
int main(void)
{
	int t, i, j;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for( i = 1; i <= n ; i ++){
			scanf("%lf%lf", &x[i], &y[i]);
		}
		for( i = 1; i <= n; i ++)
		    for( j = i ; j <= n ; j++) d[i][j] = d[j][i] = cal (i, j);
		printf("%.2lf\n",pr());
       	if(t) printf("\n");
	}
	return 0;
}
