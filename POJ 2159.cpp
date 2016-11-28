#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
char a[120], b[120];
bool cmp(int a, int b)
{
    return a > b;
}
int main(void)
{
    int l1, l2, i;
    int c1[160] = {0}, c2[160] = {0};
    scanf("%s%s",a,b);
    l1 = strlen(a); l2 = strlen(b);
    if(l1 != l2)
    {
        printf("NO\n");
        return 0;
    }
    for(i = 0 ; i < l1; i++)
    {
        c1[a[i]]++;     c2[b[i]]++;
    }
    sort(c1,c1+160,cmp);
    sort(c2,c2+160,cmp);
    for(i = 0; i < 160 ; i++)
	{
		if(c1[i]!=c2[i])
		{
			printf("NO\n");
			return 0;
		}
		else if(c1[i] == 0 || c2[i] == 0)
			break;
	}
	printf("YES\n");
    return 0;
}
