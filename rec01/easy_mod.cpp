#include <iostream>
using namespace std;
int main() {
  int a,b;
  scanf("%d%d", &a, &b);
  if (((a % 2) * (b % 2)) % 2){
    printf("Odd");
  }
  else{
    printf("Even");
  }
  return 0;
}