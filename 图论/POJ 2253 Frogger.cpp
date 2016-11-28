#include <stdio.h>
#include <string.h>
#include <math.h>

int n;
int v[202];
double d[202],x[202], y[202];

double dist(int i, int j)
{
	return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

double dijkstra()
{
    int ct = 1, i, x = 1, st;
    double min, di;

	memset(v, 0 , sizeof(v));
	for(i = 2; i <= n; i++) d[i] = 100000000;
	d[1] = 0;
	while(ct != n){
		min = 100000000;
		for(i = 2; i <= n; i++){
			if(!v[i]) {
				di = dist(x, i);
				if(d[i] > (di > d[x] ? di: d[x]))  d[i] =  (di > d[x] ? di: d[x]);
/*????*/		if (min > d[i])  {
					min = d[i];
					st = i;
				}
			}
		}
		if (st == 2) return d[2];
		x = st;
		v[x] = 1;
		ct ++;
	}

	return d[2];
}

int main(void)
{
	int i, t = 1;
	while(scanf("%d",&n)){
		if( n == 0)  break;
		for( i = 1 ; i <= n; i ++) scanf("%lf %lf", &x[i], &y[i]);
		printf("Scenario #%d\n", t);
		printf("Frog Distance = %.3lf\n\n", dijkstra());
		t++;
	}
	return 0;

}
