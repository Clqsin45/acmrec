#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <iterator>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>
using namespace std;

typedef __int64 LL;
const int N=1000005;
const LL II=1000000007;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);

char word[2*N],s1[N],s2[N];
int len,next[2*N];

void getnext(char *p,int wlen)
{
    int j=0,k=-1;
    next[0]=-1;
    while(j<wlen)
    {
        if(k==-1||p[j]==p[k])
        {
            j++;    k++;
            next[j]=k;
        }
        else
            k=next[k];
    }
}

int main()
{
    int ca=0,i,j,T;
    scanf("%d",&T);
    while(T--)
    {
        int len1,len2,t1,t2;
        scanf("%s%s",s1,s2);
        len1=strlen(s1);
        len2=strlen(s2);
        len=len1+len2;

        strcpy(word,s1);
        strcat(word,s2);
        word[len]='\0';
        getnext(word,len);
        t1=next[len];
        while(t1>len1)
            t1=next[t1];

        strcpy(word,s2);
        strcat(word,s1);
        word[len]='\0';
        getnext(word,len);
        t2=next[len];
        while(t2>len2)
            t2=next[t2];

        t1=max(t1,t2);
        printf("%d\n",len-t1);
    }
    return 0;
}
