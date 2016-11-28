void addedge(int x,int y,int c){
    e++;
    g[e].x=x; g[e].y=y; g[e].c=c; g[e].op=e+1;
    g[e].next=ls[x]; ls[x]=e;
    e++;
    g[e].x=y; g[e].y=x; g[e].c=0; g[e].op=e-1;
    g[e].next=ls[y]; ls[y]=e;
}

void init(){
    e=0;
    memset(ls,0,sizeof(ls));
    memset(zgl,0,sizeof(zgl));
    for (int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        addedge(x+n,y,inf);
    }
    scanf("%d%d",&S,&T);
    for (int i=0;i<n;i++)
      if (i!=S && i!=T) addedge(i,i+n,1);
                   else addedge(i,i+n,2);
    T+=n;
}

bool bfs(){
    for (int i=0;i<2*n;i++) v[i]=0;
    int head=0,tail=1;
    list[1]=S;
    while (head!=tail){
        head++;
        for (int t=ls[list[head]];t;t=g[t].next)
          if (!v[g[t].y] && g[t].c){
              v[g[t].y]=1;
              tail++;
              list[tail]=g[t].y;
              fa[g[t].y]=t;
          }
    }
    if (v[T]) return true;
    return false;
}

void change(){
    for (int i=T;i!=S;i=g[fa[i]].x){
        g[fa[i]].c--;
        g[g[fa[i]].op].c++;
        zgl[i]=1;
    }
    zgl[S]=1;
}

int ek(){
    bool flag=bfs();
    if (!bfs()) return 0;
    change();
    flag=bfs();
    if (!bfs()) return 1;
    return 2;
}

void dfs(int k){
    tt++;
    list[tt]=k;
    v[k]=1;
    for (int t=ls[k];t;t=g[t].next)
      if (g[t].c && !v[g[t].y]) dfs(g[t].y);
}

void work(){
    g[ls[S]].c=0;
    g[ls[T-n]].c=0;
    memset(v,0,sizeof(v));
    ans=0;
    int st=S;
    for (;;){
        tt=0;
        dfs(st);
        bool flag=false;
        for (int i=1;i<=tt;i++) if (!flag)
          for (int t=ls[list[i]];t;t=g[t].next)
            if ((t&1) && !g[t].c && !v[g[t].y]){
                ans++;
                flag=true;
                st=g[t].y;
                if (g[t].y==T) return;
            }
    }
}

int main(){
    while (scanf("%d%d",&n,&m)!=EOF){
        init();
        if (S+n==T){
            printf("1n");
            continue;
        }
        int flow=ek();
        if (flow==0) printf("%dn",n);
        else
        if (flow==2) printf("2n");
        else{
            work();
            printf("%dn",ans);
        }
    }
}
