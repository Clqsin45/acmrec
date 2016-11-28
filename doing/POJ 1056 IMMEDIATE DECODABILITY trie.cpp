#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 70000
#define INF 0x7f7f7f7f

struct trie
{
    int next[14], num;
    bool sign;
}t[MAX];
int num = 0;

void init(void)
{
    int i;
    num = 0;
    for(i = 0; i < 10; i++)
        t[num].next[i] = -1;
    t[num].sign = 0;
}

bool insert(char a[])
{
    int now = 0, la = strlen(a), i, j;
    int temp;
    bool flag = 0;
    for(i = 0; i < la; i++)
    {
        temp = a[i] - '0';
        if(t[now].sign)
             return 0;
        //cout<<now<<t[now].next[temp]<<endl;
        if(t[now].next[temp] == -1)
        {
            num++;  flag = 1;
            t[num].sign = 0;
            for(j = 0; j < 10; j++) t[num].next[j] = -1;
            t[now].next[temp] = num;
        }
        now = t[now].next[temp];
    }
    t[now].sign = 1;
    //printf("%d\n", now);
    return flag;
}


int main(void)
{
    char c[14];
    int flag = 1, TC = 1;
    init();
    while(scanf("%s", c) != EOF)
    {
        if(c[0] == '9')
        {
            init();
            if(flag)    printf("Set %d is immediately decodable\n", TC++);
            else printf("Set %d is not immediately decodable\n", TC++);
            flag = 1;
            continue;
        }
        //printf("%d\n", insert(c));
        if(insert(c))   continue;
        flag = 0;
    }
    return 0;
}
