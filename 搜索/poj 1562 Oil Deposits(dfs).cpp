#include <stdio.h>
#include <string.h>

int visit[104][104]={{0}};
char f[104][104]={{'\0'}};
int gox[10]={0, -1, -1, -1, 0,  0,  1, 1, 1};
int goy[10]={0, -1,  0,  1, -1, 1, -1, 0, 1};

void dfs(int x, int y)
{
	visit[x][y] = 1;
	int xx, yy, i;

	for(i = 1;i <= 8;i ++)
	{
		xx = x + gox[i];
		yy = y + goy[i];
		if(f[xx][yy] == '@' && visit[xx][yy] == 0) dfs(xx,yy);
	}
	return ;
}
int main(void)
{
	int m, n, t;
	int i, j, count=0;
	scanf("%d",&t);
	while(t--){
        scanf("%d%d",&m, &n);
        
		count=0;
		memset(f,'\0',sizeof(f));
		memset(visit, 0, sizeof(visit));

		for(i = 1; i <= m; i ++) {
			scanf("%s",f[i]+1); 
			visit[i][0]=visit[i][n+1]=-1;
		}
		memset(visit[0],-1,sizeof(visit[0]));
		memset(visit[m+1],-1,sizeof(visit[m+1]));
		
		for(i = 1; i <= m; i ++){
			for(j = 1; j <= n; j ++){
				if(f[i][j]=='@'&&visit[i][j]==0) {
					dfs(i,j);
					count++;
				}
			}
		}
		printf("%d\n",count);

	}
	return 0;
}
