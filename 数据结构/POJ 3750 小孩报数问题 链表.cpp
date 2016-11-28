#include <stdio.h>
#include <stdlib.h>
struct node
{
    char a[22];
    struct node * next;
};
typedef struct node *NODE;
int main(void)
{
    int n, w, g, ct, i, sign = 0;
    NODE beg, p, s;
    scanf("%d", &n);
    ct = n;
    p = (NODE) malloc(sizeof(node));  beg = p;
    for(i = 1; i <= n; i++)
    {
        scanf("%s", p->a);
        if(i == n)
        {
            p->next = beg;
            break;
        }
        s = (NODE) malloc(sizeof(node));
        p->next = s;
        p = s;
    }
    scanf("%d,%d",&w, &g);
    s = p;  p = beg;
    for(i = 1; i < w; i++)
    {
        s = p;  p = p->next;
    }
    while(n--)
    {
        for(ct = 1;  ; ct++)
        {
            if(ct == g)
            {
                printf("%s\n",p->a);
                s->next = p->next;
                p = s->next;
                break;
            }
            else
            {
               s = p; p = p->next;
            }
        }
    }
    return 0;
}
