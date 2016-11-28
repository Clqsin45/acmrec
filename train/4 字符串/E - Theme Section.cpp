#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 1000005
#define INF 0x3f7f7f7f

int next[MAX], l;
char p[MAX];

void getnext()
{
    int i = 0, j = -1;
    memset(next, 0, sizeof(next));
    next[0] = -1;
    while(i < l)
    {
        if(j == -1 || p[i] == p[j])
        {
            i++;    j++;
            if(p[i] != p[j])    next[i] = j;
            else next[i] = next[j];
        }
        else j = next[j];
    }
}

bool check(int x)
{
    int j = x, i = 0;
    while(i < l)
    {
        if(i == -1 || p[i] == p[j])
        {
            i++;    j++;
            if(i == x)  return true;
        }
        else i = next[i];
    }
    return false;
}

int main(void)
{
    int CT, i, ts, ans;
    scanf("%d", &CT);
    while(CT --)
    {
        scanf("%s", p);     l = strlen(p);
        getnext();
        //printf("~~\n");
        ans = l;
        while(ans > (l / 3))  ans = next[ans];

        while(ans > 0)
        {
            if(check(ans))    break;
            ans = next[ans];
            //printf("!!%d\n", ans);
        }
        if(ans == -1)   printf("%d\n", l / 3);
        else printf("%d\n", ans);

    }
    return 0;
}
