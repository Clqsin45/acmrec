#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

#define MAX 100002
#define INF 0x7f7f7f7f
set<int>s;
int main(void)
{
    int n, i, temp, m = 0;
    cin>>n;
    for(i = 1; i <= n; i++)
    {
        cin>>temp;
        while(s.count(temp))   s.erase(temp++);
        s.insert(temp);
        m = m > temp ? m : temp;
    }
    cout<<m - s.size() + 1<<endl;
    return 0;
}
