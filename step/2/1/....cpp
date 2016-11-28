# include <stdio.h>
# include <math.h>
int main()
{
	__int64 n,y,p;
	int su(__int64 x);
	while(scanf("%I64d",&n)!=EOF)
	{
		p=0;
		while(n--)
		{
			scanf("%I64d",&y);
			if(su(y)==0)
			{
				p++;
			}
		}
		printf("%I64d\n",p);
	}
	return 0;
}

int su(__int64 x)
{
	__int64 t=0,i;
	for(i=2;i<=sqrt(x);i++)
	{
		if(x%i==0)
		{
			t++;
			break;
		}
	}
	if(t==0)
		return 0;
	else
		return 1;
}
