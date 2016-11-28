#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

#define MAX 1001
#define INF 0x3f7f7f7f
map<string, int>m;
string s[MAX];
int v[MAX];

int main(void)
{
    int ans = -INF, i, n;
    string name;
    cin>>n;
    for(i = 1; i <= n; i++)
    {
        cin>>s[i]>>v[i];
        m[s[i]] += v[i];
    }
    for(i = 1; i <= n; i++)
    {
        ans = max(ans, m[s[i]]);
    }
    for(i = 1; i <= n; i++)
    {

    }
    cout<<name<<endl;
    return 0;
}
