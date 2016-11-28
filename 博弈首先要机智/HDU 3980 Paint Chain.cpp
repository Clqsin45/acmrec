#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N  =  1004;
int m;
int f[N];
void dfs(int x){
    if(f[x]  != -1) return;
    if(x < m){
        f[x] = 0;   return;
    }
    int i;
    bool hash[N];   memset(hash, 0, sizeof(hash));

    for(i = 1; i <= x; i++){
        if(i+m-1>x) break;
        dfs(i-1);  dfs(x-i-m+1);
        int temp = f[i-1]^f[x-i-m+1];
        hash[temp] = true;
    }
    for(i = 0;hash[i]; i++)   ;
    f[x] = i;
    return ;
}

int main(){
    int n,  i, j, x, y, TC,tc;
    scanf("%d" , &TC);
    for(tc = 1; tc<= TC; tc++){
        printf("Case #%d: ", tc);
        scanf("%d%d", &n, &m);
        memset(f, -1, sizeof(f));   f[0] = 0;
        if(n < m){
            printf("abcdxyzk\n");
            continue;
        }dfs(n-m);
        printf("%s\n",f[n-m]   ? "abcdxyzk":"aekdycoin");
    }
    return 0;
}
