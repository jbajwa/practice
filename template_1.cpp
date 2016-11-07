#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
void print_list(vector<T> t_v)
{
  typename vector<T>::iterator itr;
  for ( itr = t_v.begin() ; itr < t_v.end(); itr++) {
     cout<<*itr<<endl;
  }
}

int main() {
  vector<int> int_v{2,8,19};

  vector<string> str_v{"hey", "my", "name"};

  print_list<int>(int_v);
  print_list<string>(str_v);

  return 0;
}
