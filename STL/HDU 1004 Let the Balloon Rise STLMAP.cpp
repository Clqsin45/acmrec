#include <iostream>
#include <string.h>
#include <map>
using namespace std;
int main(void)
{
    int n, i, max;
    string st, op;
    map<string, int>b;
    while(cin>>n && n)
    {
        b.clear();  max = 0;
        for(i = 1; i <= n; i++)
        {
            cin>>op;
            b[op]++;
            if(b[op] > max)
            {
                max = b[op];
                st = op;
            }
        }
        cout<<st<<endl;
    }

    return 0;
}
