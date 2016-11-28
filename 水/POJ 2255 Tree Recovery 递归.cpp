#include <stdio.h>
#include <string.h>

char a[40], b[40];
int lt, no;

void find(int l, int r)
{
    no++;
    int i = l;
    while(a[no] != b[i]) i++;

    if(l <= i - 1)  find(l, i - 1);
    if(i + 1 <= r)  find(i + 1, r);
    printf("%c", b[i]);
    if(l == r)  return;
}

int main(void)
{
    while(scanf("%s%s", a, b) != EOF)
    {
        lt = strlen(a);
        no = -1;
        find(0, lt - 1);
        printf("\n");
    }
    return 0;
}
