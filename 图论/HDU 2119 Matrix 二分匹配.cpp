#include <cstdio>
#include<iostream>
#include <string.h>
using namespace std;

int f[210];
bool sex[210];	//相对于父节点的性别
const int MAXN = 210;
int g[MAXN][MAXN], Mx[MAXN], My[MAXN], Nx, Ny;
int chk[MAXN], Q[MAXN], prev[MAXN];

int MaxMatch(void)
{
  int res = 0;
  int qs, qe;

  memset(Mx, -1, sizeof(Mx));
  memset(My, -1, sizeof(My));
  memset(chk, -1, sizeof(chk));

  for (int i = 0; i < Nx; i++){
    if (Mx[i] == -1){
      qs = qe = 0;
      Q[qe++] = i;
      prev[i] = -1;

      bool flag = 0;
      while (qs < qe && !flag){
        int u = Q[qs];
        for (int v = 0; v < Ny && !flag; v++)
          if (g[u][v] && chk[v] != i) {
            chk[v] = i; Q[qe++] = My[v];
            if (My[v] >= 0) prev[My[v]] = u;
            else {
              flag = 1;
              int d = u, e = v;
              while (d != -1) {
                int t = Mx[d];
                Mx[d] = e; My[e]  =  d;
                d = prev[d]; e = t;
              }
            }
          }
          qs++;
      }
      if (Mx[i] != -1) res++;
    }
  }
  return res;
}
int find(int x,bool &se)
{
  se=true;
  int r=x;
  while(x!=f[x])
  {
    if(sex[x]==false)
      se=!se;
    x=f[x];
  }
  f[r]=x;
  sex[r]=se;
  return x;
}
int main()
{
  int t,i,n,m,a,b,cnt=1;
  while(scanf("%d%d",&n,&m)!=EOF)
  {
    Nx=Ny=n;
    memset(g,0,sizeof(g));
    for(i=1;i<=n;i++)
      f[i]=i,sex[i]=true;
    bool judge=true;
    while(m--)
    {
      scanf("%d%d",&a,&b);
      g[a-1][b-1]=true;
      if(judge)			//未异常
      {
        bool l1=0,l2=0;
        int fa=find(a,l1),fb=find(b,l2);
        if(fa==fb)
        {
          if(l1==l2)
            judge=false;
        }
        else
        {
          f[fa]=fb;
          sex[fa]=l1^l2;
        }
      }
    }
    if(!judge)
    {
      printf("No\n");
    }
    else
      printf("%d\n",MaxMatch());
  }
  return 0;
}
