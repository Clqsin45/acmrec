#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
/*******************
KM的无穷大手动清成一样的。。。。不要用memset
********************/
#define N 104
#define M
#define LL __int64
#define INF 0x3f7f7f7f

//3 3
//1 2 10
//2 3 5
//3 2 5
bool vx[N], vy[N];
int slack[N], lx[N], ly[N], f[N][N];
int match[N], n, m;

void init(){
    int i, j;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++) f[i][j] = -INF;
    for(i = 1; i <= n; i++) lx[i] = -INF;
//    memset(f, 0x80, sizeof(f));
//    memset(lx, 0x80, sizeof(lx));
    memset(ly, 0, sizeof(ly));
    memset(match, 0, sizeof(match));
}

bool dfs(int x){
    vx[x] = true;
    int i, j, t;
    for(i = 1; i <= n; i++){
        if(vy[i])   continue;
        t = lx[x] + ly[i] - f[x][i];
        if(t == 0){
            vy[i] = 1;
            if(!match[i] || dfs(match[i])){
                match[i] = x;
                return true;
            }
        }
        else {
            slack[i] = min(slack[i], t);
        }
    }
    return false;

}
void km(){
    int i, j, minm, ans;
    bool flag;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            lx[i] = max(lx[i], f[i][j]);
        }
    }
    for(i = 1; i <= n; i++){
        //printf("!!%d\n", i);    system("pause");
       // memset(slack, 0x3f, sizeof(slack));
       for(j = 1; j <= n; j++)  slack[j] = INF;
        while(true){
           // printf("%d %d\n", i, slack[i]);  system("pause");
            memset(vx, 0, sizeof(vx));
            memset(vy, 0, sizeof(vy));
            if(dfs(i)) break;

            minm = INF;
            for(j = 1; j <= n; j++)
                if(!vy[j])  minm = min(slack[j], minm);

            for(j = 1; j <= n; j++){
                if(vx[j])   lx[j] -= minm;
                if(vy[j])   ly[j] += minm;
                else slack[j] -= minm;
            }

        }
    }

    for(i = 1, flag = true; i <= n; i++){
        if(!match[i] || f[match[i]][i] == -INF){
            flag = false;
            break;
        }
    }
    if(!flag)   {

        printf("-1\n");
        return;
    }
    ans = 0;
    for(i = 1; i <= n; i++){
        ans += f[match[i]][i];
    }
    printf("%d\n",-ans);

}
inline int scan_d() {
	char c;
	int ret=0;
	while((c=getchar())<'0'||c>'9');
	while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
int main(void)
{
    int i, j, x, y, z;
    while(scanf("%d%d", &n, &m) != EOF){
        init();
        while(m--){
            //scanf("%d%d%d", &x, &y, &z);
            x = scan_d();   y = scan_d();   z = scan_d();
            z = -z;

            f[x][y] = max(z, f[x][y]);
            //lx[x] = max(lx[x], z);
        }

        km();
    }
    return 0;
}
