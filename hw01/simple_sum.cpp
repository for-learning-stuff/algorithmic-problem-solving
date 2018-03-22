#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
  int sum = 0;
  int n;
  char whitespace;
  while(!feof(stdin)){ //EOF is only set when tries to read past
    do {
      scanf("%d%c", &n, &whitespace); //If succeed at least once then print sum
      sum += n;
    } while(whitespace != '\n');
    if (!feof(stdin)){
      printf("%d\n", sum);
    }
    sum = 0;
  }
  return 0;
}