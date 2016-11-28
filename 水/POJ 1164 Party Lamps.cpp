/*
ID: someway1
PROG: lamps
LANG: C++
*/
#include<cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 34;
const int M = 10;
bool  ans[N][M], same[N][N];
int n, c, id = 0;
bool on[M], off[M];
int f[N];

void gao(int x){
    int one = 0, tp = x, i;
    while(tp){
        one += (tp&1);
        tp >>= 1;
    }
    if(c - one < 0 || ((c - one)&1))    return;
   // printf("%d\n", x);
    ++id;
    for(i = 1; i <= n; i++) ans[id][i] = 1;
    if(x&1) for(i = 1; i <= n; i++) ans[id][i] ^= 1;
    if(x&2) for(i = 1; i <= n; i += 2) ans[id][i] ^= 1;
    if(x&4) for(i = 2; i <= n; i+= 2)   ans[id][i] ^= 1;
    if(x&8) for(i = 1; i <= n; i+= 3)   ans[id][i] ^= 1;
    //f[id] = id;
    for(i = 1; i <= n; i++){
      //  printf("%d %d\n", i, ans[id][i]);
        if(on[i]&& !ans[id][i]){
            id --;  return;
        }
        if(off[i]&&ans[id][i]){
            id--;   break;
        }
    }

}

bool mor(int j, int k){
    int i;

    for(i = 1; i <= n; i++){
        if(ans[j][i] > ans[k][i]) return true;
        if(ans[j][i] < ans[k][i]) return false;
    }
    same[j][k] = same[k][j] = true;

}
int main()
{
//	freopen("lamps.in","r",stdin);
//	#ifndef poi
//	freopen("lamps.out","w",stdout);
//	#endif
	int i, j, t;
	cin >> n >> c;
	while(cin >> t){
        if(t == -1) break;
        on[t] = true;
	}while(cin>>t){
        if(t == -1) break;
        off[t] = true;
	}
	int limit = (1<<4);
    for(i = 0; i < limit; i++){
        //printf("%d\n", i);
        gao(i);
    }
    for(i = 1; i <= id; i++)f[i] = i;
    for(i = 1; i <= id; i++){
        for(j = 1; j <= id-i; j++){
            if(mor(f[j], f[j+1])) swap(f[j], f[j+1]);
        }
    }
    for(i = 1; i <= id; i++){
        if(same[i][i-1])    continue;
        for(j = 1; j <= n; j++){
            printf("%d", ans[f[i]][j]);
        }
        printf("\n");
    }
  //  if(id == 0) printf("IMPOSSIBLE\n");
    return 0;

}
