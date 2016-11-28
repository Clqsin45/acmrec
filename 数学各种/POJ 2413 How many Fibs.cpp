#include <stdio.h>
#include <string.h>

int f[600][150], l[600];
char a[600], b[600];

int cmp(char *s, int k)
{
	int e, i;
	e = l[k];
	for(i = e; i >= 0; i--)
	{
		if(f[k][i] < (s[i] - '0'))
		    return -1;
		if(f[k][i] > (s[i] - '0'))
		    return 1;
	}
	return 0;
}
int main(void)
{
	int i, j, m, sign = 0, t, ct, qa, qb, lb, la, p;
	f[0][0] = 1;    l[1] = 0;
	f[1][0] = 2;    l[2] = 0;
	m = 0;
	for(i = 2; i <= 500; i++)
	{
		sign = 0;
		for(j = 0; j <= m; j++)
		{
			f[i][j] = f[i - 1][j] + f[i - 2][j] + sign;
			sign = f[i][j] / 10;
			f[i][j] %= 10;
		}
		if(sign)
		{
			f[i][++m] = sign;
		}
		l[i] = m;
	}
	
	
	while(scanf("%s%s",a, b))
	{
		ct = 0;
		if(strcmp(a, "0") == 0 && strcmp(b, "0") == 0)  break;
		la = strlen(a); lb = strlen(b);
		strrev(a);  strrev(b);
		
		for(i = 0; i <=500; i++)
		{
			 t = i;
			 if(l[t] + 1> lb)   break;
			 if(l[t] + 1< la)  continue;
		
			 qa = cmp(a, t);
			 qb = cmp(b, t);	 
			if((l[t] + 1==lb) && qb>0)
       			break;
   			if((l[t] + 1==la) && qa<0)
      			continue;
			ct ++;
		}
		printf("%d\n", ct);
	}
}

