#include <stdio.h>
int f[1000004];
int s[1000004];
int a[1000004];

int main (void)
{
	int i, j, m, n, length , max ,flag, temp = 0;
	long long int x;
	while(scanf("%d%d", &m, &n) != EOF){
		max = 0;  		flag =0;
		if(m>n){
			temp = m;
			m = n;
			n = temp;
		}
		for(i = m; i <= n; i++){
			x = i;
			length = 0;
			flag = 0;

			while(x != 1){
				if(x<1000000){
					a[length] = x;
					s[x] = length;
				}
				if(x<1000000 && f[x] != 0) {
					f[i] = length + f[x];
					flag = 1;
					break;
				}
				if(x % 2 == 1) x = (3 * x+ 1);
				else x = x / 2;
				length++;
				
			}
			if(!flag) f[i]= length;
			if (f[i] > max) max = f[i];
			for(j=0;j<length;j++)
			    f[a[j]] = f[i] - s[a[j]];
		}
		if(temp > 0) printf("%d %d %d\n", n, m, max+1);
		else printf("%d %d %d\n", m, n, max+1);
	}
	
	return 0;
}
