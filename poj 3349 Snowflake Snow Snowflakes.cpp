#include <stdio.h>
#include <string.h>
int head[10002];
int flag;
struct ha{
	int next;        //ָ�����һ��ͬһ��HASHֵ��ѩ��
	int edge[7];  //����ѩ���ı߳�
}snow[10002];

void match(int com1, int com2, int node )
{
	int k, c; //˳ʱ�� OR��ʱ��
	c = node;
	flag = 1;
	for (k = 1;k < 6; k++){
		c = (c+1) % 6 ;
		if(snow[com1].edge[k] != snow[com2].edge[c]) {
			flag = 0;
			break ;
		} //��һ����ͬ �ͳ�ȥ
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
		for(j = 0 ; j < 6 ; j++){//�ҳ�ƥ���һ������
			if (snow[n].edge[0] == snow[i].edge[j]) {
				match(n, i, j);//ƥ������
			}
			if(flag) return ;//�ҵ���ͬ���� ����
		}
	}
	//���� ����
	snow[n].next = head[hash];
	head[hash] = n;
	return ;
}
int main(void)
{
	int t, n, i, p,tot;// t������  nѩ������
	scanf("%d",&t);
	while(t--){
		tot = 1;
		scanf("%d",&n);
		// ����
		memset(head, -1, sizeof(head));
        memset(&snow, 0, sizeof(snow));
        flag = 0;//����ͬ��
		while(tot<=n){
			p = 0;//�жϹ�ϣ��
		
			for(i = 0; i < 6; i++){
				scanf("%d",&snow[tot].edge[i]);
				p += (snow[tot].edge[i]% 10000);
			}
			p = p%10000;//��ϣֵ
			if(!flag){
				if (head[p] == -1) {//��Ӧ��ֵû�г��ֹ�
					head[p] = tot;
					snow[tot].next = -1;
				}
				else find(p, tot); //�����ֹ� ��������������ͬ��
			}
			tot++;
		}
				
		if(flag) //����ҵ���ͬ����
			printf("Twin snowflakes found.\n");
		else printf("No two snowflakes are alike.\n");

 	}

	return 0;
}
