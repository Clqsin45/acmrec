#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define N 1004
#define T 400000
#define INF 0x3f3f3f3f

int  st[N], ans, pos[N], val[N];

bool vis[N];
int num[100];


/*
同时有重复覆盖与精确覆盖时，尝试取某一行时，一定要先去掉重复覆盖的列，再去精确覆盖的列。
因为去精确覆盖的列时，会把重复覆盖的列的关系打乱，使后面再去重复覆盖时找不到了，无法结束。
*/
struct DLX{
	int r[T], u[T], l[T], d[T];
	int cnt[344], col[T], head[N], row[T];
	int n, id;

	void init(int nt){
		this->n = nt;
		int i;
		for(i = 0; i <= n; i++){
			d[i] = u[i] = i;
			l[i] = i - 1;	r[i] = i + 1;
		}
		id = n + 1;
		r[n] = 0;	l[0] = n;

		memset(cnt, 0, sizeof(cnt));
		memset(head, -1, sizeof(head));
	}

	void add(int rr, int cc){
		d[id] = cc;	u[id] = u[cc];
		d[u[cc]] = id;	u[cc] = id;

		if(head[rr] < 0){
			head[rr] = l[id] = r[id] = id;
		}
		else {
			l[id] = head[rr];	r[id] = r[head[rr]];
			l[r[head[rr]]] = id;	r[head[rr]] = id;
			head[rr] = id;
		}
		cnt[cc] ++;	col[id] = cc;
		row[id] = rr;
		id ++;
	}

	void del(int x){
		int i, j;
		l[r[x]] = l[x];	r[l[x]] = r[x];

		for(i = d[x]; i != x; i = d[i]){
			for(j = r[i]; j != i; j = r[j]){
				cnt[col[j]] --;
				u[d[j]] = u[j];	d[u[j]] = d[j];
			}
		}
		return ;
	}

	void resume(int x){
		int i, j;
		for(i = u[x]; i != x; i = u[i]){
			for(j = l[i]; j != i; j = l[j]){
				cnt[col[j]] ++;
				d[u[j]] = j;	u[d[j]] = j;
			}
		}
		l[r[x]] = x;	r[l[x]] = x;
	}

	bool  dfs(int deep){
		if(r[0]==0) {
			int i, j, now = 0;

			for(i = 0; i < deep; i++)  num[pos[st[i]]] = val[st[i]];
			for(i = 0; i < 9; i++){
                for(j = 0; j < 9; j++){
                    printf("%d", num[now]);
                    now ++;
                }
                printf("\n");
			}
			return true;
		}
		int idx, temp = INF, i, j;

		for(i = r[0]; i != 0; i = r[i]){
			if(cnt[i] < temp){
				temp = cnt[i];
				idx = i;
			}
		}
//printf("!!%d %d\n",  temp, idx);
	//	printf("%d\n", idx);
		if(temp == 0) return false;
		del(idx);
		for(i = d[idx]; i != idx; i = d[i]){
            st[deep] = row[i];
			for(j = r[i]; j != i; j = r[j]){
				del(col[j]);
			}
            if(dfs(deep +1)) return true;
			for(j = l[i]; j != i; j = l[j]){
				resume(col[j]);
			}
            --ans;
		}
		resume(idx);return false;
	}

}dlx;


int main(){
 //freopen("in.txt", "r", stdin);
    char s[4];
    int  i, j, k, now, id, a, b, c, d, loc, tc;
    scanf("%d", &tc);
    while(tc--){
        for(i = 0; i < 81; i++) {
            scanf("%1d", &num[i]);
        }


        //init
        dlx.init(324);
        id = now = ans = 0;
        memset(vis, false, sizeof(vis));

        for(i = 0; i < 9; i++){
            for(j = 0; j < 9; j++){
                if(num[now]){
                    loc = i / 3  * 3 +j / 3;
                    a = i * 9 + j + 1;  b = i * 9 + 81 + num[now];
                    c = 162 + j * 9 +num[now] ;
                    d = loc * 9 + 243 + num[now] ;
                    vis[a] = vis[b] = vis[c] = vis[d] = true;
                  //  if(i == 0) printf("have%d %d %d\n", i, j, d);
                    dlx.add(++id, a) ;
                    dlx.add(id, b) ;
                    dlx.add(id, c) ;
                    dlx.add(id, d);
                    pos[id] = a - 1;    val[id] = num[now];
                }
                now ++;
            }
        }
        now = 0;
        for(i = 0; i < 9; i++){
            for(j = 0; j < 9; j++){
              //  printf("%d\n", i);
                if(!num[now]){
                    for(k = 1; k <= 9; k++){

                        loc = i / 3 * 3 +j / 3;
                        a = i * 9 + j + 1;  b = i * 9 + 81 + k;
                        c = 162 + j * 9 + k;
                        d = loc * 9 + 243 + k;
                     //   printf("%d %d %d %d %d\n",a, k,vis[c], vis[b], vis[d]);
                       // if(i == 0) printf("have%d %d %d\n", i, j, d);
                        if( vis[b] || vis[c]||vis[d]) continue;

                        dlx.add(++id, a);
                        dlx.add(id, b) ;
                        dlx.add(id, c) ;
                        dlx.add(id, d);
                        pos[id] = a - 1;    val[id] = k;
                    }
                }
                now ++;
            }
        }
     //  printf("!!!\n");
        dlx.dfs(0);
    }
    return 0;
}
