// 
#include <bits/stdc++.h>
using namespace std;

int main(){
    // one lower, 2 digits
    string s = "line: a70 and z72 will be replaced, aa24 and a872 will not";
    regex pattern("\\s[a-z][0-9]{2}\\s");
    string fmt = " *** ";
    cout << regex_replace(s, pattern, fmt);
}