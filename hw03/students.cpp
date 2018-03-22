#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

struct Student{
    string left;
    string right;
};

void erase(){};

void swap(unordered_map<string, Student>& students, string& a, string& b){
    Student sA = students[a];
    Student sB = students[b];
    if (sA.left != "-1")
        students[sA.left].right = b;
    if (sA.right != "-1")
        students[sA.right].left = b;
    if (sB.left != "-1")
        students[sB.left].right = a;
    if (sB.right != "-1")
        students[sB.right].left = a;

    ///
    string tempL = students[a].left;
    string tempR = students[a].right;
    students[a].left = students[b].left; 
    students[a].right = students[b].right;
    students[b].left = tempL; 
    students[b].right = tempR;
}

int main(){
    unordered_map<string, Student> students;
    int numstudents; cin >> numstudents;
    Student t; t.left = "-1";
    string name; cin >> name;
    string first = name;
    students.insert(pair<string, Student>(name, t));
    string prev = name;
    ///
    for (int i = 1; i < numstudents; ++i){
        Student s;
        cin >> name; 
        s.left = prev;
        students[prev].right = name;
        prev = name;
        students.insert(pair<string, Student>(name, s));
    }
    students[prev].right = "-1"; // This is the guy at the end;
    string last = prev;
    //

    int queries;
    cin >> queries;
    string instruction;
    string targetA;
    string targetB;

    // for (auto i: students){
    //     cout << i.first << " " << i.second.left << " " << i.second.right << endl;
    // }
    for (int i = 0; i < queries; ++i){
        cin >> instruction;
        if(instruction == "e"){
            cin >> targetA;
            Student s = students[targetA];
            if (s.left != "-1"){
                students[s.left].right = s.right;
            }
            if (s.right != "-1"){
                students[s.right].left = s.left;
            }
            students.erase(targetA);
        }
        else if(instruction == "x"){
            cin >> targetA;
            cin >> targetB;
            swap(students, targetA, targetB);
        }
        else if(instruction == "l"){
            cin >> targetA;
            cout << students[targetA].left << endl;
        }
        else if(instruction == "r"){
            cin >> targetA;
            cout << students[targetA].right << endl;
        };
    }
    // for (auto i: students){
    //     cout << i.first << " " << i.second.left << " " << i.second.right << endl;
    // }
}