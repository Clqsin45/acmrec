#include <stdio.h>
struct thing{
	double value;
	int v;
}t[1000004];

void swap(int x, int y)
{
	int temp;
	float te;
	te = t[x].value;
	t[x].value = t[y].value;
	t[y].value = te;
	temp = t[x].v;
	t[x].v = t[y].v;
	t[y].v = temp;
}

void qsort(int left,int right)
{
	int j,last;

	if(left>=right) {
		return;
	}

	swap(left,(left+right)/2);

	last=left;	

	for(j=left+1;j<=right;j++){

		if((t[j].value)/t[j].v<(t[left].value)/t[left].v) {
			swap(++last,j);
		}

	}
	swap(left,last);
	qsort(left,last-1);
	qsort(last+1,right);
	return ;
}

int main(void)
{
	int m, n, i, sum_v;
	double sum_value;
	while(scanf("%d %d", &n, &m) == 2){
		sum_v =  0;
		sum_value = 0.0;
		i = n;
		while(i -- ){
			scanf("%lf %d", &(t[i].value), &(t[i].v));
		}
		qsort(0 , n-1);
		
		for(i = (n - 1 );; i--){
			if(t[i].v<=(m-sum_v)) {
				sum_v +=t[i].v;
				sum_value += t[i].value;
			}
			else {
				sum_value += (1.0*(m-sum_v))/t[i].v*t[i].value;
                break;
			}
		}
		printf("%.3lf\n",sum_value);
		
	}
	return 0;
	
}
