#include <stdio.h>
#include <string.h>
int cl[10002];
int node[10000];
int n, m, flag;

struct line{
	int nextl;
	int nextn;
}l[100002];

void dfs(int u, int color)
{
	int i,v;
	for(i = node[u]; i!=(-1); i = l[i].nextl){
		v = l[i].nextn;
		if(cl[v] != 0){
			if(cl[v] != color) {
				flag = 1;
				return ;
			}
			else return ;
		}
		else {
			cl[v] = color;
			dfs(v,(color>1?1:2));
		}
	}
}
int main(void)
{
	int i, c1, c2, s;
	while(scanf("%d", &n)&&n){  //µã
		memset(cl,0, sizeof(cl));
		memset(node, -1, sizeof(node));
		flag = 0;
		s = 0;
		scanf("%d", &m);   //Ïß
		for(i = 0; i < m; i++) {
			scanf("%d%d", &c1, &c2);
			s++;
			l[s].nextn=c2;
			l[s].nextl = node[c1];
			node[c1] = s;
		}
		dfs(0,1);
		if(flag) printf("NOT BICOLORABLE.\n");
		else printf("BICOLORABLE.\n");
	}
	return 0;
}
