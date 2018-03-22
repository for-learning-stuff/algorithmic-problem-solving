#include <stdio.h>
#include <iostream>
#include <set>
using namespace std;
// #include

int main(){
    int l;
    cin >> l;
    char name[l];

    set<int> fib();
    int a = 0;
    int b = 1;
    int next = a + b;
    for(int i = 1; i <= l; ++i){
        // cout << next << endl;
        if (i == next){
            cout << 'O';
            a = b;
            b = next;
            next = a + b;
        }
        else{
            cout << 'o';
        }
    }
    
}