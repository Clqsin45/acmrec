#include<cstdio>
using namespace std;
const int mm=111111;
const int mn=1111;
const int oo=1000000000;
int node,src,dest,edge,n,m;
int ver[mm],flow[mm],next[mm];
int head[mn],work[mn],dis[mn],q[mn],in[mn];
inline int min(int a,int b)
{
    return a<b?a:b;
}
inline void prepare(int _node,int _src,int _dest)
{
    node=_node,src=_src,dest=_dest;
    for(int i=0; i<node; ++i)head[i]=-1;
    edge=0;
}
inline void addedge(int u,int v,int c)
{
    ver[edge]=v,flow[edge]=c,next[edge]=head[u],head[u]=edge++;
    ver[edge]=u,flow[edge]=0,next[edge]=head[v],head[v]=edge++;
}
bool Dinic_bfs()
{
    int i,u,v,l,r=0;
    for(i=0; i<node; ++i)dis[i]=-1;
    dis[q[r++]=src]=0;
    for(l=0; l<r; ++l)
        for(i=head[u=q[l]]; i>=0; i=next[i])
            if(flow[i]&&dis[v=ver[i]]<0)
            {
                dis[q[r++]=v]=dis[u]+1;
                if(v==dest)return 1;
            }
    return 0;
}
int Dinic_dfs(int u,int exp)
{
    if(u==dest)return exp;
    for(int &i=work[u],v,tmp; i>=0; i=next[i])
        if(flow[i]&&dis[v=ver[i]]==dis[u]+1&&(tmp=Dinic_dfs(v,min(exp,flow[i])))>0)
        {
            flow[i]-=tmp;
            flow[i^1]+=tmp;
            return tmp;
        }
    return 0;
}
void Dinic_flow()
{
    while(Dinic_bfs())
    {
        for(int i=0; i<node; ++i)work[i]=head[i];
        while(Dinic_dfs(src,oo));
    }
}
int limit_min_flow()
{
    int i,src0,dest0,edge0;
    src0=src,dest0=dest,edge0=edge;
    src=node++,dest=node++;
    head[src]=head[dest]=-1;
    for(i=1; i<=n; ++i)
    {
        if(in[i]>0)addedge(src,i,in[i]);
        if(in[i]<0)addedge(i,dest,-in[i]);
    }
    Dinic_flow();
    addedge(dest0,src0,oo);
    Dinic_flow();
    for(i=head[dest0]; i>=0; i=next[i])
        if(ver[i]==src0)return flow[i^1];
}
int main()
{
    int i,u,v,k,c,t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        prepare(n+2,0,n+1);
        for(i=1; i<=n; ++i)
            addedge(src,i,oo),addedge(i,dest,oo),in[i]=0;
        for(i=1; i<=m; ++i)
        {
            scanf("%d%d%d",&u,&v,&c);
            if(c)--in[u],++in[v];
            addedge(u,v,oo);
        }
        printf("Case #%d: %d\n",++cas,limit_min_flow());
    }
    return 0;
}
