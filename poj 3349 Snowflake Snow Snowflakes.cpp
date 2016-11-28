#include <stdio.h>
#include <string.h>
int head[10002];
int flag;
struct ha{
	int next;        //指向的下一个同一个HASH值的雪花
	int edge[7];  //各个雪花的边长
}snow[10002];

void match(int com1, int com2, int node )
{
	int k, c; //顺时针 OR逆时针
	c = node;
	flag = 1;
	for (k = 1;k < 6; k++){
		c = (c+1) % 6 ;
		if(snow[com1].edge[k] != snow[com2].edge[c]) {
			flag = 0;
			break ;
		} //有一个不同 就出去
	}
	if(flag) return;
	c = node;
	flag = 0;
	for (k = 1;k < 6; k++){

		if((c - 1)< 0) c = 5;
		else c--;
		if(snow[com1].edge[k] != snow[com2].edge[c]) return;
	}
	flag =1; return;

}
void find(int hash, int n)
{
	int i, j;
	for(i = head[hash]; i!= -1; i = snow[i].next){
		for(j = 0 ; j < 6 ; j++){//找出匹配的一个长度
			if (snow[n].edge[0] == snow[i].edge[j]) {
				match(n, i, j);//匹配其余
			}
			if(flag) return ;//找到相同的了 返回
		}
	}
	//否则 连长
	snow[n].next = head[hash];
	head[hash] = n;
	return ;
}
int main(void)
{
	int t, n, i, p,tot;// t样例数  n雪花个数
	scanf("%d",&t);
	while(t--){
		tot = 1;
		scanf("%d",&n);
		// 清零
		memset(head, -1, sizeof(head));
        memset(&snow, 0, sizeof(snow));
        flag = 0;//有相同的
		while(tot<=n){
			p = 0;//判断哈希的
		
			for(i = 0; i < 6; i++){
				scanf("%d",&snow[tot].edge[i]);
				p += (snow[tot].edge[i]% 10000);
			}
			p = p%10000;//哈希值
			if(!flag){
				if (head[p] == -1) {//对应的值没有出现过
					head[p] = tot;
					snow[tot].next = -1;
				}
				else find(p, tot); //若出现过 在这条链上找相同的
			}
			tot++;
		}
				
		if(flag) //最后找到相同的了
			printf("Twin snowflakes found.\n");
		else printf("No two snowflakes are alike.\n");

 	}

	return 0;
}
