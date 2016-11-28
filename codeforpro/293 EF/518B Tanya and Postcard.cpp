#include <bits/stdc++.h>
using namespace std;
const int N = 55;
const int M  = 200004;
int cnta[N], cntb[N];
char a[M], b[M];
map<char, int >f;

void init(){
    memset(cnta, 0, sizeof(cnta));
    memset(cntb, 0,sizeof(cntb));
    int i;
    int id = 0;
    for(i = 0; i < 26; i++) {
        f['A' + i] = id++;
        f['a' + i] = id++;
    }
}

int main(){
    int i, n;
    scanf("%s%s", a, b);
    init();
    n = strlen(a);
    for(i = 0; i < n; i++)  cnta[f[a[i]]]++;
    n = strlen(b);
    for(i = 0; i < n; i++)  cntb[f[b[i]]]++;
    int ans1 = 0,ans2= 0 ;
    for(i = 0; i < 52; i+= 2){
        if(cntb[i]>=cnta[i] && cntb[i^1]>= cnta[i^1]){
            ans1 += cnta[i];
            ans1 += cnta[i^1];
        }
        else if(cntb[i]<cnta[i] && cntb[i^1]<cnta[i^1]){
            ans1 += cntb[i] ; ans1 += cntb[i^1];
        }
        else {
            if(cntb[i]>=cnta[i]){
                ans1 += (cnta[i] + cntb[i^1]);
                ans2 += min(cntb[i]-cnta[i], cnta[i^1]-cntb[i^1]);
            }
            else {
                ans1 += (cntb[i] + cnta[i^1]);
                ans2 += min(cntb[i^1]-cnta[i^1], cnta[i]-cntb[i]);
            }
        }
    }
    cout<<ans1<<" "<<ans2<<endl;

    return 0;
}
