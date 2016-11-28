#include <stdio.h>
#include <math.h>
int main(void)
{
    char op1, op2;
    double s1, s2, ans, st;
    int c;
    while(scanf("%c", &op1))
    {

        if(op1 == 'E')  break;
        scanf("%lf %c %lf",&s1, &op2, &s2);
        getchar();
        //printf("%c %f  %c %f\n",op1,s1, op2, s2);
        if(op1 == 'H' && op2 == 'D')
            c = 1;
        else if(op1 == 'D' && op2 == 'H')
            c = 2;
        else if(op1 == 'H' && op2 == 'T')
            c = 3;
        else if(op1 == 'D' && op2 == 'T')
            c = 4;
        else if(op1 == 'T' && op2 == 'H')
            c = 5;
        else if(op1 == 'T' && op2 == 'D')
            c = 6;
        switch(c)
        {
            case 1:
                ans=s1-0.5555*(6.11*exp(5417.7530*(1/273.16-1/(s2+273.16)))-10.0);
                printf("T %.1f D %.1f H %.1f\n",ans,s2,s1);
                break;
            case 2:
                ans=s1-0.5555*(6.11*exp(5417.7530*(1/273.16-1/(s2+273.16)))-10.0);
                printf("T %.1f D %.1f H %.1f\n",ans,s1,s2);
                break;
            case 3:
                ans=1/(1/273.16-log(((s1-s2)/0.5555+10)/6.11)/5417.753)-273.16;
                printf("T %.1f D %.1f H %.1f\n",s2,ans,s1);
                break;
            case 4:
                ans=s2+0.5555*(6.11*exp(5417.7530*(1/273.16-1/(s1+273.16)))-10.0);
                printf("T %.1f D %.1f H %.1f\n",s2,s1,ans);
                break;
            case 5:
                ans=1/(1/273.16-log(((s2-s1)/0.5555+10)/6.11)/5417.753)-273.16;
                printf("T %.1f D %.1f H %.1f\n",s1,ans,s2);
                break;
            case 6:
                ans=s1+0.5555*(6.11*exp(5417.7530*(1/273.16-1/(s2+273.16)))-10.0);
                printf("T %.1f D %.1f H %.1f\n",s1,s2,ans);
                break;
        }
    }

    return 0;
}
