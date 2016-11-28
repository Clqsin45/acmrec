#include <stdio.h>
#include <string.h>
char m[22][22];
int visit[22][22];
int gox[4] = {-1, 0, 1, 0}, goy[4]={0, -1, 0, 1};
int ans = 0;
void dfs(int x, int y)
{
	int i;
	visit[x][y] = 1;
	ans++;
	for(i=0 ; i < 4 ; i++){
		if( m[x + gox[i]][y + goy[i]] == '.' && visit[x + gox[i]][y + goy[i]] == 0){
		    dfs(x + gox[i],y + goy[i]);
		}
	}
}
int main(void)
{
	int t, w, h, i ,j;
	scanf("%d",&t);
	
	while(t--){
		ans = 0;
		scanf("%d%d", &w, &h);
		memset(visit,0,sizeof(visit));
		memset(visit[0], -1, sizeof(visit[0]));
		memset(visit[h+1], -1, sizeof(visit[h+1]));
		memset(m, '\0', sizeof(m));
		for(i = 1; i <= h; i++){
			scanf("%s",m[i]+1);
			visit[i][0] = visit[i][w+1] = -1;
		}
		for(i = 1; i <= h; i ++){
			for(j = 1; j<= w; j++)
			    if ( m[i][j] == '@') dfs(i, j);
		}
		printf("%d\n", ans);
	}
	return 0;
}
