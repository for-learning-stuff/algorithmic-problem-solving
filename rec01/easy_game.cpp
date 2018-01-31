#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main(){
  ///
  ifstream f("board.txt");
  ///
  string line;
  vector<string> board;
  while (f >> line){
  // while (cin >> line){
    board.push_back(line);
  }

  // # of x and # of o

  int x = 0;
  int o = 0;
  for (string s: board){
    for (char c: s){
      if (c == 'X') x++;
      if (c == 'O') o++;
    }
  }

  cout << x << o;

  char curr;
  if (x > o) curr = "O"
  else if (x = o) curr = "X"
  else return "illegal";


  // check win
  // check if should've won already

}