//#pragma comment(linker, "/STACK:36777216")
//#pragma GCC optimize ("O2")
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<ctime>
#include<queue>
#include<utility>
using namespace std;
#define E          2.71828182845904523536
#define PI         3.14159265358979323846
#define PI_2       1.57079632679489661923
#define PI_4       0.785398163397448309616
#define SQRT2      1.41421356237309504880
#define SQRT1_2    0.707106781186547524401
#define mcpy(from,to) memcpy((to),(from),sizeof((from)))
#define msetz(pp) memset((pp),0,sizeof((pp)))
#define mseto(pp) memset((pp),1,sizeof((pp)))
#define msetno(pp) memset((pp),-1,sizeof((pp)))
#define mseti(pp) memset((pp),0x3f3f3f3f,sizeof((pp)))
#define msetni(pp) memset((pp),0xc0c0c0c0,sizeof((pp)))
typedef pair<int,int> PII;
typedef __int64 LL;
const int INF=0x3f3f3f3f;
const double inf=1e20,eps=1e-8;
const double pi=acos(-1.0);

template <class T>
void exGCD(T a,T b,T &d,T &x,T &y) {//ax+by==d=gcd(a,b)
	if(b==0) { d=a;x=T(1);y=T(0); }
	else { exGCD(b,a%b,d,y,x);y-=x*(a/b); }
}
template <class T>
T ceil(T aa,T bb) {
	if(bb<T(0)) { aa=-aa;bb=-bb; }
	if(aa>T(0)) return (aa-T(1))/bb+T(1);
	else return aa/bb;
}
template <class T>
T floor(T aa,T bb) {
	if(bb<T(0)) { aa=-aa;bb=-bb; }
	if(aa>=T(0)) return aa/bb;
	else return (aa+T(1))/bb-T(1);
}
template <class T> T lowbit(T x) { return x&(-x); }
template <class T> T gcd(T a,T b) { return b?gcd(b,a%b):a; }
const LL mod=LL(1e9)+7ll;
template <class T> T qpow(T a,T b) {
	if(b==T(0)) return T(1);
	T t=qpow(a*a%mod,b>>1);
	if(b&T(1)) t=t*a%mod;
	return t;
}
int readint(){
	char c;
	while(c=getchar(),(c<'0'||c>'9')&&(c!='-'));
	bool flag=(c=='-');
	if(flag) c=getchar();
	int x=0;
	while(c>='0'&&c<='9') {
		x=x*10+c-48;
		c=getchar();
	}
	return flag?-x:x;
}
LL readLL(){
	char c;
	while(c=getchar(),(c<'0'||c>'9')&&(c!='-'));
	bool flag=(c=='-');
	if(flag) c=getchar();
	LL x=0ll;
	while(c>='0'&&c<='9') {
		x=x*10ll+LL(c-48);
		c=getchar();
	}
	return flag?-x:x;
}
void putint(int x){
	if(x<0) {
		putchar('-');
		x=-x;
	}
	int len=0,data[10];
	while(x) {
		data[len++]=x%10;
		x/=10;
	}
	if(!len) data[len++]=0;
	while(len--) putchar(data[len]+48);
	//putchar('\n');
}
void putLL(LL x){
	if(x<0ll) {
		putchar('-');
		x=-x;
	}
	int len=0,data[30];
	while(x>0ll) {
		data[len++]=x%10ll;
		x/=10ll;
	}
	if(!len) data[len++]=0;
	while(len--) putchar(data[len]+48);
	putchar('\n');
}

const int MAXN=300,MAXE=30000,NINF=0xc0c0c0c0;
struct Edge {
	int u,v,f,cost,next;
	Edge() {};
	Edge(int u,int v,int f,int cost,int next):u(u),v(v),f(f),cost(cost),next(next) {};
};
Edge edge[MAXE];
int head[MAXN<<1],dis[MAXN],pe[MAXN],nEdge;
bool vis[MAXN<<1];
void init() {
	memset(head,-1,sizeof(head));
	nEdge=0;
}
void addedge(int u,int v,int c,int cost) {
	edge[nEdge]=Edge(u,v,c,cost,head[u]);
	head[u]=nEdge++;
	edge[nEdge]=Edge(v,u,0,-cost,head[v]);
	head[v]=nEdge++;
}
bool spfa(int src,int sink) {
	memset(vis,false,sizeof(vis));
	for(int i=src;i<=sink;i++) dis[i]=NINF;
	memset(pe,-1,sizeof(pe));
	queue<int> q;
	q.push(src);
	dis[src]=0;
	vis[src]=true;
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		vis[u]=false;
		for(int i=head[u];i!=-1;i=edge[i].next) {
			int f=edge[i].f,v=edge[i].v,cost=edge[i].cost;
			if(f&&dis[u]+cost>dis[v]) {
				dis[v]=dis[u]+cost;
				pe[v]=i;
				if(!vis[v]) {
					vis[v]=true;
					q.push(v);
				}
			}
		}
	}
	if(dis[sink]!=NINF) return true;
	else return false;
}
int min_cost_max_flow(int src,int sink) {
	int ans=0;
	while(spfa(src,sink)) {
		int delta=INF;
		for(int i=pe[sink];i!=-1;i=pe[edge[i].u]) delta=min(delta,edge[i].f);
		for(int i=pe[sink];i!=-1;i=pe[edge[i].u]){
			edge[i].f-=delta;
			edge[i^1].f+=delta;
		}
		ans+=dis[sink]*delta;
	}
	return ans;
}

int n,val[MAXN],hh[MAXN],pp[MAXN],aa[MAXN],bb[MAXN];

bool check(int u,int v) {
	int i=ceil(hh[u],bb[v]),j=ceil(pp[v],aa[u]);
	return i>=j;
}

int main() {
	while(~scanf("%d",&n)&&n) {
		for(int i=1;i<=n;i++) val[i]=readint();
		for(int i=1;i<=n;i++) hh[i]=readint();
		for(int i=1;i<=n;i++) pp[i]=readint();
		for(int i=1;i<=n;i++) aa[i]=readint();
		for(int i=1;i<=n;i++) bb[i]=readint();
		init();
		int src=0,sink=2*n+1;
		for(int i=1;i<=n;i++) {
			addedge(src,i,1,0);
			addedge(i+n,sink,1,0);
		}
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {
			int cc=val[i]*1000;
			if(!check(i,j)) cc=-cc;
			if(i==j) cc++;
			addedge(i,j+n,1,cc);
		}
		int totc=min_cost_max_flow(src,sink);
		if(totc/1000>0) {
			double ss=100.0*(totc%1000)/n;
			putint(totc/1000),putchar(' ');
			printf("%.3f%%\n",ss);
		}
		else puts("Oh, I lose my dear seaco!");
	}
	return 0;
}
