#include <unordered_map>
#include <string>
#include <iostream>
#include <stack>
using namespace std;


int main(){
    int p = 1000000006;
    stack<char> prefix;
    stack<char> operators;

    char c;
    int i;
    while((c = getchar()) != EOF){
        if (c == '\n') continue;
        
        if (c > 47 && c < 58){
            prefix.push(c);
            continue;
        }
        if ( c == '*' || c == '/'){
            while (operators.size() != 0 && operators.top() != '-' && operators.top() != '+'){
                prefix.push(operators.top());
                operators.pop();
            }
        }
        if ( c == '+' || c == '-'){
            while (operators.size() != 0 && operators.top()){
                prefix.push(operators.top());
                operators.pop();
            }
        }
        operators.push(c);
    }
    while (operators.size() != 0){
        prefix.push(operators.top());
        operators.pop();
    }

    stack<char> postfix;
    while (prefix.size() != 0){
        postfix.push(prefix.top());
        prefix.pop();
    }
    // cout << endl;

    // while (postfix.size() != 0){
    //     cout << postfix.top();
    //     postfix.pop();
    // }

    stack<int> operand;
    int a;
    int b;
    while (postfix.size() != 0){
        c = postfix.top();
        // cout << c;
        postfix.pop();
        if (c > 47 && c < 58){
            operand.push(c-48);
            continue;
        }
        a = operand.top();
        operand.pop();
        b = operand.top();
        operand.pop();
        cout << a << " " << b << endl;
        if ( c == '*'){
            operand.push(((a % p) * (b % p)) % p;
        }
        else if ( c == '/'){
            operand.push((a % p) / (b % p));
        }
        else if ( c == '+'){
            operand.push(((a % p) + (b % p))) % p;
        }
        else if ( c == '-'){
            if (b > a){
                operand.push((a % p) - (b % p));
            }
            operand.push((a % p) - (b % p));
        }
    }
    if (postfix.size == 0){
        cout << operand.top() % p;
    }
}