#include<stdio.h>
#include<math.h>
int main()
{
    int i,N,j;
    long long a;
    int b;
    scanf("%d\n",&N);
    while(N--)    //��˵�ж�EOF����Ҳ�ԣ�����������������������Ŀ������N--�ȽϺ�
    {
        scanf("%lld",&a);   //ϸ�ڣ�long long ����lld���������
        b=(int)sqrt(a); //b�����δ档���Խ��������Ӱ���
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
                    {printf("\n");  break;} //�Ӹ�break   a��1��ʱ��Ϳ��Խ���ѭ���ˡ���ʣ�µĶ���û�õ�
                i--;
            }
        }
        if(a > 1)   printf("%1lld\n", a); //����һ�С��������һ������>bʱ�����������֤�����ʣ�µ�������1������һ����һ����������
    }
    //�����Ǽ��ж�����ɾ���ˡ���ʣ�µ��Ǹ�����һ����һ������������������Լ����ܡ�
    return 0;
 }
