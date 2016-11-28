#include <cstring>
#include <cstdio>
#include <algorithm>
#include<cmath>
using namespace std;
const int N = 5000005;
const int MAX = 5000000;
const int M = 100005;
bool flag[N];
int p[N], f[M], s[M];

void init()
{
    int i, cnt = 0, j;
    for(i = 2; i <= 5000000; i++)
    {

        if(!flag[i])    p[cnt++] = i;
        for(j = 0; j < cnt && i * p[j] <= MAX; j++)
        {
            flag[i * p[j]] = true;
            if(i % p[j] == 0)   break;
        }
    }
   // printf("%d\n", p[0]);

}

int find(int x){
    if(f[x] != -1)return f[x];

    int i, cnt = 0, n = x, m = sqrt(x) + 1;
    for(i = 0; x != 1 && p[i] <= m; i++){
        while(x % p[i] == 0){
            cnt ++;
            x /= p[i];
        }
    }
    if(x!= 1)cnt++;
    return f[n] = cnt;
}

int  main(){
    int n, ans, i, temp,x,  tc = 0;
    init();
    memset(f, -1, sizeof(f));
    while(scanf("%d", &n) != EOF){
        ans = 0;
        for(i = 1; i <= n; i++){
            scanf("%d", &x);
            s[i] = find(x);
            ans ^= s[i];
        }
        printf("Test #%d: ", ++tc);
        if(ans) {
            for(i = 1; i <= n; i++){
                temp = ans ^ s[i];
                if(temp <= s[i]){
                    printf("Alice %d\n", i);
                    break;
                }
            }
        }
        else printf("Bob\n");
    }
    return 0;

}
