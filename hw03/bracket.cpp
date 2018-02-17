#include <unordered_map>
#include <string>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

unordered_map<char, char> pairs =
{ {'{','}'},  {'[',']'}, {'(',')'}};

bool checkvalid(vector<char>& brackets){
    stack<char> open;
    for(char c: brackets){
        // cout << c;
        if (c == '{' or c == '[' or c == '('){
            open.push(c);
        }
        else {
            if (open.size() == 0 || c != pairs[open.top()]){
                return false;
            }
            open.pop();
        }
    }
    if (open.size() == 0)
    return true;
}

int main(){
    stack<char> open;
    vector<char> brackets;
    bool valid = true;
    char next;
    while ((next = getchar()) != EOF){
        brackets.push_back(next);
        if (next == '{' or next == '[' or next == '('){
            open.push(next);
        }
        else {
            if (next != pairs[open.top()]){
                valid = false;
            }
            open.pop();
        }
    }

    bool fixable = false;
    if (!valid){
        brackets[4] = ']';
        cout << checkvalid(brackets);
        for(int i = 0; i < brackets.size() ; ++i){
            brackets[i] = '[';
            if (checkvalid(brackets)){
                fixable = true;
                break; 
            }
            brackets[i] = ']';
            cout << checkvalid(brackets);
            if (checkvalid(brackets)){
                fixable = true;
                break; 
            }
            brackets[i] = '(';
            if (checkvalid(brackets)){
                fixable = true;
                break; 
            }
            brackets[i] = ')';
            if (checkvalid(brackets)){
                fixable = true;
                break; 
            }
        }
    }

    if (valid){
        cout << "valid ";
    } else {
        cout << "invalid ";
        if (fixable){
            cout << "yes";
        } else {
            cout << "no";
        }
    }

}