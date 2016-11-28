#include <iostream>
#include<cstdio>

using namespace std;
const int inf=1999999999;
const int Maxv=1300;
const int Maxe=1000000;
struct Node
{
    int id,flow;
    Node *next;
};
//以下为dinic主过程，调用 maxFlow=dinic(s,t)
bool levelmaxflow(Node* node[],Node edge[],int S,int T,int level[])
{
int stack[Maxv];
for(int i=0;i< Maxv;i++)level[i]=-1;
level[S]=1;
int front=1,rear=1;
stack[front]=S;
while(front<=rear)
{
int v=stack[front++];
for(Node *temp=node[v];temp!=NULL;temp=temp->next)
{
int id=temp->id,flow=temp->flow;
if(level[id]==-1&&flow>0)
{
level[id]=level[v]+1;
stack[++rear]=id;
if(id==T)
return true;
}
}
}
return false;
}

int maxflow(Node* node[],Node edge[],int S,int T) //函数主体
{
Node *out[Maxv],*mat[Maxv];
bool vis[Maxv];
int tflow=0,path[Maxv],level[Maxv];;
while(levelmaxflow(node,edge,S,T,level))
{
for(int i=0;i<=T;i++)
out[i]=node[i],vis[i]=false;
int pos=1;
path[pos]=S;
while(pos)
{
int v=path[pos];
if(v==T)
{
int now=inf;
for(int i=1;i<pos;i++)
now=min(now,mat[path[i]]->flow);
tflow+=now;
int pt;
for(int i=1;i<pos;i++)
{
mat[path[i]]->flow-=now;
Node* temp=edge+((mat[path[i]]-edge)^1);
temp->flow+=now;
if(mat[path[i]]->flow==0)
pt=i;
}
pos=pt;
}
else
{
int x=path[pos];
bool flag=false;
for(Node *temp=out[x];temp!=NULL;temp=temp->next)
{
int id=temp->id,flow=temp->flow;
if(!vis[id]&&level[id]==level[x]+1&&flow>0)
{
mat[x]=temp;
out[x]=temp->next;
flag=true;
path[++pos]=id;
break;
}
}
if(!flag)
{
pos--;
vis[x]=true;
}
}
}
}
return tflow;
}
Node edge[Maxe],*node[Maxv];
int numptr;
void addEdge(int x,int y,int flow)//增加一条从x到y流量为flow的流
{
edge[numptr].id=y;
edge[numptr].flow=flow;
edge[numptr].next=node[x];
node[x]=&edge[numptr];
numptr++;
edge[numptr].id=x;
edge[numptr].flow=0;
edge[numptr].next=node[y];
node[y]=&edge[numptr];
numptr++;
}
int main()
{
//freopen("in","r",stdin);
int i,k,n,m,x,y,t,ans,sum;
scanf("%d",&t);
for(k=1;k<=t;k++)
{
scanf("%d%d",&n,&m);
for(i=0;i<2*n+4;i++)
{
    node[i]=NULL;
}
numptr=0;
while(m--)
{
    scanf("%d%d",&x,&y);
    addEdge(x,y+n,1);
    addEdge(y,x+n,1);
}
sum=0;
for(i=1;i<=n;i++)
{
scanf("%d",&x);
sum+=x;
addEdge(0,i,x);
addEdge(i+n,n+n+1,x);
}
ans=maxflow(node,edge,0,n+n+1);
if(ans==sum)
{
printf("Case %d: YES\n",k);
}
else{
printf("Case %d: NO\n",k);
}
}

return 0;
}
