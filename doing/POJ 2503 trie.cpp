#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 150005
#define INF 0x7f7f7f7
struct trie
{
    int next[26], dep;
    char word[12];
}t[MAX];

int num = 0;

void insert(char a[], char b[])
{
    int now = 0, i, j, lb = strlen(b);
    for(i = 0; i < lb; i++)
    {
        if(t[now].next[b[i] - 'a'] == -1)
        {
            num++;
            for(j = 0; j < 26; j++)
                t[num].next[j] = -1;
            t[num].dep = 0;
            t[now].next[b[i] - 'a'] = num;
        }
        now = t[now].next[b[i] - 'a'];
    }
    strcpy(t[now].word, a);
    t[now].dep = 1;
}

int find(char temp[])
{
    int now = 0, i, lt = strlen(temp);
    for(i = 0; i < lt; i++)
    {
        now = t[now].next[temp[i] - 'a'];
        if(now == -1)
            return 0;
    }
    if(t[now].dep)
    {
        printf("%s\n", t[now].word);
        return 1;
    }
    return 0;
}

int main(void)
{
    char a[11], b[11];
    int i, j;
    for(i = 0; i < 26; i++)
        t[0].next[i] = -1;

    while(scanf("%s", a) && getchar()==' ')
    {
        scanf("%s", b);
        insert(a, b);
    }
    do
    {
        if(find(a) == 0)
            printf("eh\n");
    }while(scanf("%s", a) != EOF);


    return 0;
}
