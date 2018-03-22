#include <iostream>
using namespace std;

int main(){
  int length;
  scanf("%d", &length);
  int max;
  scanf("%d", &max);
  int next;
  for(int i = 1; i < length; ++i){
    scanf("%d", &next);
    if (next > max) max = next;
  }
  printf("%d", max);
  return 0;
}