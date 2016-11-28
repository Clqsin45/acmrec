#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
#define N 205
#define M 100005
#define INF 0x3f3f3f3f

using namespace std;

int head[N], cur[N], d[N], st[M], s, e, no,dis[N][N],k,c,m;

void floyd()
{
	for(int s=1;s<=k+c;s++)
	{
		for(int i=1;i<=k+c;i++)
		{
			for(int j=1;j<=k+c;j++)
			{
				dis[i][j]=min(dis[i][s]+dis[s][j],dis[i][j]);
			}
		}
	}
}

struct point{
	int u, v, flow, next;
	point(){};
	point(int x, int y, int z, int w):u(x), v(y), next(z), flow(w){};
}p[M];

void add(int x, int y, int z){
	p[no] = point(x, y, head[x], z);	head[x] = no++;
	p[no] = point(y, x, head[y], 0);	head[y] = no++;
}
void init(){
	memset(head, -1, sizeof(head));
	no = 0;
}

bool bfs()
{
    int i, x, y;
    memset(d, -1, sizeof(d));
    queue<int>q;
    q.push(s);  d[s] = 0;
    while(!q.empty())
    {
        x = q.front();  q.pop();
        for(i = head[x]; i != -1; i = p[i].next)
        {
            if(p[i].flow && d[y = p[i].v] < 0)
            {
                d[y] = d[x] + 1;
                if(y == e)  return true;
                q.push(y);
            }
        }
    }
    return false;

}
int dinic()
{
    int i, x = s, y, nowflow, maxflow = 0, top, loc;
    while(bfs())
    {
        //printf("%d\n", maxflow);
        for(i = s; i <= e; i++) cur[i] = head[i];
        top = 0;
        while(true)
        {
            if(x == e)
            {
                nowflow = INF;
                for(i = 0; i < top; i++)
                {
                    if(p[st[i]].flow < nowflow)
                    {
                        nowflow = p[st[i]].flow;
                        loc = i;
                    }
                }
                for(i = 0; i < top; i++)
                {
                    p[st[i]].flow -= nowflow;
                    p[st[i] ^ 1].flow += nowflow;
                }
                maxflow += nowflow;
                top = loc;  x = p[st[top]].u;
            }
            for(i = cur[x]; i != -1; i = p[i].next)
                if(p[i].flow && d[p[i].v] == d[x] + 1)  break;
            cur[x] = i;
            if(i != -1)
            {
                st[top++] = i;
                x = p[i].v;
            }
            else
            {
                if(!top)    break;
                d[x] = -1;
                x = p[st[--top]].u;
            }
        }
    }
    return maxflow;
}
void solve()
{
	int l,r,mid,ans;
	for(int i=1;i<=k+c;i++)
	{
		for(int j=1;j<=k+c;j++)
		{
			scanf("%d",&dis[i][j]);
			if(!dis[i][j]) dis[i][j]=INF;//Ҫ�Ǿ���Ϊ0�Ļ����ǹ���ȥ��
		}
	}
	floyd();//�����е�֮������·
	s=0;//����Դ��
	e=k+c+1;//�������
	l=0,r=2000;//���ұ߽�
	printf("%d\n", m);
	while(l<r)//����
	{
		mid=(l+r)/2;
		init();
		no=0;
		for(int i=k+1;i<=k+c;i++)//��ͼ����
		{
			add(0,i,1);//Դ����ţ������Ϊ1�ı�
		}
		for(int i=1;i<=k;i++)
		{
			add(i,e,m);//���̻�����������Ϊm�ı�
		}
		for(int i=k+1;i<=k+c;i++)
		{
			for(int j=1;j<=k;j++)
			{
				if(dis[i][j]<=mid) add(i,j,1);//��ţ�뼷�̻���ľ���С�ڵ���mid��������Ϊ1�ı�
			}
		}
//		printf("%d\n", mid);
//		for(int i = s; i <= e; i++){
//            printf("%d:\n", i);
//            for(int j = head[i]; j != -1; j = p[j].next){
//                printf("%d ", p[j].v);
//            }
//            printf("\n");
//        }
		ans=dinic();//��ǰͼ�������
		printf("%d\n", ans);
		if(ans==c) r=mid;//�ж��Ƿ������ţ��
		else l=mid+1;
	}
	printf("%d\n",r);
}

int main()
{
	int m,s,e,l,r,mid;
	//freopen("C:\\Users\\sony\\Desktop\\11.txt","r",stdin);
	scanf("%d %d %d",&k,&c,&m);
	solve();
}
