#include <bits/stdc++.h>
using namespace std;
typedef __int64 ll;
const int N = 2000;
const int M  =  1000005;
const int INF=  0x3f3f3f3f;

int gox[4] = {0, 0, -1, 1}, goy[4] = {-1, 1, 0, 0};
int head[N], d[N], st[M], cur[N];
int no, id, s, e, n, m, numn, numf;
ll inf;
ll  tmax = 0;

int f[500][500], num[24][24];
char ch[24][24];
struct Infor{
    int r, c;
    ll t;
    void scan(){
        scanf("%d%d%I64d", &r, &c, &t);
        tmax = max(t, tmax);
    }

    ll cal(int x, int y){
        int temp = f[num[r][c]][num[x][y]];
        if(temp == INF) return inf + 1;
        return t * temp ;
    }
}male[500], famale[500], boss;
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
	no = 0 ;
}

bool bfs(){
	int i, x, y;
	queue<int>q;
	memset(d, -1, sizeof(d));
	d[s] = 0;	q.push(s);
	while(!q.empty()){
		x = q.front();	q.pop();
		for(i = head[x]; i != -1; i = p[i].next){
			if(p[i].flow && d[y = p[i].v] < 0){
				d[y] = d[x] + 1;
				if(y == e)	return true;
				q.push(y);
			}
		}
	}
	return false;
}

int dinic(){
	int i, loc, top, x = s, nowflow, maxflow = 0;
	while(bfs()){
		for(i = s; i <= e; i++)	cur[i] = head[i];
		top = 0;
		while(true){
			if(x == e){
				nowflow = INF;
				for(i = 0; i < top; i ++){
					if(nowflow > p[st[i]].flow){
						nowflow = p[st[i]].flow;
						loc = i;
					}
				}
				for(i = 0; i < top; i++){
					p[st[i]].flow -= nowflow;
					p[st[i]^1].flow += nowflow;
				}
				maxflow += nowflow;
				top = loc;	x = p[st[top]].u;
			}
			for(i = cur[x]; i != -1; i = p[i].next)
				if(p[i].flow && d[p[i].v] == d[x] + 1) break;
			cur[x] = i;
			if(i != -1){
				st[top ++] = i;
				x = p[i].v;
			}
			else {
				if(!top)	break;
				d[x] = -1;
				x = p[st[--top]].u;
			}
		}
	}
	//printf("%d\n", maxflow);
	return maxflow;
}

void floyd()
{
    int i, j , k;
    for(k = 1; k <= id; k++)
        for(i = 1; i <= id; i++)
            for(j = 1; j <= id; j++)
                if(f[i][j] > f[i][k] + f[k][j]) f[i][j] = f[i][k] + f[k][j];
}

bool inmap(int x, int y){
    return x>=1 && y >= 1&& x <= n && y <= m;
}
void pre(){
    int i, j, k, x, y, poi;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            if(ch[i][j] == '#')continue;
            num[i][j] = ++id;
        }
    }

    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            if(ch[i][j] == '#') continue;
            poi = num[i][j];
            for(k = 0; k < 4; k++){
                x = i +gox[k];
                y = j + goy[k];
                if(inmap(x, y) && ch[x][y] != '#') {
                    f[poi][num[x][y]] = 1;
                }
            }
        }
    }
    for(i = 1; i <= id; i++)    f[i][i] = 0;
    floyd();
    return ;
}

void build(ll mid){
    int i, j, k, t;
    init();
    for(i = 1; i<= numn; i++){
        add(s, i, 1);
        for(j = 1; j <= n; j++){
            for(k = 1; k <= m; k++){
                if(ch[j][k] == '#')continue;
                if(male[i].cal(j, k) <= mid){
                    add(i, num[j][k] + numn, 1);
                }
            }
        }
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            if(ch[i][j] == '#')continue;
            add(num[i][j] + numn, num[i][j] +numn + id, 1);
        }

    }
    for(i = 1; i<= numf; i++){
        add(i + 2 * id + numn, e, 1);
        for(j = 1; j <= n; j++){
            for(k = 1; k <= m; k++){
                if(ch[j][k] == '#')continue;
                if(famale[i].cal(j, k) <= mid){
                    add(num[j][k] + numn + id,i + 2 * id + numn , 1);
                }
            }
        }
    }

//    for(i = 0; i <= e; i++){
//        printf("%d:\n",i);
//        for(j = head[i]; j != -1;j  =p[j].next){
//            if(p[j].flow != 0)  printf("%d ", p[j].v);
//        }
//        printf("\n");
//    }
}

int main(){
    int i, j;
    ll low, high, mid, ans;
    memset(f, 0x3f, sizeof(f));
    id = 0;
    scanf("%d%d%d%d", &n, &m, &numn, &numf);
    for(i = 1; i <= n; i++) scanf("%s", ch[i]+1);

   // printf("%d\n", id);
    boss.scan();
    for(i = 1; i <= numn; i++)  male[i].scan();
    for(i = 1; i <= numf; i++)  famale[i].scan();
    if(abs(numn-numf) != 1) {
        printf("-1\n"); return 0;
    }
    if(numn < numf) male[++numn] = boss;
    else famale[++numf] = boss;
    pre();
//    for(i = 1; i <= id; i++){
//        for(j = 1; j <= id; j++){
//            printf("%d ", f[i][j]);
//        }
//        printf("\n");
//    }
    s = 0;  e = id * 2 + numn + numf + 1;
  //  printf("%d %d\n", s, e);
    low = 0;    high = (n*m)*tmax;
    inf = high;
    //low = high = 20;
    ans = -1;
    while(low <= high){
        mid = (low + high) >> 1;
        build(mid);
       // printf("%I64d %I64d %I64d ", low,  mid, high);
        if(dinic() == numf){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
        //printf("\n");
    }
    printf("%I64d\n", ans);
    return 0;
}

