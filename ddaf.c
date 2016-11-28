#include<stdio.h>
int n,m,t,i,j,ans=0;
int father[1000002]={0};
int a[1000002]={0};
int lenth[1000002]={0};

void find_len(long long now)
{
    int i,j,late=now,x,l,len=0;
    father[now]=-1;
    while(1)
    {
        if(now<=1000000 && a[now]!=0)  break;
        if(now%2==0)  now/=2;
        else now=now*3+1;
        if(now<=1000000)
        {
            father[now]=late;
            late=now;
        }
        else lenth[late]++;
    }
    x=father[now];  l=a[now];
    while(x!=-1)
    {
        a[x]=++l+lenth[x];
        l=a[x];
        x=father[x];
    }
    return;
}

int main()
{
    a[1]=1;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        t=0;
        if(n>m)  { t=n; n=m; m=t;}
        ans=0;
        for(i=n;i<=m;i++)
        {
            if(a[i]==0)  find_len(i);
            if(a[i]>ans)  ans=a[i];
        }
        if(t!=0)  { t=n; n=m; m=t;}
        printf("%d %d %d\n",n,m,ans);
    }
    return 0;
}
