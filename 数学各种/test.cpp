#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct
{
    long long d;
    long long x;
    long long y;
} NODE;
NODE gcd(long long a,long long b)
{
    NODE s,p;
    if(!b)
    {
        s.x=1;
        s.y=0;
        s.d=a;
        return s;
    }
    s=gcd(b,a%b);
    p.x=s.x;
    s.x=s.y;
    s.y=p.x-(a/b)*s.y;
    return s;

}
long long max(long long a,long long b)
{
    return a>b?a:b;
}
long long min(long long a,long long b)
{
    return a<b?a:b;
}

int main(void)
{
    long long a,b,c,x1,x2,y1,y2,ll,rr,tt;
    scanf("%lld%lld%lld",&a,&b,&c);
    scanf("%lld%lld",&x1,&x2);
    scanf("%lld%lld",&y1,&y2);
    if(a==0&&b==0)
    {
        if(!c)printf("%lld\n",(x2-x1+1)*(y2-y1+1));
        else
            printf("0\n");
    }
    else if(a==0&&b!=0)
    {
        if(c%b==0&&(c/b)>=y1&&(c/b)<=y2)
            printf("%lld\n",x2-x1+1);
        else
            printf("0\n");
    }
    else if(a!=0&&b==0)
    {
        if(c%a==0&&(c/a)>=x1&&(c/a)<=x2)
            printf("%lld\n",y2-y1+1);
        else
            printf("\n");
    }
    else
    {
        c=-c;
        if(c<0)
        {
            a=-a;
            b=-b;
            c=-c;
        }
        if(a<0)
        {
            a=-a;
            tt=x1;
            x1=-x2;
            x2=-tt;
        }
        if(b<0)
        {
            b=-b;
            tt=y1;
            y1=-y2;
            y2=-tt;
        }
        NODE s=gcd(a,b);
        if(c%s.d)
            printf("0\n");
        else
        {

            s.x*=(c/s.d);
            s.y*=(c/s.d);
            //printf("%lld %lld\n",s.x,s.y);
            ll=max(ceil((double)(x1-s.x)*s.d/b),ceil((double)(s.y-y2)*s.d/a));
            rr=min(floor((double)(x2-s.x)*s.d/b),floor((double)(s.y-y1)*s.d/a));
            if(ll>rr)
                printf("0\n");
            else
                printf("%lld\n",rr-ll+1);
        }
    }
    return 0;
}
