#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
#define LL __int64
#define N 100005
int s[N];
int a[N];
LL cnt;
void merge(int l, int m, int r)
{
	int l_1, l_2, pt = 0, i, j;
	l_1 = l; l_2 = m + 1;
	while(l_1 <= m && l_2 <= r){
		if(a[l_1] <= a[l_2])
		    s[pt++] = a[l_1++];
		else {
             s[pt++] = a[l_2++];
             cnt += m - l_1 + 1;
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
	LL k;
	while(scanf("%d%I64d",&n, &k) != EOF){

		cnt = 0LL;
		for(i = 0; i < n; i++)		scanf("%d",&a[i]);
		mergesort( 0, n -1);
		printf("%I64d\n", max( cnt - k , 0LL));
	}
	return 0;
}
