#include <stdio.h>
#include <string.h>

char b[120][74], f[120][72], op[10] = {'\0'}, cur[100] = {"http://www.acm.org/"}, d[100] = {'\0'};
int main(void)
{
    int i, topb = 0, topf = 0;
    while(1)
    {
        gets(d);
        for(i = 0; d[i] != '\0' && d[i] != ' '; i++)
            op[i] = d[i];
        op[i] = '\0';

        if(strcmp(op,"BACK") == 0)
        {
            if(topb == 0)   printf("Ignored\n");
            else
            {
                strcpy(f[++topf],cur);
                strcpy(cur,b[topb]);
                topb--;
                printf("%s\n",cur);
            }
        }
        else if(strcmp(op, "QUIT")== 0) break;
        else if(strcmp(op, "FORWARD") == 0)
        {
            if(topf == 0)   printf("Ignored\n");
            else
            {
                strcpy(b[++topb], cur);
                strcpy(cur, f[topf]);
                topf--;
                printf("%s\n",cur);
            }
        }
        else if(strcmp(op,"VISIT") == 0)
        {
            strcpy(b[++topb], cur);
            strcpy(cur, d + i + 1);

            topf = 0;
            printf("%s\n", cur);
            //printf("###\n");
        }
    }

    return 0;
}
