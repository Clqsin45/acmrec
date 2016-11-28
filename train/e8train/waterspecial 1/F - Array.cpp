#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

#define MAX
#define INF 0x7f7f7f7

vector<int>v[4];
vector<int>p;
vector<int>n;

int main(void)
{
    int x, i, flag = 0,temp;
    cin>>x;
    for(i = 1; i <= x; i++)
    {
        cin>>temp;
        if(temp > 0)
        {
            if(flag)    v[2].push_back(temp);
            else
            {
                p.push_back(temp);
                flag = 1;
            }
        }
        else if(temp == 0)
        {
            v[2].push_back(temp);
        }
        else
        {
            n.push_back(temp);
        }

    }
    if(!flag)
    {
        v[1].push_back(n[0]);   v[1].push_back(n[1]);
        v[0].push_back(n[2]);
        for(i = 3; i < n.size(); i++)
        {
            v[2].push_back(n[i]);
        }
    }
    else
    {
        v[0].push_back(n[0]);
        v[1].push_back(p[0]);
        for(i = 1; i < n.size(); i++)
        {
            v[2].push_back(n[i]);
        }
    }
    for(i = 0; i < 3; i++)
    {
        x = v[i].size();
        printf("%d",x);
        for(int j = 0; j < x; j++)
            printf(" %d", v[i][j]);
        printf("\n");
    }
    return 0;
}
