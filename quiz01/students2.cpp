#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

struct Student{
    string left;
    string right;
};

void moveLeft(unordered_map<string, Student>& students, string& a, string& first){
    ///
    string SL = students[a].left;
    string SR = students[a].right;

    students[a].left = students[first].left; //-1
    students[a].right = first;
    students[first].left = a;

    if (SL != "-1")
        students[SL].right = SR;
    if (SR != "-1")
        students[SR].left = SL;
}

void moveRight(unordered_map<string, Student>& students, string& a, string& last){
    ///
    string SL = students[a].left;
    string SR = students[a].right;

    students[a].left = last; //-1
    students[a].right = students[last].right;
    students[last].right = a;

    if (SL != "-1")
        students[SL].right = SR;
    if (SR != "-1")
        students[SR].left = SL;
}

int main(){
    unordered_map<string, Student> students;
    int numstudents; cin >> numstudents;
    
    Student t; t.left = "-1";
    string name = "1";
    string first = name;
    students.insert(pair<string, Student>(name, t));
    string prev = name;
    ///
    for (int i = 2; i <= numstudents; ++i){
        Student s;
        name = to_string(i); 
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

    for (int i = 0; i < queries; ++i){
        cin >> instruction;
        if(instruction == "mr"){
            cin >> targetA;

            if(targetA == first){
                first = students[targetA].right;
            }
            moveRight(students, targetA, last);
            last = targetA;
            
        }
        else if(instruction == "ml"){
            cin >> targetA;
            if(targetA == last){
                last = students[targetA].left;
            }
            moveLeft(students, targetA, first);
            first = targetA;

        }
        else if(instruction == "l"){
            // cout << instruction;
            cin >> targetA;
            cout << students[targetA].left << endl;
        }
        else if(instruction == "r"){
            // cout << instruction;
            cin >> targetA;
            cout << students[targetA].right << endl;
        };
    }
    // for (auto i: students){
    //     cout << i.first << " " << i.second.left << " " << i.second.right << endl;
    // }
}