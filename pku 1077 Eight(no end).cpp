#include <stdio.h>
#include <stdlib.h>
int a[5][5];
int main(void)
{
	int t, i , j;
	char ch;
	scanf("%d",&t);
	while(t--){
		for(i = 1; i <=3; i++){
			for(j = 1; j <=3 ; j++)
			{
				scanf("%c",&ch);
				if(ch == 'X') a[i][j] = 0;
				else a[i][j] = ch -48;
			}
		}
		
		
	}

}
