#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<map>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<list>
using namespace std;
const int MAX=110000;
const double EPS=1.0e-8;
int dblcmp(double x)
{
    if(fabs(x)<EPS)return 0;
    return x<0?-1:1;
}
int tree[MAX];
int a[MAX];

int query(int t)
{
    int ret=0;
    while(t)
    {
        if(tree[t]>ret)ret=tree[t];
        t-=(-t)&t;
    }
    return ret;
}
void ins(int t,int v,int n)
{
    while(t<=n)
    {
        if(v>tree[t])tree[t]=v;
        t+=(-t)&t;
    }
}
int dp[MAX];
int dcre[MAX],c;

int main(){

    int n;
    int i,j;
    int d;

    while(scanf("%d%d",&n,&d)!=EOF)
    {
        c=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);

            dcre[i]=a[i];
        }
        sort(dcre,dcre+n);
        c=unique(dcre,dcre+n)-dcre;
        memset(tree,0,sizeof(int)*(c+2));
        for(i=0;i<n;i++)
        {
            a[i]=lower_bound(dcre,dcre+c,a[i])-dcre+1;
            printf("%d  %d\n", i, a[i]);
        }

        int ans=1;
        int tmp=0;
        for(i=0;i<n;i++)
        {
            //printf("%d\n", a[i] - 1);
            tmp=query(a[i]-1)+1;

            if(tmp>ans)ans=tmp;

            dp[i]=tmp;

            j=i-d;
            printf("%d\n", j);
            if(j>=0)
            {
                ins(a[j],dp[j],c);
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}
