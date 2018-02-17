#include <set>
#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int number;
    set<int> s;
    vector<int> numbers;
    cin >> number;
    numbers.push_back(number);
    s.insert(number);
    int left = 0;
    int right = 0;
    int longest = 0;
    while (scanf("%d", &number) != EOF) {
        numbers.push_back(number); // add it first
        ++right;                   // increment pointer
        if(s.count(number)){
            if (s.size() > longest){
                longest = s.size();
            }
            while(s.count(number)){
                s.erase(numbers[left]);
                ++left;
            }
            s.insert(number);
        }
        else{
            s.insert(number);
        }
    }
    if (s.size() > longest){
        longest = s.size();
    }
    cout << longest;
}