#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int N = 1000005;
int f[N];

int cal(int x){
    int i = 0;
    while(x){
        i++;
        x/= 10;
    }
    return i;
}
int dfs(int x){
    if(f[x] != -1)  return f[x];
   // printf("%d")
    int len = cal(x), nowlen = 0;
    int i, j, k, temp;
    bool flag = false;
    for(i = 1; i <= x; i *= 10){
         nowlen ++;
         temp = x / i;  temp %= 10;
         if(temp == 0){
            if(!dfs(x/i/10)) flag = true;
            continue;
         }
         for(j = 1; j <= temp; j++){
            k = x - j * i;
            if(j == temp && nowlen == len)  continue;
         //   printf("%d %d\n", x, k);
            if(!(dfs(k))) flag  = true;
         }
    }
    if(flag)return f[x] = 1;
    return f[x] = 0;
}

int main(){
    //freopen("out.txt","w", stdout);
    int n, i, j, temp;
    memset(f, -1, sizeof(f));
    char ch[10];    f[0] = 1;
    for(i = 1; i < 1000000; i++)  {
        f[i] = dfs(i);
    //    if(f[i] == 0) printf("%d\n", i);
    }
    while(scanf("%s", ch) != EOF){
        if(ch[0] == '0'){
            printf("Yes\n");
            continue;
        }
        n = atoi(ch);
        printf("%s\n", f[n] ? "Yes" :"No");
    }
    return 0;
}
