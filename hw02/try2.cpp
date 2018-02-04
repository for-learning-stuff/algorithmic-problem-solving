#include <stdio.h>
#include <string.h>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

template <class T, class V>
void printMap(map<T, V> m){
  for(auto it = m.cbegin(); it != m.cend(); ++it)
  {
     cout << it->first << " " << it->second << "\n";
  }
}

int main(){
    int numberOfProblems;
    int freebies;
    scanf("%d%d", &numberOfProblems, &freebies);
    map<char, int> problemValues;
    
    cout << numberOfProblems << " " << freebies;
    char problem;
    int points;
    for (int i=0; i<numberOfProblems; ++i){
      scanf("%*[\n]%c%d", &problem, &points); // Will read the \n from part 1 if not filtered
      // cout << problem << points;
      problemValues.insert(pair<char,int>(problem, points));
    }
    
    printMap(problemValues);
    char startTime[16];
    scanf("%*[\n]%16c%*[\n]", startTime);
    
    startTime[5] = startTime[14];
    cout << startTime;
    cout << endl;
    ////
    ////
    map<string, map<string, string>> dates();
    char time[16];
    scanf("%16c%*[\n]", time);

    cout << time;
}  