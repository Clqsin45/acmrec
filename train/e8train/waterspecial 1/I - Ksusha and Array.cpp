#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 100005
#define INF 0x7f7f7f7f

int f[MAX];
int gcd(int a, int b)
{
    if(b == 0)  return a;
    return gcd(b, a % b);
}

int main(void)
{

    int n, temp, m = INF, flag = 1, x, y, i;
    cin>>n;

    for(i = 1; i <= n; i++)
    {
        scanf("%d", &f[i]);
        m = min(f[i], m);
    }
    for(i = 1; i <= n; i++)
    {
        if(f[i] % m)
        {
            flag = 0;
            break;
        }
    }
    if(flag)    cout<<m<<endl;
    else cout<<-1<<endl;
    /**************
    if(n == 1)
    {
        cin>>temp;  cout<<temp<<endl;
        return 0;
    }
    cin>>x>>y;  n -= 2;
    lg = gcd(x, y);

    if(lg == x || lg == y)  flag = 1;
    while(n--)
    {
        cin>>temp;
        if(lg == temp)  flag = 1;
        else if(temp % lg == 0) continue;
        lg = gcd(lg, temp);
        if(lg == temp)  flag = 1;
        else flag = 0;
    }
    if(flag)    cout<<lg<<endl;
    else cout<<-1<<endl;
    *********************************/
    return 0;
}
