#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX
#define INF 0x7f7f7f7

__int64 a[100];
int main(void)
{
    __int64 p, q, temp, s1, s2;
    int i, n, flag = 1;
    cin>>p>>q>>n;
    for(i = 1; i <= n; i++)
    {
        scanf("%I64d", &a[i]);
    }
    for(i = 1; i <= n; i++)
    {
        if(p / q < a[i])
        {
            flag = 0;
            break;
        }
        p -= a[i] * q;
        if(p == 0)
        {
            //cout<<i<<endl;
            if(i != n)  flag = 0;
            break;
        }
        temp = p;   p = q;  q = temp;
        //cout<<p<<"  "<<q<<endl;
    }
    if(q != 0 && (p != 0 && i != n))
        flag = 0;
    if(flag)    cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
