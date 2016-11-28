#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 1004
#define INF 0x7f7f7f7

struct tree
{
    int next[26], no;
    bool sign;
}t[MAX * 100];
int l, c, w, num = 0;
char m[MAX][MAX];

struct point
{
    char s[MAX], dir;
    bool sign;
    int ansx, ansy;
}f[MAX];

int go[2][10] = {{-1, -1, 0, 1, 1, 1, 0, -1}, {0, 1, 1, 1, 0, -1, -1, -1}};


void init(int x)
{
    int i;
    for(i = 0; i < 26; i++)
        t[x].next[i] = -1;
    t[x].sign = false;
    return;
}

inline bool judge(int x, int y)
{
    return x >= 1 && y >= 0 && x <= l && y < c;
}

void insert(char a[], int k)
{
    int now = 0, i, la = strlen(a), temp;
    for(i = 0; i < la; i++)
    {
        temp = a[i] - 'A';
        if(t[now].next[temp] == -1)
        {
            num++;
            init(num);
            t[now].next[temp] = num;
        }
        now = t[now].next[temp];
    }
    //cout<<a<<"  "<<now<<endl;
    t[now].sign = true;
    t[now].no = k;
    return;
}

void find(int x, int y)
{
    int i, j, k, xx, yy, now = 0;
    char v;
    for(i = 0 ; i < 8; i++)
    {
        now = 0;
        for(j = 0; j < MAX ; j++)
        {
            xx = x + go[0][i] * j;
            yy = y + go[1][i] * j;

            if(!judge(xx, yy))  break;

            v = m[xx][yy] - 'A';
            //cout<<v+'A'<<endl;
            if(t[now].next[v] == -1)   break;
            now = t[now].next[v];
            if(t[now].sign)
            {
                k = t[now].no;
                if(f[k].sign)   continue;
                f[k].ansx = x;
                f[k].ansy = y;
                f[k].dir = i;
                f[k].sign = true;
            }
        }
    }
}

int main(void)
{
    //freopen("out.txt", "w", stdout);
    int i, j, k, t;
    cin>>l>>c>>w;
    init(0);

    for(i = 1; i <= l; i++)
        scanf("%s",  m[i]);
    for(i = 1; i <= w; i++)
    {
        scanf("%s", f[i].s);
        insert(f[i].s, i);
        f[i].sign = 0;
    }
    for(i = 1; i <= l; i++)
    {
        for(j = 0; j <  c; j++)
        {
            find(i, j);
        }
    }

    for(i = 1; i <= w; i ++)
    {
        //printf("%")
        printf("%d %d %c\n", f[i].ansx - 1, f[i].ansy, f[i].dir + 'A');
    }
    return 0;
}
