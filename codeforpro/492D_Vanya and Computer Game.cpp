/********************
 一开始以为是要从1开始依次打这些怪物，是连续关系。。
还看成了A打一下可以掉x点，B打一下掉y点，感觉有些麻烦。
后来发现自己想多了。

打了个表，打怪以lca(x, y)为周期。周期内打个表出来。
表的大小不会超过两倍的max(x,y)
接下来取模就可以了

解释一下表。a每个1/x分钟打 一下可以看做每隔y分钟打一下，同样的变换b
按从小到大的打击顺序打个表
注意爆longlong re了 = =
D. Vanya and Computer Game
**********************/
#include<bits/stdc++.h>
using namespace std;
#define LL __int64
#define N 10000007
int typ[N];
string st[3] = {"Vanya","Vova", "Both"};
int main(void){
    int i, n,  z, j, tot =0;
    LL x, y;
    cin>>n>>x>>y;

    LL m = __gcd(x,y);
    m = x / m * y;
    i = j = 1;
    //0->xy
    typ[0] = 2;
   // cout<<m<<endl;
    while(i * y <= m && j * x <= m){
        if(i * y < j * x){
            typ[++tot] = 0;
            i++;
        }
        else if(j * x < i * y){
            typ[++tot] = 1;
            j++;
        }
        else{
            typ[++tot] = 2;
            break;
        }
        //printf("%d %d %d\n", tot, i, j);
    }
//cout<<tot<<endl;
    tot++;
    while(n--){
        cin>>x;
        cout<<st[typ[x%tot]]<<endl;

    }
}

