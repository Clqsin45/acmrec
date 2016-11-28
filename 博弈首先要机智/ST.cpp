#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<vector>
#define C    240
#define TIME 10
#define inf 1<<25
#define LL long long
using namespace std;
int a[100005],nim[100005];
int main(){
    int t,n,s,w;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&s,&w);
        int g=s,ret=0;
        for(int i=0;i<n;i++){
            a[i]=g;
            if(a[i]==0)  a[i]=g=w;
            if(g%2==0)  g/=2;
            else g=(g/2)^w;
            ret^=a[i];
            nim[i]=ret;
        }
        sort(nim,nim+n);
        LL sum=(LL)n*(n+1)/2;
        int len=1;
        for(int i=1;i<n;i++){
            if(nim[i]==nim[i-1])
                len++;
            else{
                if(nim[i-1]==0)
                    sum-=len;
                sum-=(LL)len*(len-1)/2;
                printf("%d %lld\n", i,sum );
                len=1;
            }
        }
        sum-=(LL)len*(len-1)/2;
        printf("%lld\n",sum);
    }
    return 0;
}
