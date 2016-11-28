#include <iostream>
#include <stack>
#include <stdio.h>
using namespace std;
int a[44], c[22];
stack<int> s;
int main(void)
{
    int t, now, n, i, top;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for( i = 1; i <= n; i++)     cin>>c[i];
        now = 1;    top = 0;
        for(i = 1; i <= 2 * n;)
        {
            while(i - now + 1 <= c[now])
                a[i ++ ] = 0;
            a[i++] = 1;   now++;
        }
        for(i = 1; i <= 2 * n; i++)
        {
            if(!a[i])   s.push(i);
            else
            {
                int st = s.top();
                s.pop();
                printf("%d%c",(i - st + 1) / 2, i != 2 * n ? ' ' : '\n');
            }
        }
    }
    return 0;
}
