#include <stdio.h>
int a[500004], s[500004];
long long int count;
void merge(int l, int m, int r)
{
	int l_1, l_2, pt = 0, i, j;
	l_1 = l; l_2 = m + 1;
	while(l_1 <= m && l_2 <= r){
		if(a[l_1] <= a[l_2])
		    s[pt++] = a[l_1++];
		else {
             s[pt++] = a[l_2++];
             count += m - l_1 + 1;
		}
	}
	while (l_1 <= m)   s[pt++] = a[l_1++];
	while (l_2 <= r)   s[pt++] = a[l_2++];
	for(i = l, j = 0; i<=r; i++, j++)  a[i] = s[j];
	
}

void mergesort(int l, int r)
{
	if (l >= r) return ;
	int m = (l + r) / 2;
	mergesort(l, m);
	mergesort(m + 1, r);
	merge(l, m, r);
	return ;
}
int main(void)
{
	int n, i;
	while(scanf("%d",&n)){
		if(n == 0) {
			return 0;
		}
		count = 0;
		for(i = 0; i < n; i++)		scanf("%d",&a[i]);
		mergesort( 0, n -1);
		printf("%lld\n", count);
	}
	return 0;
}
