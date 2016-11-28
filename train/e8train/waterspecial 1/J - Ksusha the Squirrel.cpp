#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX
#define INF 0x7f7f7f7f


int main(void)
{
    int n, k, i, sum = 0, m = 0;
    char temp;
    cin>>n>>k;
    for(i = 1; i <= n; i++)
    {
        cin>>temp;
        if(temp == '.')
        {
            m = max(m, sum);
            sum = 0;
        }
        else    sum++;
    }
    if(m <= k - 1)    cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
