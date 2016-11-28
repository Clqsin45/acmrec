#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;
#define MAX 1111111
char s[MAX];
stack<char>Sta;
bool judge(char c)
{
    return c >= 'A' && c <= 'Z';
}

int main(void)
{
    int T, i, j, flag, base, row, col;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", s);
        i = 0;
        while(judge(s[i]))  i++;
        j = i - 1;    flag = 1;
        while(s[i] != '\0')
        {
            if(judge(s[i]))
            {
                flag = 0;
                break;
            }
            i++;
        }

        if(flag)
        {
            for(i = j, col = 0, base = 1; i >= 0; i--, base *= 26)
            {
                col += base * (s[i] - 'A' + 1);
            }
            printf("R%sC%d\n",s + j + 1, col);

        }
        else
        {
            for(i = 1, row = 0; s[i] != 'C'; i++)
                row = row * 10 + s[i] - '0';
            for(i = i + 1, col = 0; s[i] != '\0'; i++)
                col = col * 10 + s[i] - '0';

            while(col >= 1)
            {
                j = col % 26;
                if(j)
                //printf("%d  %d  %c\n", col, col % 26, col % 26 + 'A' - 1);
                    Sta.push(col % 26 + 'A' - 1);
                else
                {
                    Sta.push('Z');
                    col--;
                }


                col /= 26;
            }
            while(!Sta.empty())
            {
                printf("%c", Sta.top());
                Sta.pop();
            }
            printf("%d\n",row);
        }
    }
    return 0;
}

//R288C494
