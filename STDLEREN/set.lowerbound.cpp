// set::lower_bound/upper_bound
#include <iostream>
#include <set>

int main ()
{
  std::set<int> myset;
  std::set<int>::iterator itlow,itup;

  for (int i=1; i<10; i++) myset.insert(i*10); // 10 20 30 40 50 60 70 80 90

  itlow=myset.lower_bound (100);                //       ^
  itup=myset.upper_bound (90);                 //                   ^
  std::cout<<(itlow == myset.end())<<'\n';
  myset.erase(itlow,itup);                     // 10 20 70 80 90

  std::cout << "myset contains:";
  for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}

//upperbound 输出比查询大的最小值。如果没有返回end()的位置
//lowerbound 输出大于等于的最左。若没有返回end()
