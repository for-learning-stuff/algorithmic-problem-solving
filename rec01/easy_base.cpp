#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main(){
  int a;
  string s = "";
  while (cin >> a){
    while (a > 1){
      s = to_string(a % 2) + s;
      a = a >> 1;
    }

    s = to_string(a % 2) + s;
    cout << s << endl;
    // printf("%s", s); Does not handle std::string, only c-style string, use c_str() to get a byte array
    s = "";
  }
}
