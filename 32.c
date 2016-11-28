#include <stdio.h>
#include <string.h>

int d[100004] = {0};
int que[200004] = {0};
int bfs(int m, int n)
{
	int front = 1, rear = 1, x;
	d[m] = 0;
	que[1] = m;
	x = m;
	while ( front <= rear){
		if( ((x-1) >= 0) && ( d[x-1] ==0 )&&(x-1!=m)){
			que[++rear] = (x-1);
			d[x-1]=d[x]+1;
			if( x-1 == n) break;

		}
		if( (x+1) <=100110 && d[x+1] == 0&&(x+1!=m))
		{
			que[++rear]=x+1;
			d[x+1]= d[x]+1;
			if( x+1 == n) break;
		}
		if (2*x <= 100110 && d[2*x] == 0&&(2*x!=m))
		{
			que[++rear]= 2*x;
			d[2*x]=d[x]+1;
			if( 2*x==n) break;
		}
		front++;
		x=que[front];
	}
	return d[n];
}

int main(void)
{
	int m, n;

		scanf("%d %d", &m, &n);
		printf("%d\n",bfs(m, n));
	system("pause");
	return 0;
}
