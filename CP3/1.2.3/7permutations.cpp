// Generate permutations for first 10 letters

#include <bits/stdc++.h>
using namespace std;

int main(){
    string letters = "ABCDEFGHIJ";

    do {
        cout << letters;
    } while( next_permutation(letters.begin(), letters.end()) ); // returns a bool
    // Takes a Compare object
}


