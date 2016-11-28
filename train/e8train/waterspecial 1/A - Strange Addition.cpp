#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define MAX
#define INF 0x7f7f7f7

vector<int>ans;
int f[5];
int main(void)
{
    int n, temp, i;
    memset(f, 0, sizeof(f));
    cin>>n;
    while(n--)
    {
        scanf("%d", &temp);
        if(temp == 0)   ans.push_back(0);
        else if(temp < 10)
        {
            if(f[0])    continue;
            else f[0] = temp;
        }
        else if(temp < 100)
        {
            if(temp % 10 == 0)
            {
                if(f[1])    continue;
                f[1] = temp;
            }
            else
            {
                if(f[3])    continue;
                f[3] = temp;
            }
        }
        else f[2] = temp;
    }
//    for(i = 0; i < 4; i++)
//        cout<<f[i]<<endl;
    if(f[3])
    {
        if(f[1] && f[0])
        {
            ans.push_back(f[1]);
            ans.push_back(f[0]);
        }
        else ans.push_back(f[3]);
    }
    else
    {
        if(f[1])    ans.push_back(f[1]);
        if(f[0])    ans.push_back(f[0]);
    }
    if(f[2])
        ans.push_back(f[2]);

    cout<<ans.size()<<endl;
    for(i = 0; i < ans.size(); i++)
        printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');



    return 0;
}
