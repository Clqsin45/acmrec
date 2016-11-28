#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 10005
#define INF 0x3f7f7f7f
int ct[11];
int v[MAX];

void getsum(int x)
{
    while(x > 0)
    {
        ct[x % 10] ++;
        x /= 10;
    }
}


int main(void)
{
    int TC, ls, temp, s, e, g, sa, sg, i;
    char sn[100], ch, st[MAX];

    scanf("%d", &TC);        while(ch != '\n') ch = getchar();

    while(TC--)
    {
        gets(sn);
       // ls = strlen(sn);
       // i = ls - 1;
        //while(sn[i] == ' ') {sn[i] = '\0'; i--;}

        memset(ct, 0, sizeof(ct));
        memset(v, 0, sizeof(v));
        sa = sg = 0;

        scanf("%d", &ls);
        while(getchar() != '\n');
        while(ls--)
        {
            while(scanf("%c", &ch)) if(ch != ' ')break ;
           // printf("%d\n", ch);
            if(ch == '+')
            {
                scanf("%d%d%d", &s, &e, &g);
                for(i = s; i <= e; i += g)
                {
                    if(v[i] < 0)    continue;
                    v[i] =  1;
                }
                gets(st);
            }
            else if(ch == '-')
            {
                scanf("%d%d%d", &s, &e, &g);
                for(i = s; i <= e; i += g)
                {
                    v[i] = -1;
                    //printf("%d\n", i);
                }
                //while(getchar() != '\n');
                gets(st);
            }
            else if(ch >= '0' && ch <= '9')
            {
                temp = ch - '0';
                while(scanf("%c", &ch))
                {
                    if(ch == '\n' || ch == ' ') break;
                    temp = temp * 10 + ch - '0';
                }
                while(ch != '\n') ch = getchar();
                v[temp] = true;
            }


        }
        for(i = 1; i < 10000; i++)
        {
            if(v[i] <= 0)   continue;
            //printf("%d\n", i);
            getsum(i);      sa ++;
        }
        /********
        i = 0;
        while(sn[i] != '\0')    {
            printf("%c", sn[i]);    i++;
        }

        printf("\n");
        ********/
        puts(sn);
        if(sa <= 1) printf("%d address\n", sa);
        else printf("%d addresses\n", sa);

        for(i = 0; i <= 9; i++)
        {
            printf("Make %d digit %d\n", ct[i], i);
            sg += ct[i];
        }
        //if(sg > 1)
            printf("In total %d digits\n", sg);
        //else printf("In total %d digit\n", sg);

    }
    return 0;
}
