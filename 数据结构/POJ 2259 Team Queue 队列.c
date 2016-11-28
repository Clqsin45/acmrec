#include <stdio.h>
#include <string.h>
int b[1000002], ed[1002], q[1000000];
int main(void)
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, n, f, r, i, a, j, ct = 1;
    char op[10];
    while(scanf("%d", &t) && t)
    {
        f = 1;  r = 0;
        for(i = 1; i <= t; i++)
        {
            scanf("%d", &a);
            for(j = 1; j <= a; j++)
            {
                scanf("%d", &n);
                b[n] = i;
            }
            ed[i] = -1;
        }
        printf("Scenario #%d\n",ct);
        while(1)
        {
            scanf("%s", op);
            if(strcmp(op, "STOP") == 0) break;
            else if(strcmp(op, "DEQUEUE") == 0)
            {
                if(ed[b[q[f]]] == f)
                {
                    ed[b[q[f]]] = -1;
                }
                printf("%d\n",q[f]);
                f++;
            }
            else
            {
                scanf("%d", &n);
                if(ed[b[n]] == -1 || ed[b[n]] == r)
                {
                    q[++r] = n;
                    ed[b[n]] = r;
                }
                else
                {
                    for(i = r; i >= ed[b[n]] + 1; i--)
                    {
                        //printf("@@@%d   %d\n", b[q[i+1]], b[q[i]]);
                        if(b[q[i + 1]] != b[q[i]])
                        {
                            ed[b[q[i]]]++;
                        }

                        q[i + 1] = q[i];
                    }
                    q[ed[b[n]] + 1] = n;
                    ed[b[n]]++;
                    r++;
                }
               // for(i = f; i <= r; i++) printf("%d   %d\n", i, q[i]);
            }

        }
        memset(q, -1, sizeof(q));
        printf("\n");
        ct ++;
    }
    return 0;
}
