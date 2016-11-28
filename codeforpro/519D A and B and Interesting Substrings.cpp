#include <bits/stdc++.h>
using namespace std;
typedef __int64 ll;

const int N = 100004;
map<ll, int>f[26];
int dir[40];
char ch[N];

int main(){
    int i, j, n;
    ll sum = 0;
    for(i = 0; i < 26; i++)scanf("%d", &dir[i]);
    scanf("%s", ch);
    ll ans = 0;
    for(i = 0; i < 26; i++)f[i].clear();
    for(i = 0; ch[i] != '\0'; i++){
        j = ch[i] - 'a';
        ans += f[j][sum];
        sum += dir[j];
        f[j][sum]++;
    }
    printf("%I64d\n", ans);
    return 0;
}
