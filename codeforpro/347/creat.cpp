#include<bits/stdc++.h>
using namespace std;
char ch[103];
int main(){
    string inp;
    gets(ch);
    inp = (string)ch;
    //打开文件 输入并创造文件
    FILE *fp = NULL;
    inp= inp + ".cpp";
    int len = inp.length();
    inp.copy(ch, len, 0);
    fp = fopen( ch, "w");
    //cout<<inp<<endl;

    //预置代码
   // if(isdigit(ch[0])){
        fprintf(fp, "#include <bits/stdc++.h>\n");
    //}else{
        //fprintf(fp,"#include <cstring>\n");
        //fprintf(fp,"#include <cstdio>\n");
      //  fprintf(fp,"#include <algorithm>\n");

    //}
    fprintf(fp,"using namespace std;\n");
    //close
    fclose(fp); fp = NULL;


    return 0;
}
