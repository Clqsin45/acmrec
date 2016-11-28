#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define N 22
#define M 303
#define S 6000
#define LL __int64
#define INF 0x3f7f7f7f

int l[S], r[S], u[S], d[S], sum[M], col[S], row[S], no, n, m;
bool vis[N];
vector<int>v;
void init()
{
    memset(sum, 0, sizeof(sum));
    memset(row, -1, sizeof(row));
    memset(vis, false, sizeof(vis));
    v.clear();
    int i;
    for(i = 1; i <= m; i++){
        u[i] = d[i] = i;
        l[i] = i - 1;
        r[i] = i + 1;
    }
    r[m] = 0; l[0] = m;     r[0] = 1;
    no = m;
}

void del(int x){
    l[r[x]] = l[x]; r[l[x]] = r[x];
    int i, j;
    for(i = d[x]; i != x; i = d[i]){
        for(j = r[i]; j != i; j = r[j]){
            sum[col[j]] --;
            u[d[j]] = u[j]; d[u[j]] = d[j];
        }
    }
}

void resume(int x){
    int i, j;
    for(i = u[x]; i != x; i = u[i]){
        for(j = l[i]; j != i; j = l[j]){
            sum[col[j]] ++;
            d[u[j]] = j;   u[d[j]] = j;
        }
    }
    l[r[x]] = x;    r[l[x]] = x;
}

bool dfs(){
    if(r[0] == 0)   return true;
    int idx, temp, i, j;
    temp = INF;
    for(i = r[0]; i != 0; i = r[i]){
        if(sum[i] < temp){
            temp = sum[i];    idx = i;
        }
    }
    if(temp == 0)   return false;

    del(idx);

    for(i = d[idx]; i != idx; i = d[i]){
        //printf("%d\n", i);
        for(j = r[i]; j != i; j = r[j]){
           del(col[j]);
        }
        //printf("%d\n", j);
        if(dfs())   return true;
        for(j = l[i]; j != i; j = l[j])
            resume(col[j]);
    }
    resume(idx);
    return false;
}
int main(void)
{
    int  i, j, x, a;
    while(scanf("%d%d", &n, &m) != EOF){
        init();
        for(i = 1; i <= n; i++){
            for(j = 1; j <= m; j++){
                scanf("%d", &x);
                if(x){
                    no++;
                    if(!vis[i]){
                        l[no] = r[no] = no;
                        a = no;
                        vis[i] = true;
                    }
                    else{
                        l[no] = no - 1;
                        r[no] = a;
                        r[no - 1] = no;
                        l[a] = no;
                        //l[no - 1] = r[no - 1] =  no;
                    }
                    d[u[j]] = no;
                    u[no] = u[j];
                    u[j] = no;  d[no] = j;

                    sum[j] ++;    row[no] = i;    col[no] = j;
                }
            }
        }
      //  printf("%d\n", d[6]);

        if(dfs())  printf("Yes, I found it\n");
        else printf("It is impossible\n");
    }
    return 0;
}
