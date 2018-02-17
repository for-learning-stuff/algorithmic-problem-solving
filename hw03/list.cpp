#include<bits/stdc++.h>
using namespace std;

// void swap(Student& a, Student& b){
//     string tempL = a.left;
//     string tempR = a.right;
//     a.left = b.left; 
//     a.right = b.right
//     b.left = b.left; 
//     b.right = b.right
// }

int main(){
    unordered_map<string, string*> students;
    list<string> line;
    int numstudents; cin >> numstudents;
    string name; cin >> name;
    students.insert(pair<string, string*>(name, &name));
    line.push_back(name);
    ///
    for (int i = 1; i < numstudents; ++i){
        string s;
        cin >> s;
        line.push_back(s);
        students.insert(pair<string, string*>(s, &line.back()));
    }
    int queries;
    cin >> queries;
    char instruction;
    string targetA = "john";
    string targetB;
    for (int i = 0; i < queries; ++i){
        cin >> instruction;
        switch(instruction){
            case('e'):{
                cin >> targetA;
                line.remove(targetA);
                students.erase(targetA);
            };
            case('x'):;
            case('l'):{
                cin >> targetA
                cout << students
                };
            case('r'):;
        }
    }


    for (auto i: students){
        cout << i.first << " " << *(i.second) << endl;
    }
    for (auto i: line){
        cout << i << endl;
    }
    


    for (auto i: students){
        cout << i.first << " " << *(i.second) << endl;
    }
    for (auto i: line){
        cout << i << endl;
    }
}