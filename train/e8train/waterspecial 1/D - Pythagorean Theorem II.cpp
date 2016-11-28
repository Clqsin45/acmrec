#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;

#define MAX 10004
#define INF 0x7f7f7f7

int f[MAX];
int main(void)
{
    //freopen("out.txt", "w", stdout);
    int i, j, n;
    double x;
    f[0] = f[1] = f[2] = f[3] = f[4] = 0;
    cin>>n;
    for(i = 5; i <= n; i++)
    {
        for(j = i - 1; j >= 1; j--)
        {
            x = sqrt(i * i - j * j);
            if(x > j)   break;
            if(x == ceil(x))
            {
                if((int)x + j > i)  f[i]++;
            }
        }

        f[i] += f[i - 1];
        //printf("%x%s", f[i], i % 10 == 0 ? ",\n" : ",");
    }

    cout<<f[n]<<endl;
    return 0;
}
