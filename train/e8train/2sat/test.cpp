#include<stdio.h>
#include<math.h>
int main()
{
    int i,N,j;
    long long a;
    int b;
    scanf("%d\n",&N);
    while(N--)    //虽说判断EOF可能也对，但是遇到给出样例数的题目，还是N--比较好
    {
        scanf("%lld",&a);   //细节：long long 是用lld输入输出的
        b=(int)sqrt(a); //b用整形存。。对结果不会有影响的
        printf("%lld = ",a);
        for (i=2;i<=b;i++)
        {
            if(a%i==0)
            {
                a=a/i;
                printf("%1d",i);
                if(a>1)
                    {printf(" * ");}
                if(a==1)
                    {printf("\n");  break;} //加个break   a是1的时候就可以结束循环了。。剩下的都是没用的
                i--;
            }
        }
        if(a > 1)   printf("%1lld\n", a); //加这一行。。如果有一个因数>b时就输出，可以证明如果剩下的数不是1，那他一定是一个素数。。
    }
    //后面那几行都给你删掉了。。剩下的那个数字一定是一个素数。。具体可以自己感受。
    return 0;
 }
