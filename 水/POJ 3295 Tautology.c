#include <stdio.h>
#include <string.h>

char a[1002], changechar[3];
int time, change[202] = {-1};
int main(void)
{
    freopen("in.txt", "r", stdin);
    int top, i;
    change['p'] = 0;    change['q'] = 1;
    changechar[1] = 'q';    changechar[0] = 'p';
    while(scanf("%s", a))
    {
        time = 0;
        if(strcmp(a, "0") == 0)    break;
        top = strlen(a) - 1;

    }
    return 0;
}
