#include <stdio.h>
#include <algorithm>
using namespace std;

int a[4];
int main(void)
{
    int n = 0, t, sign , st, i , j;
    while(scanf("%d%d%d%d", &a[0],&a[1],&a[2],&a[3]) && (a[0] || a[1] || a[2] || a[3]))
    {
        if(n)   printf("\n");
        n ++;
        for(i = 0; i < 4; i++)
        {
             for(j = 0; j < 3 - i; j++ )
            {
                if(a[j] > a[j + 1])
                {
                    t = a[j];   a[j] = a[j + 1]; a[j + 1] = t ;
                }
            }
        }
        sign = 1;   st = -1;
        do
        {

            if(!a[0]) continue;
            if(sign)
            {
                printf("%d%d%d%d",a[0],a[1],a[2],a[3]);
                sign = 0;
            }
            else if(a[0] == st)
                printf(" %d%d%d%d",a[0],a[1],a[2],a[3]);
            else
                printf("\n%d%d%d%d",a[0],a[1],a[2],a[3]);
            st = a[0];
        }while(next_permutation(a, a+4));
        printf("\n");

    }
    return 0;
}
