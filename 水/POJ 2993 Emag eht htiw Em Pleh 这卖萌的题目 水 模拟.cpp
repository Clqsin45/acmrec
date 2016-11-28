#include <stdio.h>
#include <ctype.h>
#include <string.h>
char c[10][80] = {{'\0'},{"|:::|...|:::|...|:::|...|:::|...|"},{"|...|:::|...|:::|...|:::|...|:::|"},
                         {"|:::|...|:::|...|:::|...|:::|...|"},{"|...|:::|...|:::|...|:::|...|:::|"},
                         {"|:::|...|:::|...|:::|...|:::|...|"},{"|...|:::|...|:::|...|:::|...|:::|"},
                         {"|:::|...|:::|...|:::|...|:::|...|"},{"|...|:::|...|:::|...|:::|...|:::|"}};
int main(void)
{
    int st1, st2, i, l;
    char gap[80] = {"+---+---+---+---+---+---+---+---+"}, del[80] = {'\0'}, cinp;
    gets(del);
    l = strlen(del);
    for(i = 7;;)
    {
        if(del[i + 3] == ',')
        {
            cinp = del[i];  st1 = del[i + 1]-'a'+1; st2 = del[i+2] - '0';
            i+=4;
        }
        else if(del[i+2] == ',' || del[i + 2] == '\0')
        {
            cinp = 'P'; st1 = del[i]-'a'+1; st2 = del[i+1] - '0';
            i+=3;
        }
        c[st2][-2+4 * st1] = cinp;
        if(i > l)  break;
    }
    memset(del, '\0', sizeof(del));
    gets(del);
    l = strlen(del);
    for(i = 7; ;)
    {
        if(del[i + 3] == ',')
        {
            cinp =  tolower(del[i]);  st1 = del[i + 1]-'a'+1; st2 = del[i+2] - '0';
            i+=4;
        }
        else if(del[i+2] == ',' || del[i + 2] == '\0')
        {
            cinp = 'p'; st1 = del[i]-'a'+1; st2 = del[i+1] -'0';
            i+=3;
        }
        c[st2][-2 + 4 * st1] = cinp;
        if(i > l)  break;
    }
    for(i = 8; i >= 1; i--)
    {
        printf("%s\n%s\n", gap, c[i]);
    }
    printf("%s\n",gap);

    return 0;
}
