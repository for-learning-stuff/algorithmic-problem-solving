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

map<int, int> days = 
{
  {1:31},
  {2:28},
  {3:31},
  {4:30},
  {5:31},
  {6:30},
  {7:31},
  {8:31},
  {9:30},
  {10:31},
  {11:30},
  {12:31},
}

bool expired(string& start, string& time){
  int month = stoi(start[0:1]);
  int date = stoi(start[3:4]);
  // rollover days = days[month] - date
  // exp = date + 7
  return false;
}
/////////

bool isAccepted(const string& s){
  return (s == "Accepted");
}

struct Problem{
  int tries = 0;
  bool accepted = false;
};

double score(const Problem& p, int points, int freebies){
  double multiplier = 1 - (p.tries - freebies) * .1;
  if (p.accepted){
    return max(multiplier, .3) * points;
  }
  else return 0;
}

void add(map<string, map<char, Problem>>& scores, string name, char problem, string status){
  if(!scores.count(name)){
    scores.insert(
      pair<string, map<char, Problem>>(name, map<char, Problem>()));
  }
  if(!scores[name].count(problem)){
    scores[name].insert(pair<char, Problem>(problem, Problem()));
  }
  // scores[name][problem] = the problem object
  if (isAccepted(status)){
    scores[name][problem].accepted = true;
  }
  // cout << status << scores[name][problem].accepted << endl;
  if(!scores[name][problem].accepted){
    scores[name][problem].tries += 1;
  }
}

int main(){
  int numberOfProblems;
  int freebies;
  scanf("%d%d", &numberOfProblems, &freebies);
  map<char, int> problemValues;
  
  cout << numberOfProblems << endl << freebies;
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
  
  ////////
  // while(scanf("%16c", date) != EOF)
  // {
  // }

  // map<string, map<char, Problem>> scores;
  // char date[17];
  // date[16] = '\0';
  // string name;
  // char status[19];
  // while(scanf("%16c", date) != EOF)
  // {
  //   // cout << date << endl; // Date is not null terminated with dare[16], so it prints date and status
  //   cin >> name >> problem;
  //   scanf("%*[ ]%[^\n]%*[\n]", status);
  //   add(scores, name, problem, status);

  // }
  // // cout << "Last line : " << date << endl;


  // // Print scores
  // for(auto student : scores)
  // {
  //    cout << student.first << endl; 
  //    for(auto problem : student.second){
  //      // Prints status
  //      cout << problem.first << " " << problem.second.tries << " " << problem.second.accepted<<  "\n";
  //      // Print scores
  //      cout << score(problem.second, problemValues[problem.first], freebies);
  //    }
  // }

  // cout << endl;
  // cout << strcmp(startTime, firstDate) << endl;
  // char line[100];
  return 0;
}