#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX
#define INF 0x7f7f7f7



int a[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
int y1, y2, m1, m2, d1, d2;
bool judge(int x)
{
    if((x % 4 == 0 && x % 100 != 0) || x % 400 == 0)    return true;
    return false;
}

int main(void)
{
    int i, j, ans1 = 0, ans2 = 0, temp, x;
    scanf("%d:%d:%d", &y1, &m1, &d1);
    scanf("%d:%d:%d", &y2, &m2, &d2);
    x = judge(y1);
    for(i = 1, temp = 0; i < m1; i++)   temp += a[x][i];
    temp += d1;
    ans1 = 365 + x - temp;

    for(i = y1 + 1; i <=2039; i++)
    {
        ans1 += (365 + judge(i));
    }

    x = judge(y2);
    for(i = 1, temp = 0; i < m2; i++)   temp += a[x][i];
    temp += d2;
    ans2 = 365 + x - temp;

    for(i = y2 + 1; i <=2039; i++)
    {
        ans2 += (365 + judge(i));
    }

    temp = ans1 - ans2;
    if(temp < 0)    temp = -temp;
    cout<<temp<<endl;


    return 0;
}
