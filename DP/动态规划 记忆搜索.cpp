#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	int a[10][10],d[10][10];
int def(int i,int j)
{
	if(d[i][j]>=0) return d[i][j];
	return d[i][j]=a[i][j]+(i == 4 ? 0 : def(i+1,j)>? def(i+1,j+1));
}
int main(void)
{

	int i,j;
	memset(d,-1,sizeof(d));
	for(i=1;i<=4;i++)
	    for(j=1;j<=i;j++)
	        scanf("%d",&a[i][j]);

	d[1][1]=def(1,1);
	
	printf("%d",d[1][1]);
	system("pause");
	return 0;

}
